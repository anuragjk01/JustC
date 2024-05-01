// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

typedef enum bool{
	false = 0,
	true
}bool;

void printBinTree(struct node* root, int space);
void insertBST(struct node** root, int value);
int treeHeight(struct node* root);
bool isIdentical(struct node* tree1, struct node* tree2);
int treeSum(struct node* root);

int main() {
  struct node* root = NULL;
  struct node* root2 = NULL;

  insertBST(&root, 7);
  insertBST(&root, 4);
  insertBST(&root, 5);
  insertBST(&root, 8);
  insertBST(&root, 10);
  insertBST(&root, 3);
  insertBST(&root, 0);
  insertBST(&root, 9);

  insertBST(&root2, 7);
  insertBST(&root2, 4);
  insertBST(&root2, 5);
  insertBST(&root2, 8);
  insertBST(&root2, 10);
  insertBST(&root2, 3);
  insertBST(&root2, 0);
  insertBST(&root2, 9);
  insertBST(&root2, 2);

  printf("Tree height: %d\n\n", treeHeight(root));

  printf("Tree sum: %d\n\n", treeSum(root));

  printf("Isidentical: %s\n", isIdentical(root, root2)?"Yes":"No");

  printf("print binary-tree 1\n");
  printBinTree(root, 4);

  printf("print binary-tree 2\n");
  printBinTree(root2, 4);

}

void printBinTree(struct node* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 4;
 
    // Process right child first
    printBinTree(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = 4; i < space; i++)
        printf(" ");
    printf("%d\n",root->item);
 
    // Process left child
    printBinTree(root->left, space);
}

// Insert in an Binary Search Tree
void insertBST(struct node** root, int value)
{
	if(*root == NULL)
	{
		// Tree is empty
		*root = calloc(1,sizeof(struct node));
		(*root)->item = value;
		return;
	}

	if(value <= (*root)->item)
	{
		if((*root)->left == NULL)
		{
			(*root)->left = calloc(1,sizeof(struct node));
			(*root)->left->item = value;
		}
		else
		{
			insertBST(&(*root)->left, value);
		}
	}
	else
	{
		if((*root)->right == NULL)
		{
			(*root)->right = calloc(1,sizeof(struct node));
			(*root)->right->item = value;
		}
		else
		{
			insertBST(&(*root)->right, value);
		}
	}
}

// FInd height of the tree
int treeHeight(struct node* root)
{
	int leftHeight = 0;
	int rightHeight = 0;

	if(root == NULL)
		return 0;

	leftHeight = treeHeight(root->left);	
	rightHeight = treeHeight(root->right);

	return ( (leftHeight > rightHeight) ? leftHeight : rightHeight ) + 1;	
}

// Check if two trees are identical
bool isIdentical(struct node* tree1, struct node* tree2)
{
	bool left = false;
	bool right = false;


	if((tree1 == NULL) || (tree2 == NULL))
		return (tree1 == tree2);

	if(tree1->item == tree2->item)
		return ( isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right) );
	else
		return false;
}

// Sum of all elements in a tree
int treeSum(struct node* root)
{
	if(root == NULL)
		return 0;

	return root->item + treeSum(root->left) + treeSum(root->right);
}

