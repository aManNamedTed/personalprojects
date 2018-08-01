#include <iostream>
using namespace std;

/* 8.1.18
To remember:
    - Arrays can be used to store linear data of similar types, but have limitations:
        1. Size of arrays is fixed; must know upper bound of elements. Also memory is pre-allocated.
        2. Inserting a new ele in array is expensive, need to create new array.
        3. Deletion is also expensive with arrays unless use special techniques.
    - Pros of linked list
        1. Dynamic size
        2. Ease of insertion/deletion
    - Cons of linked list
        1. Random access not allowed. Need to access elements sequentially.
        2. Extra memory space for a pointer is required with each element of list.
        3. Not cache friendly. Not contiguous memory locations.
*/
struct Node
{
    int data;
    struct Node *next;
};

// O(n) to print bc iterating through linked list and printing each
void printList(struct Node *head)
{
    while(head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

// O(1) to push because pushing to head
void pushAtHead(struct Node **head, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// O(1) to insert after node because node is given to function
void insertAfter(struct Node *prev, int new_data)
{
    if(prev == NULL)
    {
        cout << "Given previous node cannot be NULL" << endl;
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = prev->next;
    prev->next = new_node;
}

// O(n) because iterate through list; could include tail node to reduce to O(1)
void pushAtTail(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }

    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

int main()
{
    struct Node* head   = NULL;
    struct Node* second = NULL;
    struct Node* third  = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second  = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);

    pushAtHead(&head, 0);
    printList(head);

    pushAtTail(&head, 10);
    printList(head);
    pushAtTail(&head, 10);
}
