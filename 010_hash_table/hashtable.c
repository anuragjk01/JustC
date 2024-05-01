#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashMap_s {
	void *map;
	unsigned int mapLen;
} hashMap_t;

typedef struct node_s {
	char *key;
	char *value;
	struct node_s *next;
} node_t;

/************* Function Prototypes *******************************************/
int hashFunction(hashMap_t *hm, char *key, unsigned int *hash);
int initHashMap(hashMap_t **hm, size_t itemSize, unsigned int mapLen);
int pushKeyVal(hashMap_t *hm, char *key, char *value);
node_t* getNode(hashMap_t *hm, char *key);
/************* Main Function *************************************************/
void main()
{
	hashMap_t *hm = NULL;
	node_t *node = NULL;
	unsigned int hash = 0;

	if(initHashMap(&hm, sizeof(node_t), 100) < 0){
		printf("Error failed!!\n");
	}

	pushKeyVal(hm, "key", "012");
	pushKeyVal(hm, "anurag", "345");
	pushKeyVal(hm, "hello", "678");
	pushKeyVal(hm, "world", "910");
	pushKeyVal(hm, "good", "111");
	pushKeyVal(hm, "bye", "121");
	pushKeyVal(hm, "value", "141");

	node = getNode(hm, "key");
	printf("Key:%s, value:%s\n", node->key, node->value);
	node = getNode(hm, "bye");
	printf("Key:%s, value:%s\n", node->key, node->value);
	node = getNode(hm, "world");
	printf("Key:%s, value:%s\n", node->key, node->value);
	node = getNode(hm, "bye");
	printf("Key:%s, value:%s\n", node->key, node->value);

}

/************* Function Definitions ******************************************/
int initHashMap(hashMap_t **hm, size_t itemSize, unsigned int mapLen)
{
	hashMap_t *hashmap = NULL;
	
	hashmap = malloc(sizeof(hashMap_t));

	if(!hashmap)
		return -1;

	hashmap->mapLen = mapLen;

	// map should be seen as an array of pointers 
	if( (hashmap->map = calloc(sizeof(void*), mapLen)) == NULL )
	{
		free(hashmap);
		return -1;
	}

	*hm = hashmap;

	return 0;
}

int hashFunction(hashMap_t *hm, char *key, unsigned int *hash)
{
	// Ref: http://www.cse.yorku.ca/~oz/hash.html

	if(!hm)
		return -1;

	*hash = 5381;
	while(*key){
		*hash = ((*hash << 5) + *hash ) + *(key++);
					/*  hash = (hash x 33) + char */
	}
	*hash %= hm->mapLen;

	return 0;
} 

int pushKeyVal(hashMap_t *hm, char *key, char *value)
{
	unsigned int idx = 0;
	node_t *node = NULL;
	node_t **map = NULL;

	if(!hm)
		return -1;

	if( hashFunction(hm, key, &idx) < 0 )
		return -1;

	node = malloc(sizeof(node_t));
	if( NULL == (node->key = malloc(strlen(key))) )
		return -1;
	memcpy(node->key, key, strlen(key));
	if( NULL == (node->value = malloc(strlen(value))) )
		return -1;
	memcpy(node->value, value, strlen(value));

	map = hm->map;
	node->next = map[idx];
	map[idx] = node;

	return 0;
}

node_t* getNode(hashMap_t *hm, char *key)
{
	unsigned int idx = 0;
	node_t **map = NULL;
	node_t *node = NULL;

	if(!hm)
		return NULL;

	if( hashFunction(hm, key, &idx) < 0 )
		return NULL;

	map = hm->map;
	node = map[idx];

	while( node && (0 != strcmp(node->key,key)) )
		node = node->next;

	return node;
}
