#!/bin/bash

GREEN="\x1B[42;37m "
RED="\x1B[41;37m "
BOLD="\x1B[1m "
RESET=" \x1B[0m"

# Config
SET_MISSING=1
SET_VALGRIND=1
SET_CLEAN=1
SET_BSD=1
SET_MATH=0
SET_DEBUG=1
SET_DEBUG_ERROR=1
CC=clang
CFLAGS="-g -Wall -Werror -Wextra -Wnon-literal-null-conversion -Wnull-character -I ./include"

# Runtime vars
FILE_GIVEN=0
TOTAL=0
COUNT=0
PASS=0
COV=0
COV_TOTAL=0
COV_YES=0
C_FILES=""
TEST_FILES=""
MISSING_FILES=""
FOLDER="./"
LIB_FOLDERS="./binaries ./libraries/"

for instr in $@; do
    if [ $instr == "--debug" ]; then
        SET_DEBUG=1
    elif [ $instr == "--no-debug" ]; then
        SET_DEBUG=0
    elif [ $instr == "--debug-error" ]; then
        SET_DEBUG_ERROR=1
    elif [ $instr == "--no-debug-error" ]; then
        SET_DEBUG_ERROR=0
    elif [ $instr == "--no-missing" ]; then
        SET_MISSING=0
    elif [ $instr == "--no-memcheck" ]; then
        SET_VALGRIND=0
    elif [ $instr == "--no-clean" ]; then
        SET_CLEAN=0
    elif [ $instr == "--missing" ]; then
        SET_MISSING=1
    elif [ $instr == "--memcheck" ]; then
        SET_VALGRIND=1
    elif [ $instr == "--clean" ]; then
        SET_CLEAN=1
    elif [ $instr == "--bsd" ];then
        SET_BSD=1
    elif [ $instr == "--no-bsd" ];then
        SET_BSD=0
    elif [ $instr == "--math" ];then
        SET_MATH=1
    elif [ $instr == "--no-math" ];then
        SET_MATH=0
    elif [ $instr == "--fast" ]; then
        SET_MISSING=0
        SET_VALGRIND=0
        SET_CLEAN=1
        SET_DEBUG=0
        SET_BSD=1
        SET_MATH=0
    elif [ $instr == "--full" ]; then
        SET_MISSING=1
        SET_VALGRIND=1
        SET_CLEAN=1
        SET_DEBUG=1
        SET_BSD=1
        SET_MATH=1
        SET_DEBUG_ERROR=0
    else
        if [[ -f $instr && "$instr" == *.c ]]; then
            FILE_GIVEN=1
            if [[ "$instr" != *_test.c ]]; then
                C_FILES="$C_FILES $instr"
            fi
        elif [ -d $instr ]; then
            FOLDERS="$FOLDER $instr"
            instr=${instr%/}
            FOUND_FILES=$(ls $instr/)
            FILE_GIVEN=1
            for file in $FOUND_FILES; do
                if [[ -f $instr/$file && "$instr/$file" == *.c ]]; then
                    if [[ "$instr/$file" != *_test.c ]]; then
                        C_FILES="$C_FILES $instr/$file"
                    fi
                fi
            done
        else
            if [ $instr ]; then
                echo "Invalid Option: $instr"
            fi
            echo "Usage:"
            echo "./test.sh [options] [filenames]"
            echo ""
            echo "Options:"
            echo "--debug           enable debug messages"
            echo "--no-debug        diable debug messages [default]"
            echo "--debug-error     debug messages only on error"
            echo "--no-debug-error  Not display messages on error only"
            echo "--no-missing      disable display missing tests"
            echo "--missing         enable display missing tests [default]"
            echo "--no-clean        disable cleaning"
            echo "--clean           enable cleaning [default]"
            echo "--no-memcheck     disable memory leak checking with valgrind"
            echo "--memcheck        enable memory leak checking with valgrind [default]"
            echo "--bsd             compile with bsd lib [default]"
            echo "--no-bsd          don't compile with bsd lib"
            echo "--math            compile with math lib [default]"
            echo "--no-math         don't compile with math lib"
            echo "--fast            Sane settings for fast test"
            echo "--full            Sane settings for full test"
            echo ""
            echo "Pass specific files you want to test. E.g. ft_split.c"
            echo ""
            echo "Warning: Arguments are processed in the order they are passed in. Be aware of possible overwrites"
            exit 1
        fi
    fi
