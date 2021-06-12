#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "concurrentHash.h"

#define THREADS 4
#define INSERTS 40

void* insertInTable(void* args);

/*Globals*/
hashTable table;
hashTable* tablePtr = &table;

int main(){
	int i;
	pthread_t tid[THREADS];
	hashInitialize(tablePtr);
	srand(time(0));

	for (i = 0; i < THREADS; i++){
		if(pthread_create(&tid[i], NULL, insertInTable, tablePtr)){
			goto cleanup;
		}
	}

	hashPrettyPrint(tablePtr);

	cleanup:
	pthread_exit(NULL);
	return EXIT_SUCCESS;
}

void* insertInTable(void* args){
	int i;
	hashTable* ptr = args;

	for (i = 0; i < INSERTS/THREADS; i++){
		hashInsert(ptr, rand());
	}
	return 0;
	free(args);
}