#!/bin/bash

PHILO=./philo   # binario da testare

run_test() {
    echo "Test: $@"
    $PHILO "$@"
    echo "Exit code: $?"
    echo "------------------------"
}

# ✅ Validi
run_test 5 800 200 200
run_test 2 60 60 60 7
run_test 1 800 200 200
run_test 200 800 200 200
run_test 5 800 200 200 0   # meals = infinito
run_test 5 2147483647 2147483647 2147483647 2147483647  # INT_MAX

# ❌ Numero argomenti
run_test
run_test 5 200 200
run_test 5 200 200 200 7 9

# ❌ Filosofi
run_test 0 200 200 200
run_test 201 200 200 200

# ❌ Valori negativi
run_test 5 -200 200 200
run_test 5 200 -200 200
run_test 5 200 200 -200
run_test 5 200 200 200 -3

# ❌ Zeri non validi
run_test 5 0 200 200
run_test 5 200 0 200
run_test 5 200 200 0

# ❌ Non numerici
run_test a 200 200 200
run_test 5 hello 200 200
run_test 5 200 test 200
run_test 5 200 200 2a
run_test 5 200 200 200 ciao
run_test +5 200 200 200
run_test 5 +200 200 200
run_test 5 --5 200 200

# ❌ Overflow
run_test 2147483648 200 200 200
run_test -2147483649 200 200 200

