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
/************* Main Function *************************************************/
void main()
{
	hashMap_t *hm = NULL;
	node_t *node = NULL;
	unsigned int hash = 0;

	initHashMap(&hm, sizeof(node_t), 100);

	pushKeyVal(hm, "key", "value");

	if(!hashFunction(hm, "anurag", &hash))
		printf("%u\n", hash);	

	if(!hashFunction(hm, "hello_world", &hash))
		printf("%u\n", hash);	

	if(!hashFunction(hm, "abcd", &hash))
		printf("%u\n", hash);	
}

/************* Function Definitions ******************************************/
int initHashMap(hashMap_t **hm, size_t itemSize, unsigned int mapLen)
{
	hashMap_t *hashmap = NULL;
	
	hashmap = malloc(sizeof(hashMap_t));

	if(!hashmap)
		return -1;

	hashmap->mapLen = mapLen;
	if( (hashmap->map = malloc(itemSize * mapLen)) == NULL )
	{
		free(hashmap);
		return -1;
	}

	*hm = hashmap;

	return 0;
}

int hashFunction(hashMap_t *hm, char *key, unsigned int *hash)
{
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

	if(!hm)
		return -1;

	if( !hashFunction(hm, key, &idx) )
		return -1;

	node = malloc(sizeof(node_t));
	node->key = malloc(strlen(key));
	memcpy(node->key, key, strlen(key));
	node->value = malloc(strlen(value));
	memcpy(node->value, value, strlen(value));
}

