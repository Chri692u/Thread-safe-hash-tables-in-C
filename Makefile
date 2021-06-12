all: normal concurrent

normal: driverNormal.c
	gcc driverNormal.c -o normal.out -ansi -pedantic -Wall -Wextra -g normalHash.c
concurrent: driverConcurrent.c
	gcc driverConcurrent.c -o concurrent.out -ansi -pedantic -Wall -Wextra -g -lpthread concurrentHash.c