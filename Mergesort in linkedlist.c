#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void displayList(struct Node *temp)
{
    while(temp != NULL)
    {
        printf("%d", temp->data);

        if(temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf("\n");
}

struct Node *mergeLists(struct Node *a, struct Node *b)
{
    if(a == NULL)
        return b;

    if(b == NULL)
        return a;

    if(a->data <= b->data)
    {
        a->next = mergeLists(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeLists(a, b->next);
        return b;
    }
}

struct Node *mergeSort(struct Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;

    struct Node *slow = head;
    struct Node *fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node *second = slow->next;
    slow->next = NULL;

    struct Node *left = mergeSort(head);
    struct Node *right = mergeSort(second);

    return mergeLists(left, right);
}

int main()
{
    int n, i, data;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertNode(data);
    }

    displayList(head);

    head = mergeSort(head);

    displayList(head);

    return 0;
}
