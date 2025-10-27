#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct NodeType
{
    uint32_t data;
    struct NodeType *next;
} Node;

Node *linkedlistptr;

Node *CreateNode(uint32_t input)
{
    Node *TempNode = (Node *)malloc(sizeof(Node));
    TempNode->data = input;
    TempNode->next = NULL;

    return TempNode;
}

void AppendNode(uint32_t input, Node *Head)
{
    Node *tempNode = CreateNode(input);

    while (Head->next != NULL)
    {
        Head = Head->next;
    }

    Head->next = tempNode;
}

int main()
{
    // Node test1;
    // Node test2;

    // test2.data = 21;
    // test2.next = NULL;

    // test1.data = 31;
    // test1.next = &test2;

    linkedlistptr = CreateNode(123);

    AppendNode(456, linkedlistptr);
    AppendNode(4564, linkedlistptr);
    AppendNode(42663, linkedlistptr);
    AppendNode(453455, linkedlistptr);
    AppendNode(713, linkedlistptr);
    AppendNode(4941, linkedlistptr);

    // printf("[%d]->", linkedlistptr->data);
    // linkedlistptr = linkedlistptr->next;

    while (linkedlistptr->next != NULL)
    {

        printf("[%d]->", linkedlistptr->data);
        linkedlistptr = linkedlistptr->next;
    }

    printf("[%d]->", linkedlistptr->data);
    printf("None\n");

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