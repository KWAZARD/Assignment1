// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char thisChar;
    struct Node* nextNode;
}Node;

Node* CreateLinkedList(char firstChar)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->thisChar = firstChar;
    head->nextNode = NULL;
    return head;

}
Node* AddNodeToLast(Node* head, Node* newNode)
{
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->nextNode != NULL)
    {
        current = current->nextNode;
    }
    current->nextNode = newNode;
    return head;
}






Node* InsertAtIndex(Node* head, Node* insertedNode, int index)
{
    if (head == NULL)
    {
        printf("Linked list does not exist");
        return;
    }
    Node* current;
    current = head;
    int iteration = 0;
    while (iteration != index && current != NULL)
    {
        current = current->nextNode;
    }
    if (current == NULL && iteration != index)
    {
        printf("Index is to big, there is no previous element");
        return;
    }
    insertedNode->nextNode = current->nextNode;
    current->nextNode = insertedNode;
    printf("Text is inserted");
    return head;
}







Node* CaseOne(Node* head)
{
    while (getchar() != '\n');
    printf(">Append text symbols to the end:\n");
    

    char a;
    
    

    while ((a = getchar()) != '\n' && a != EOF)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->thisChar = a;
        newNode->nextNode = NULL;
        head = AddNodeToLast(head, newNode);
    }
    return head;
}



Node* CaseTwo(Node* head)
{
    while (getchar() != '\n');
    printf(">New line is started\n");
    
    Node* slashnNode = (Node*)malloc(sizeof(Node));
    
    slashnNode->thisChar = '\n';
    slashnNode->nextNode = NULL;

    head = AddNodeToLast(head, slashnNode);
    
    return head;
}

Node* CaseThree(Node* head)
{
    while (getchar() != '\n');
    printf(">New line is started\n");

    Node* slashnNode = (Node*)malloc(sizeof(Node));

    slashnNode->thisChar = '\n';
    slashnNode->nextNode = NULL;

    head = AddNodeToLast(head, slashnNode);

    return head;
}

//===========================================FILE MANIPULATIONS===================================================================================

void SaveFile(Node* head)
{
    printf(">Enter file name: ");
    
    FILE* file;
    char name[260];


    if (scanf_s("%255s", name, (unsigned int)sizeof(name)) != 1) 
    {
        printf("Invalid input.\n");
        return;
    }

    strcat_s(name, sizeof(name), ".txt");

    if (fopen_s(&file, name, "w") == 0)
    {
        Node* current = head;
        while (current != NULL)
        {
            fputc(current->thisChar, file);
            current = current->nextNode;    
        }
        fclose(file);
    }
}



Node* LoadFile()
{
    FILE* file;

    char name[260];
    Node* head = NULL;
    Node* last = NULL;

    if (scanf_s("%255s", name, (unsigned int)sizeof(name)) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    strcat_s(name, sizeof(name), ".txt");
    if (fopen_s(&file, name, "r") != 0)
    {
        printf("Error opening file\n");
        return;
    }
    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        char symbol = (char)ch;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->thisChar = symbol;
        newNode->nextNode = NULL;
        if (head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->nextNode = newNode;
            last = newNode;
        }
    }

    fclose(file);
    return head;
}



//===========================================MAIN===================================================================================
int main()
{

    int user_choise;
    printf("1-Append text symbols to the end\n"
        "2-Start the new line\n" 
        "3-Print the current text to console\n"
        "4-Insert the text by line and symbol index\n"
        "5-Search(please note that the text can be found more than once)\n"
        "6-Use files to load the information\n"
        "7-Use files to save the information\n"
        ">Choose options\n");
    
    Node* head = NULL;
    Node* current;
    while (true)
    {
        printf(">");
        
        if (scanf_s("%d", &user_choise) != 1)
        {
            printf("Please enter right number\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        switch (user_choise)
        {
        case 1:
            
            head = CaseOne(head);
            break;
        case 2:
            head = CaseTwo(head);
            break; 
        case 3:
            printf(">This command is not implemented");
            break;
        case 4:
            printf(">This command is not implemented");
            break; 
        case 5:
            printf(">This command is not implemented");
            break;
        case 6:
            
            head = LoadFile();
            break;
        case 7:
            SaveFile(head);
            
            return 0;
        default:
            printf(">This command is not valid");
            break;
            
        }
    }
    
    return 0;
}

