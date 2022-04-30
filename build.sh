 #!/usr/bin/env bash
 
 cd ./$1
 gcc main.c -Wall -Og --output main.out
 ./main.out