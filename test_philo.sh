#!/bin/bash

PHILO=./philo

run_test() {
    echo "Test: $*"
    $PHILO "$@"
    echo "Exit code: $?"
    echo "------------------------"
}

# ✅ Casi validi
run_test 5 800 200 200
run_test 2 60 60 60 7

# ❌ Numero argomenti errato
run_test
run_test 5 200 200
run_test 5 200 200 200 7 9

# ❌ Philosopher count fuori range
run_test 0 200 200 200
run_test 201 200 200 200

# ❌ Valori negativi
run_test 5 -200 200 200
run_test 5 200 -200 200
run_test 5 200 200 -200
run_test 5 200 200 200 -3

# ❌ Zero (invalidi tranne meals opzionale)
run_test 5 0 200 200
run_test 5 200 0 200
run_test 5 200 200 0
run_test 5 200 200 200 0

# ❌ Input non numerici
run_test a 200 200 200
run_test 5 hello 200 200
run_test 5 200 test 200
run_test 5 200 200 "2a"
run_test 5 200 200 200 ciao

# ❌ Segni +/-
run_test +5 200 200 200
run_test 5 +200 200 200
run_test 5 -200 200 200

