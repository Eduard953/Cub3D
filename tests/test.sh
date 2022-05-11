EXE_PATH=./binaries/Cub3D
if [[ ! -f "$EXE_PATH" ]]; then
    echo "No Binary found"
    exit 1
fi

all_tests=0
fail_test=0

function run_test() {
    mappath="tests/test_maps/$1"
    comment="$2"
    echo
    if [[ "$comment" ]]; then
        echo "Testing $comment"
    fi
    echo "Trying Map path: $mappath"
    all_test=$(($all_tests + 1))
    $EXE_PATH $mappath
    errorcode=$?
    echo
    if [[ $errorcode != 0 ]]; then
        echo "==PASS=="
    else
        echo "==FAIL=="
        fail_test=$(($fail_test + 1))
    fi
}


echo
echo "RUNNING MAP TESTS:"

run_test "doesnotexist.cub" "not existing file"
run_test "wrongend.txt" "wrong file ending"
run_test "wrongformat.cub" "wrong format in the file"

echo
echo "Ran $all_test tests"
echo "$fail_test tests failed"

