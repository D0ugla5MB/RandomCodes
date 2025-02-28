#include <stdio.h>
#include <stdlib.h>

int rng(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

typedef struct Node
{
    int data;
    struct Node *leftPtr;
    struct Node *rightPtr;
    int (*rngPtr)(int min, int max);
} Node;

Node makeNode(int min, int max)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->rngPtr = rng;
    newNode->data = newNode->rngPtr(min, max);
    newNode->leftPtr = NULL;
    newNode->rightPtr = NULL;
    return *newNode;
}

void showNode(const struct Node *auxPtr) // TO AVOID COPYING THE DATA
{
    printf("\n");
    printf("Node: %p\t Data: %d\n",
           auxPtr, auxPtr->data);
    printf("--------------------------------------\n");
}

void addNode(Node *baseNode, Node (*nodeFncPtr)(int, int))
{
    if (baseNode->rngPtr(0, 1) > 0)
    {
        baseNode->leftPtr = malloc(sizeof(Node));
        *(baseNode->leftPtr) = nodeFncPtr(1, 100);
        return;
    }
    baseNode->rightPtr = malloc(sizeof(Node));
    *(baseNode->rightPtr) = nodeFncPtr(1, 100);
    return;
}

void showNodesList(Node *baseNode)
{
    int cnt = 0;
    Node *auxPtr = baseNode;
    while (auxPtr || cnt < 2)
    {
        Node nodes[2];

        showNode(auxPtr);
        if (auxPtr->leftPtr)
        {
            showNode(auxPtr->leftPtr);
            nodes[0] = *(auxPtr->leftPtr);
        }
        if (auxPtr->rightPtr)
        {
            showNode(auxPtr->rightPtr);
            nodes[1] = *(auxPtr->leftPtr);
        }
        if (cnt > 1)
        {
            cnt = 0;
        }
        auxPtr = &nodes[cnt];
        cnt++;
        if (!auxPtr->leftPtr && !auxPtr->rightPtr)
        {
            break;
        }
        
    }

    return;
}

int main()
{
    Node root = makeNode(1, 100);
    addNode(&root, makeNode);

    Node *nodePtr = &root;

    showNodesList(nodePtr);

    return 0;
}