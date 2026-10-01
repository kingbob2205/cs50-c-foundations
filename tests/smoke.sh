#!/bin/sh
set -eu
test "$(printf 'Bob\n' | ./bin/hello | tail -n 1)" = 'Name: hello, Bob'
printf '3\n' | ./bin/mario_less | grep -q '###'
printf '3\n' | ./bin/mario_more | grep -q '###  ###'
test "$(printf '41\n' | ./bin/cash | tail -n 1)" = 'Change owed in cents: 4'
printf '4111111111111111\n' | ./bin/credit | grep -q VISA
printf 'cat\nzoo\n' | ./bin/scrabble | grep -q 'Player 2 wins!'
printf 'One fish. Two fish.\n' | ./bin/readability | grep -q 'Before Grade 1'
printf 'Abc!\n' | ./bin/caesar 1 | grep -q 'Bcd!'
printf 'Abc!\n' | ./bin/substitution ZYXWVUTSRQPONMLKJIHGFEDCBA | grep -q 'Zyx!'
printf '3\nAlice\nBob\nAlice\n' | ./bin/plurality Alice Bob | grep -q 'Alice$'
echo 'All smoke tests passed.'
