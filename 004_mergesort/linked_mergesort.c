// C code for linked list merged sort
#include <stdio.h>
#include <stdlib.h>

// Link list node 
struct Node 
{
	int data;
	struct Node* next;
};


/* Function to print nodes in a given 
linked list */
void printList(struct Node* node)
{
	while (node != NULL) 
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("\b\b\n");
}

/* Function to insert a node at the 
beginning of the linked list */
void push(struct Node** head_ref, 
		int new_data)
{
	// Allocate node 
	struct Node* new_node = 
		(struct Node*)malloc(sizeof(struct Node));

	// Put in the data 
	new_node->data = new_data;

	// Link the old list of the new node 
	new_node->next = (*head_ref);

	// Move the head to point to the new node 
	(*head_ref) = new_node;
}


void mySplit(struct Node** head, int len)
{
	struct Node* tmp1 = NULL;
	struct Node* tmp2 = NULL;
	struct Node* tmp3 = NULL;
	int i = 0;

	// Till head has only one element
	if(len == 1)
		return;

	// Iterate to mid point
	for(tmp1=*head, i=0;i<(len/2)-1;tmp1=tmp1->next,i++);
	tmp2 = tmp1->next;
	tmp1->next = NULL;
	tmp1 = *head;


	// Resursive split
	mySplit(&tmp1, len/2);
	mySplit(&tmp2, len - (len/2));


	// Sort and merge
	// tmp3 is used for putting the nodes in order
	for(i = 0; i < len; i++)
	{
		if(tmp1 && tmp2)
		{
			if(tmp1->data < tmp2->data)
			{
				if(tmp3)
				{
					tmp3->next = tmp1;
					tmp3 = tmp3->next;
				}
				else
				{
					// As tmp3 is null, this is the first element in this iteration
					tmp3 = tmp1;
					*head = tmp3;
				}
				tmp1 = tmp1->next;
			}
			else
			{
				if(tmp3)
				{
					tmp3->next = tmp2;
					tmp3 = tmp3->next;
				}
				else
				{
					// As tmp3 is null, this is the first element in this iteration
					tmp3 = tmp2;
					*head = tmp3;
				}
				tmp2 = tmp2->next;
			}
		}
		// if tmp1 != NULL and tmp2 == NULL, rest of tmp1 can be taken as such
		else if(tmp1)
		{
			tmp3->next = tmp1;
			break;
		}
		// if tmp2 != NULL and tmp1 == NULL, rest of tmp2 can be taken as such
		else if(tmp2)
		{
			tmp3->next = tmp2;
			break;
		}
	}
}

// Driver code
int main()
{
	// Start with the empty list 
	struct Node* a = NULL;
	struct Node* tmp = NULL;
	int len = 0;

	/* Let us create a unsorted linked lists 
	to test the functions created lists shall 
	be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 5);
	push(&a, 10);
	push(&a, 3);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	for(tmp=a,len=0; tmp; tmp=tmp->next,len++);
	printf("Input Linked List is: \n");
	printList(a);

	// Sort the above created Linked List 
	//MergeSort(&a);
	mySplit(&a, len);

	printf("Sorted Linked List is: \n");
	printList(a);

	getchar();
	return 0;
}

