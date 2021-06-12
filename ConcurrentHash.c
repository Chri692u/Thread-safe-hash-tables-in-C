#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "concurrentHash.h"



void listInitialize(list* list){
	list->head = NULL;
	pthread_mutex_init(&list->lock, NULL);
}

int listInsert(list* list, int key){
	node* new = malloc(sizeof(node));
	if (new == NULL){
		perror("Malloc:");
		return -1;
	} else{
		pthread_mutex_lock(&list->lock);
		new->key = key;
		new->next = list->head;
		list->head = new;
		pthread_mutex_unlock(&list->lock);
		return 0;
	}
}
int listLookup(list* list, int key){
	node* current = list->head;
	pthread_mutex_lock(&list->lock);
	while(current){
		if (current->key == key){
			pthread_mutex_unlock(&list->lock);
			return 0;
		}
		current = current->next;		
	}
	pthread_mutex_unlock(&list->lock);
	return -1;
}

void listPrettyPrint(list* list, int index){
	node* current = list->head;
	printf("List %d: ", index);
	while (current){
		printf("%d ->", current->key);
		current = current->next;
	}
	printf("NULL");
	
}
void hashInitialize(hashTable* hash){
	int i;
	for(i = 0; i < HASH_SLOTS; i++){
		listInitialize(&hash->lists[i]);
	}
}

int hashInsert(hashTable* hash, int key){
	int i = key % HASH_SLOTS; /* hash*/
	return listInsert(&hash->lists[i], key);
}

int hashLookUp(hashTable* hash, int key){
	int i = key % HASH_SLOTS; /*hash*/
	return listLookup(&hash->lists[i], key);
}

void hashPrettyPrint(hashTable* hash){
	int i;
	for(i = 0; i < HASH_SLOTS; i++){
		listPrettyPrint(&hash->lists[i], i);
		printf("\n");
	}
}