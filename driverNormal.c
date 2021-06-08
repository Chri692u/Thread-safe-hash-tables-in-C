#include <stdio.h>
#include <stdlib.h>
#include "NormalHash.h"

int main(){
	hashTable table;
	hashTable* tablePtr = &table;
	hashInitialize(tablePtr);

	hashInsert(tablePtr, 10);
	hashInsert(tablePtr, 4);
	hashInsert(tablePtr, 12);

	hashLookUp(tablePtr, 10);
	hashLookUp(tablePtr, 4);
	hashLookUp(tablePtr,12);
	
	hashPrettyPrint(tablePtr);
	return EXIT_SUCCESS;
}