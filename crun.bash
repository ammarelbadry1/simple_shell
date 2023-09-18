#!/bin/bash
shell_input="$@"
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh && echo $shell_input | ./hsh
