#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 10000


typedef struct Node{
	int x;
	struct Node* next;
} Node;

void AppendToList (Node** head, int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->x = value;
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
	}
	else {
		Node* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

void FreeLinkedList(Node* head) {
	Node* current = head;
	Node* nextNode;
	while (current != NULL) {
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
}
void GenerateIntArray(int array[], int size, int lowerBound, int upperBound) {
	for (int i = 0; i < size; i++) {
		array[i] = (rand() % (upperBound - lowerBound) + lowerBound); // Random number between 10 & 99
	}
}

int SequentialSearchRecursive(int array[], int size, int x) {
	if (size == 0) {
		return -1;
	}
	if (array[size - 1] == x) {
		return size - 1;
	}
	return SequentialSearchRecursive(array, size - 1, x);
}

int SequentialSearchLinkedList (Node* head, int target) {
	Node* current = head;
	int index = 0;
	while (current != NULL)
	{
		if (current->x == target) return index; //Element found
		current = current->next;
		index++;
	}
	return -1; // Element not found
}



void TestLV2()
{
	srand((unsigned)time(NULL));

	
	int array[N];
	Node* head = NULL;

	clock_t start = clock(), end;
	GenerateIntArray(array, N, 10, 99);
	end = clock();
	
	printf("Time taken to generate array: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	for (int i = 0; i < N; i++)
	{
		AppendToList(&head, *(array + i));
	}
	end = clock();
	
	printf("Time taken to generate linked list: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

	int targetValue = 5;

	start = clock();
	SequentialSearchRecursive(array, N, targetValue);
	end = clock();
	
	printf("Time taken to search in array: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	SequentialSearchLinkedList(head, targetValue);
	end = clock();
	printf("Time taken to search in linked list: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

	FreeLinkedList(head);
	return;
}
int main()
{
	TestLV2();
	return 1;
}