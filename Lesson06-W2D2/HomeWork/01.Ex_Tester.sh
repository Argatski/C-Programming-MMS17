#!/bin/bash

# Compile the C program (if not already compiled)
gcc -o expression_evaluator 02.Recursion.c

# Function to compare the expected output with the actual output
function compare_output() {
    expected_output=$(cat "$1")
    actual_output=$(./expression_evaluator < "$2")

    if [ "$expected_output" == "$actual_output" ]; then
        echo "Test passed for $2"
    else
        echo "Test failed for $2"
    fi
}

# Loop through all the test files in the "tests" directory
for test_file in tests/*.in; do
    test_num=$(basename "$test_file" .in)

    # Call the function to compare the output for each test
    compare_output "tests/$test_num.out" "$test_file"
done
