#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>



typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;
} Node;

int found = -1;
Node* root = NULL;

void SearchBinaryTreeRecursive(char targetValue, Node** head)
{
	if (*head == NULL)
	{
		found = -1;
		return;
	}
	if ((*head)->data == targetValue)
	{
		found = 1;
		return;
	}
	found = -1;
	root = *head;
	if ((*head)->data > targetValue) 
		SearchBinaryTreeRecursive(targetValue, &(*head)->left);
	else 
		SearchBinaryTreeRecursive(targetValue, &(*head)->right);
}

void AddNodeToBinaryTree(Node** head, char inputValue)
{
	found = -1;
	root = NULL;

	SearchBinaryTreeRecursive(inputValue, head);
	
	if (found == 1) return;
	else
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = inputValue;
		newNode->left = newNode->right = NULL;
		if (root == NULL) *head = newNode;
		else
		{
			if (inputValue < root->data) 
				root->left = newNode;
			else 
				root->right = newNode;
		}
	}
}

void TraversePreOrder(Node* head)
{
	printf("%-3c", head->data);
	if (head->left != NULL) 
		TraversePreOrder(head->left);
	if (head->right != NULL) 
		TraversePreOrder(head->right);
}

void TraverseInOrder(Node* head)
{
	
	if (head->left != NULL)
		TraverseInOrder(head->left);
	printf("%-3c", head->data);
	if (head->right != NULL)
		TraverseInOrder(head->right);
}

void TraversePostOrder(Node* head)
{
	if (head->left != NULL)
		TraversePostOrder(head->left);
	if (head->right != NULL)
		TraversePostOrder(head->right);
	printf("%-3c", head->data);
}

int main()
{
	Node* head = NULL;
	char myNameAndSurname[] = "marinvalencak";
	for (int i = 0; i < strlen(myNameAndSurname); i++)
	{
		AddNodeToBinaryTree(&head, myNameAndSurname[i]);
	}
	printf("Preorder: ");
	TraversePreOrder(head);
	printf("\n");

	printf("Inorder: ");
	TraverseInOrder(head);
	printf("\n");

	printf("Postorder: ");
	TraversePostOrder(head);
	printf("\n");

	return 1;
}