done

VALGRIND="$(which valgrind)"
TIMEOUT="$(which timeout)"

if [[ ! -z "$TIMEOUT" ]]; then
    TIMEOUT="$TIMEOUT 30"
else
    PERL="$(which perl)"
    if [[ ! -z "$PERL" ]]; then
        function timeout() {
            $PERL -e 'alarm shift; exec @ARGV' "$@";
        }
        TIMEOUT="timeout 30"
    else
        echo -e "${RED}Timeout not found, running without${RESET}"
    fi
fi

# Add BSD flag
if [[ $SET_BSD == 1 && "$OSTYPE" != "darwin"* ]]; then
    CFLAGS="-lbsd $CFLAGS"
fi
# Add MATH flag
if [ $SET_MATH == 1 ]; then
    CFLAGS="-lm $CFLAGS"
fi

if [[ $SET_VALGRIND == 1 && -z $VALGRIND ]]; then
    echo -e "${RED}No Support for valgrind, disabling memcheck${RESET}"
    SET_VALGRIND=0
fi

# Get all C files if not specified as args
if [ -z "$C_FILES" ]; then
    if [ $FILE_GIVEN == 1 ]; then
        echo "No valid Files given (maybe try without '_test')"
        exit 1
    fi
    for cfile in $(find ./source -type f -name "*.c" -print); do
        C_FILES="$C_FILES $cfile"
    done
fi

# Get All Test files for the C Files
for cfile in $C_FILES; do
    COV_TOTAL=$(($COV_TOTAL + 1))
    test_file=${cfile/.c/_test.c}
    test_file=${test_file/.\/source/.\/tests}
    if [ -f $test_file ]; then
        TOTAL=$(($TOTAL + 1))
        TEST_FILES="$TEST_FILES $test_file"
    else
        MISSING_FILES="$MISSING_FILES $cfile"
    fi
done

