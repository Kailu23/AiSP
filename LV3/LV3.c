#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 1000
typedef struct
{
	int array[MAX_SIZE];
	int top;
} Stack;

typedef struct LL
{
	int data;
	struct LL *next;

} LinkedList;

void initialize(Stack* stack) {
	stack->top = -1;
}

bool isEmpty(Stack* stack) {
	return stack->top == -1;
}

bool isFull(Stack* stack) {
	return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        //printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
    //printf("Pushed %d onto the stack\n", value);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = stack->array[stack->top];
    stack->top--;
    //printf("Popped %d from the stack\n", popped);
    return popped;
}

LinkedList* CreateNode(int data)
{
	LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void InsertAtFirst(LinkedList** head, int data)
{
	LinkedList* newNode = CreateNode(data);
	newNode->next = *head;
	*head = newNode;
}

void deleteFromFirst(LinkedList** head) {
	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}
	LinkedList* temp = *head;
	*head = temp->next;
	free(temp);
}

int CalculateFactoriel(int number) {
	if (number <= 1) {
		return 1;
	}
	else {
		return number * CalculateFactoriel(number - 1);
	}
}

int CalculateCombinations(int n, int m)
{
	if (n == m) return 1;
	else if (n == 1) return 1;
	else if (m == 0) return 1;
	return CalculateCombinations(n - 1, m - 1) + CalculateCombinations(n - 1, m);
}

void CalculateCombinationsWithStack(int a, int b)
{
	Stack* s1 = (Stack*)malloc(sizeof(Stack)); 
	Stack *s2 = (Stack*)malloc(sizeof(Stack));
	int n, m;
	initialize(s1); initialize(s2);
	push(s1, a); push(s2, b);
	int combinations = 0;
	do
	{
		n = pop(s1);
		m = pop(s2);
		if (m == n || m == 0) combinations++;
		else
		{
			push(s1, n - 1);
			push(s2, m - 1);
			push(s1, n - 1);
			push(s2, m);
		}
	} while (!isEmpty(s1));
	printf("%d choose %d is: %d\n", a, b, combinations);
	free(s1);
	free(s2);
}

void CalculateCombinationsWithLL(int a, int b)
{
	LinkedList* l1Head = CreateNode(a);
	LinkedList* l2Head = CreateNode(b);
	int n, m;
	int combinations = 0;
	do
	{
		n = l1Head->data; deleteFromFirst(&l1Head);
		m = l2Head->data; deleteFromFirst(&l2Head);
		if (m == n || m == 0) combinations++;
		else
		{
			InsertAtFirst(&l1Head, n - 1);
			InsertAtFirst(&l2Head, m - 1);
			InsertAtFirst(&l1Head, n - 1);
			InsertAtFirst(&l2Head, m);
		}
	} while (l1Head != NULL);
	printf("%d choose %d is: %d\n", a, b, combinations);
}

int main()
{
	clock_t start, end;
	int n = 24;
	int m = n / 2;
	
	printf("With stack:\n");
	start = clock();
	CalculateCombinationsWithStack(n, m);
	end = clock();
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	printf("With LL:\n");
	start = clock();
	CalculateCombinationsWithLL(n, m);
	end = clock();
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	printf("With recursion:\n");
	start = clock();
	printf("%d choose %d is: %d\n", n, m, CalculateCombinations(n, m));
	end = clock();
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 1;
}