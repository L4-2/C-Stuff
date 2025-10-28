#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Define the structure for a generic node in the linked list, holds some 32-bit data and pointer to next node
typedef struct NodeType
{
    uint32_t data;
    struct NodeType *next;
} Node;

// Function to create a new node with given data, returns pointer to the new node
Node *CreateNode(uint32_t input)
{
    // dynamically allocate memory for a new node using malloc
    Node *TempNode = (Node *)malloc(sizeof(Node));

    // need to use pointer based member access since TempNode is a pointer
    TempNode->data = input;
    TempNode->next = NULL;

    return TempNode;
}

// TODO: Add error checking for NULL head pointer and allow appending to empty list if true
// Function to append a new node with given data to the end of the linked list, takes head pointer as argument
void AppendNode(uint32_t input, Node *Head)
{
    // Create a new node with the given input data using CreateNode function
    Node *tempNode = CreateNode(input);

    // Traverse to the end of the linked list
    while (Head->next != NULL)
    {
        Head = Head->next;
    }

    // Once at the end, link the new node to the last node
    Head->next = tempNode;
}

// TODO: Fix this function to properly remove a node by index, causes segmentation fault currently
void RemoveNodebyIndex(uint32_t index, Node *Head)
{
    Node *previousNode = Head;

    // iterate to the node requested
    for (uint32_t i = 0; i < index; i++)
    {
        previousNode = Head;
        Head = Head->next;
    }

    // Set the previous node to the current node's next node.
    previousNode->next = Head->next;

    Head->next = NULL;

    free(Head);
}

// Global pointer to the head of the linked list, this acts as the linked list itself
Node *linkedlistptr = NULL;

int main()
{
    // Node test1;
    // Node test2;

    // test2.data = 21;
    // test2.next = NULL;

    // test1.data = 31;
    // test1.next = &test2;

    // linkedlistptr = CreateNode(123);

    // AppendNode(456, linkedlistptr);
    // AppendNode(4564, linkedlistptr);
    // AppendNode(42663, linkedlistptr);
    // AppendNode(453455, linkedlistptr);
    // AppendNode(713, linkedlistptr);
    // AppendNode(4941, linkedlistptr);

    // printf("[%d]->", linkedlistptr->data);
    // linkedlistptr = linkedlistptr->next;

    linkedlistptr = CreateNode(0);

    uint32_t test[] = {1239, 3359, 5939, 592, 39, 148};

    for (uint8_t i = 0; i < (sizeof(test) / sizeof(test[0])); i++)
    {
        AppendNode(test[i], linkedlistptr);
    }

    while (linkedlistptr->next != NULL)
    {

        printf("[%d]->", linkedlistptr->data);
        linkedlistptr = linkedlistptr->next;
    }

    printf("[%d]->", linkedlistptr->data);
    printf("None\n");

    RemoveNodebyIndex(3, linkedlistptr);

    while (linkedlistptr->next != NULL)
    {

        printf("[%d]->", linkedlistptr->data);
        linkedlistptr = linkedlistptr->next;
    }

    // while (linkedlistptr->next != NULL)
    // {
    //     printf("data: %d", linkedlistptr->data);
    // }

    // linkedlistptr = &test1;
    // printf("LinkedListPtr = %d\n", linkedlistptr->data);

    // linkedlistptr = linkedlistptr->next;
    // printf("LinkedListPtr = %d\n", linkedlistptr->data);

    return 0;
}