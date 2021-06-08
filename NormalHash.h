#define HASH_SLOTS 16

typedef struct node node;
typedef struct list list;
typedef struct hashTable hashTable;

void listInitialize(list*);
int listInsert(list*, int);
int listLookup(list*, int);
void listPrettyPrint(list*, int);
void hashInitialize(hashTable*);
int hashInsert(hashTable*, int);
int hashLookUp(hashTable*, int);
void hashPrettyPrint(hashTable*);

struct node {
	int key;
	struct node* next;
};

struct list {
	node* head;
};

struct hashTable{
	list lists[HASH_SLOTS];
};
