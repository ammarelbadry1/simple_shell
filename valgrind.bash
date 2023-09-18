#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh
shell_input="$@"
echo $shell_input | valgrind --leak-check=full --show-leak-kinds=all ./hsh