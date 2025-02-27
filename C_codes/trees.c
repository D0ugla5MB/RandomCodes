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
    int (*rng)(int min, int max);
} Node;

Node *makeNode(int min, int max)
{
    Node *nodePtr = malloc(sizeof(Node));
    nodePtr->rng = rng;
    nodePtr->data = nodePtr->rng(min, max);
    nodePtr->leftPtr = NULL;
    nodePtr->rightPtr = NULL;
    return nodePtr;
}

Node *linkLeft(Node *parent, Node *child)
{
    if (!parent)
    {
        return NULL;
    }
    if (!child)
    {
        child = makeNode(-9999, 9999);
    }

    parent->leftPtr = child;
    return parent->leftPtr;
}

Node *linkRight(Node *parent, Node *child)
{
    if (!parent)
    {
        return NULL;
    }
    if (!child)
    {
        child = makeNode(-9999, 9999);
    }

    parent->rightPtr = child;
    return parent->rightPtr;
}

Node *goLeft(Node *node)
{
    if (!node)
    {
        return NULL;
    }
    return node->leftPtr;
}

void showNode(struct Node *auxPtr)
{
    printf("\n");
    printf("Node number:\t%d\n",auxPtr->data);
    //printf("Node\n:number: %d\tLeft: %p\tRight: %p\n", auxPtr->data, *auxPtr->leftPtr, *auxPtr->rightPtr);
    printf("--------------------------------------\n");
}

int main() {
    Node *root = makeNode(-9999, 9999);
    Node *currentNode = root;
    int cnt = 5;
    
    // Create chain
    for (int i = 0; i < cnt; i++) {
        currentNode->leftPtr = makeNode(-9999, 9999);
        currentNode = currentNode->leftPtr;
    }
    
    // Display chain
    currentNode = root;
    while (currentNode != NULL) {
        showNode(currentNode);
        currentNode = currentNode->leftPtr;
    }

    // Free chain
    currentNode = root;
    Node *next;
    while (currentNode != NULL) {
        next = currentNode->leftPtr;
        free(currentNode);
        currentNode = next;
    }
    free(next);

    return 0;
}