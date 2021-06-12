#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "NormalHash.h"

#define THREADS 1
#define INSERTS 40
int main(){
	int i;
	hashTable table;
	hashTable* tablePtr = &table;
	hashInitialize(tablePtr);
	srand(time(0));
	
	for (i = 0; i < INSERTS / THREADS; i++){
		hashInsert(tablePtr, rand());
	}
	
	hashPrettyPrint(tablePtr);
	return EXIT_SUCCESS;
}