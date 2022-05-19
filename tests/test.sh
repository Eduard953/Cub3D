#!/bin/bash

EXE_PATH=./binaries/Cub3D
if [[ ! -f "$EXE_PATH" ]]; then
    echo "No Binary found"
    exit 1
fi

MEMCHECKER=""
if [[ ! -z `which valgrind` ]]; then
    echo "Found valgrind using that"
    MEMCHECKER="valgrind -q --leak-check=full"
fi


function run_test() {
    mappath="tests/test_maps/$1"
    comment="$2"
    expect_code="1"
    if [[ "$3" ]]; then
        expect_code="$3"
    fi
    echo
    if [[ "$comment" ]]; then
        echo "Testing $comment"
    fi
    echo "Trying Map path: $mappath"
    $MEMCHECKER $EXE_PATH $mappath
    errorcode=$?
    echo
    if [[ "$errorcode" == "$expect_code" ]]; then
        echo "==PASS=="
    else
        echo "==FAIL=="
        exit 1
    fi
}


echo
echo "RUNNING MAP TESTS:"

run_test "doesnotexist.cub" "not existing file"
run_test "wrongend.txt" "wrong file ending"
run_test "wrongformat.cub" "wrong format in the file"
run_test "missingtexture.cub" "missing a texture"
run_test "missingceilcolor.cub" "missing the ceiling color"
run_test "missingfloorcolor.cub" "missing the floor color"
run_test "doortooutside.cub" "a door to the outside of the map"
run_test "notenclosed.cub" "map is not enclosed"
run_test "spawnnotmap.cub" "spawn is not on map"
run_test "spawnaswall.cub" "spawn is a wall tile"
run_test "doublespawn.cub" "2 spawn points"

run_test "test2.cub" "Correct Map" 0
run_test "test1.cub" "Correct Map" 0

