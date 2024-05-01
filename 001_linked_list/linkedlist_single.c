#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************* Struct Definitions ********************************************/
typedef struct node_s {
	int data;
	struct node_s *next;
} node_t;

/************* Function Prototypes *******************************************/
int push(node_t **head, int data);
void printList(node_t *head);
int pop(node_t **head, int *data);

/************* Main Function *************************************************/
void main()
{
	node_t *head = NULL;

	push(&head, 5);
	push(&head, 6);
	push(&head, 8);
	push(&head, 9);
	push(&head, 3);
	push(&head, 2);

	printf("Input list: ");
	printList(head);
}

/************* Function Definitions ******************************************/
int push(node_t **head, int data)
{
	// New entries are pushed to head kind of like 
	// a stack implementation (LIFO)
	
	node_t *new = NULL;
	int ret = -1;

	new = malloc(sizeof(node_t));
	if(new)
	{
		new->data = data;

		new->next = *head;
		*head = new;

		ret = 0;
	}

	return ret;
}

int pop(node_t **head, int *data)
{
//	Pop is done from head like in stack (LIFO)

	node_t *tmp = NULL;
	int ret = -1;

	tmp = *head;
	if(*head)
	{
		(*head) = (*head)->next;
		*data = tmp->data;
		tmp->next = NULL;
		free(tmp);
		ret = 0;
	}

	return ret;
}

void printList(node_t *head)
{
	node_t *tmp = NULL;

	for(tmp = head; tmp ; tmp = tmp->next)
		printf("%d%s", tmp->data, tmp->next?"->":"\n");
}