# Include all built libraries
for folder in $LIB_FOLDERS; do
    ALL_LIBS=$(find $FOLDER/$folder -name "*.a" 2>/dev/null)
    if [ ! -z "$ALL_LIBS" ]; then
        for lib in "$ALL_LIBS"; do
            lib=${lib/$FOLDER\//}
            lib=${lib/$folder\//}
            lib=${lib/lib/}
            lib=${lib/.a/}
            if [ ! -z "$lib" ]; then
                echo -e "${BOLD}Adding lib ${lib}${RESET}"
                CFLAGS="$CFLAGS -L$folder -l$lib"
            fi
        done
    fi
done

# Cleaning
if [ $SET_CLEAN -eq 1 ]; then
    for file in $(find $FOLDER -name "*.c.out*" -or -name "*.c.usr*" -or -name "vgcore.*" -or -name "*.c.out.dYSM*"); do
        rm -rf $file
    done
fi

# Running tests
for testfile in ${TEST_FILES}; do
    COUNT=$((COUNT + 1))
    EXIT_CODE=-1
    OUTPUT=""
    if [ -f "./${testfile/.c/.sh}" ]; then
        echo -e "${BOLD}Executing special test script${RESET}"
        bash ./${testfile/.c/.sh} > ./$testfile.usr 2>&1
        EXIT_CODE=$?
        OUTPUT=$(cat ./$testfile.usr)
    elif [ ! -f "./$testfile.out" ]; then
        if [ -f "./Makefile" ]; then
            $CC $testfile -o $testfile.out $CFLAGS
        else
            echo -e "${BOLD}No Makefile, just compiling all c files into binary${RESET}"
            $CC *.c -o $testfile.out $CFLAGS
        fi
    fi
    if [ -f "./$testfile.out" ]; then
        if [ $SET_VALGRIND == 1 ]; then
            $TIMEOUT valgrind --error-exitcode=1 --leak-check=full -q --show-leak-kinds=all --errors-for-leak-kinds=all ./$testfile.out > ./$testfile.usr 2>&1
            EXIT_CODE=$?
            OUTPUT=$(cat ./$testfile.usr)
        else
            $TIMEOUT ./$testfile.out > ./$testfile.usr 2>&1
            EXIT_CODE=$?
            OUTPUT=$(cat ./$testfile.usr)
        fi
        if [ -f "./$testfile.ref" ]; then
            OUTPUT=$(diff --text "./$testfile.usr" "./$testfile.ref")
            if [ "$OUTPUT" ]; then
                EXIT_CODE=1
            fi
            if [ $SET_DEBUG == 1 ]; then
                if [ -z "$OUTPUT" ]; then
                    OUTPUT="$(echo "Diff OK")"
                    OUTPUT="$OUTPUT\n$(echo "$(cat ./$testfile.usr)")"
                fi
            fi
        fi
    fi
    if [ $EXIT_CODE == 0 ]; then
        PASS=$(($PASS + 1))
        echo -e "${GREEN} PASS ${RESET} ${testfile}"
        if [ $SET_DEBUG_ERROR == 1 ]; then
            OUTPUT=""
        fi
    else
        echo -e "${RED} FAIL ${RESET} ${testfile}"
    fi
    if [ $SET_DEBUG == 1 ]; then
        if [ "$OUTPUT" ]; then
            echo -e "${OUTPUT}"
        fi
    fi
done

# Cleaning
if [ $SET_CLEAN -eq 1 ]; then
    for file in $(find $FOLDER -name "*.c.out*" -or -name "*.c.usr*" -or -name "vgcore.*" -or -name "*.c.out.dYSM*"); do
        rm -rf $file
    done
fi

# Display results
echo -n "╭"
for i in {1..79}; do echo -n "─"; done
echo "╮"
echo -n "│ Results:"
for i in {1..70}; do echo -n " "; done
echo "│"
echo -n "├"
for i in {1..79}; do echo -n "─"; done
echo "┤"
if [ $TOTAL -eq 0 ]; then
    COV="NaN"
else
    COV=$((($TOTAL * 100) / $COV_TOTAL))
fi
echo -n "│"
COV_REPORT="Test Coverage: $COV% ($TOTAL of $COV_TOTAL files)"
echo -n " $COV_REPORT"
COV_REPORT_LEN=${#COV_REPORT}
for i in $(seq 77 -1 $COV_REPORT_LEN); do echo -n " "; done
echo "│"
echo -n "│"
if [ $TOTAL -eq 0 ]; then
    TEST_REPORT=" Passed Tests: NaN% ($PASS of $TOTAL tests)"
else
    TEST_REPORT=" Passed Tests: $((($PASS * 100) / $TOTAL))% ($PASS of $TOTAL tests)"
fi
echo -n " $TEST_REPORT"
TEST_REPORT_LEN=${#TEST_REPORT}
for i in $(seq 77 -1 $TEST_REPORT_LEN); do echo -n " "; done
echo "│"
echo -n "╰"
for i in {1..79}; do echo -n "─"; done
echo "╯"

# Show missing test files
if [ $SET_MISSING == 1 ]; then
    if [ "$MISSING_FILES" ]; then
        echo "Missing Tests: $MISSING_FILES"
    fi
fi

# Exit based on if test passed or not
if [ $PASS == $TOTAL ]; then
    exit 0
else
    exit 1
fi
