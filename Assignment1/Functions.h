#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdbool.h>
#include <stddef.h>


typedef struct Node {
    char thisChar;
    struct Node* nextNode;
} Node;

Node* CreateLinkedList(char firstChar);
Node* AddNodeToLast(Node* head, Node* newNode);
void FreeList(Node* head);
Node* CaseOne(Node* head);
Node* CaseTwo(Node* head);
void CaseThree(Node* head);
Node* CaseFour(Node* head);
void CaseFive(Node* head);
void SaveFile(Node* head);
Node* LoadFile();



Node* DeleteCase(Node* head, int line, int index, int deleteNumber);
void Copy(Node* head, int line, int index, int length);
Node* PasteInsertion(Node* head, Node* insertedHead, int line, int index);
Node* InsertWithReplasement(Node* head, int line, int index);
void SaveWithName(char fileName[], Node* head);
Node* LoadWithName(char fileName[]);



#endif

