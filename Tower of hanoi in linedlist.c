#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int disk;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
    char name;
} Stack;

Stack *createStack(char name)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->top = NULL;
    stack->name = name;

    return stack;
}

void push(Stack *s, int disk)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->disk = disk;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    Node *temp;
    int disk;

    if (s->top == NULL)
        return -1;

    temp = s->top;
    disk = temp->disk;

    s->top = temp->next;

    free(temp);

    return disk;
}

void moveDisk(Stack *s, Stack *dest)
{
    int disk;

    disk = pop(s);

    push(dest, disk);

    printf("Move Disk %d from %c to %c\n",
           disk,
           s->name,
           dest->name);
}

void towerOfHanoi(int n,
                  Stack *s,
                  Stack *aux,
                  Stack *dest)
{
    if (n == 1)
    {
        moveDisk(s, dest);
        return;
    }

    towerOfHanoi(n - 1, s, dest, aux);

    moveDisk(s, dest);

    towerOfHanoi(n - 1, aux, s, dest);
}

int main()
{
    int n;
    int i;

    Stack *s;
    Stack *aux;
    Stack *dest;

    printf("Enter Number of Disks: ");
    scanf("%d", &n);

    s = createStack('A');
    aux = createStack('B');
    dest = createStack('C');

    for (i = n; i >= 1; i--)
    {
        push(s, i);
    }

    towerOfHanoi(n, s, aux, dest);

    return 0;
}
