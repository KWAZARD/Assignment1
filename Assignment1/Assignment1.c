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
        return head;
    }
    Node* current = head;
    while (current->nextNode != NULL)
    {
        current = current->nextNode;
    }
    current->nextNode = newNode;
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

void CaseThree(Node* head)
{
    printf(">");
    Node* current = head;
    if (current == NULL)
    {
        printf_s("There is no text to print\n");
        return;
    }
    
    while (current != NULL)
    {
        printf("%c", current->thisChar);
        current = current->nextNode;
    }
    printf("\n");
    
}


Node* CaseFour(Node* head)
{
    int line;
    int index;
    printf(">Choose line: ");
    if (scanf_s("%d", &line) != 1) return head;
    printf(">Choose index: ");
    if (scanf_s("%d", &index) != 1) return head;

    char a;
    while ((a = getchar()) != '\n' && a != EOF) continue;

    printf("Enter text to append: ");
    Node* insertedHead = NULL;

    while ((a = getchar()) != '\n' && a != EOF)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) return head;
        newNode->thisChar = a;
        newNode->nextNode = NULL;
        insertedHead = AddNodeToLast(insertedHead, newNode);
    }


    if (insertedHead == NULL) return head;


    int countLine = 0;
    int indexInLine = 0;

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && !(countLine == line && indexInLine == index))
    {
        if (current->thisChar == '\n')
        {
            countLine++;
            indexInLine = -1;
        }
        previous = current;
        current = current->nextNode;
        indexInLine++;
    }


    if (!(countLine == line && indexInLine == index))
    {
        printf("This line or index does not exist\n");
        Node* currentNow = insertedHead;
        while (currentNow != NULL)
        {
            Node* nextNow = currentNow->nextNode;
            free(currentNow);
            currentNow = nextNow;
        }
        return head;
    }


    Node* insertedLast = insertedHead;

    while (insertedLast->nextNode != NULL)
    {
        insertedLast = insertedLast->nextNode;
    }

    insertedLast->nextNode = current;
    if (previous == NULL)
    {
        head = insertedHead;
    }
    else
    {
        previous->nextNode = insertedHead;
    }

    printf("Text is successfully inserted!\n");
    return head;

}

void CaseFour(Node* head)
{
    
    char a;
    while ((a = getchar()) != '\n' && a != EOF) continue;

    printf("Enter text to search: ");
    Node* searchHead = NULL;

    while ((a = getchar()) != '\n' && a != EOF)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) return head;
        newNode->thisChar = a;
        newNode->nextNode = NULL;
        searchHead = AddNodeToLast(searchHead, newNode);
    }


    if (searchHead == NULL) return head;


    int countLine = 0;
    int indexInLine = 0;

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL)
    {
        if (current == searchHead)
        {
            while (current->nextNode == searchHead->nextNode)
            {
                continue;
            }
        }
        previous = current;
        current = current->nextNode;
        indexInLine++;
    }


    if (!(countLine == 1 && indexInLine == 1))
    {
        printf("This line or index does not exist\n");
        Node* currentNow = searchHead;
        while (currentNow != NULL)
        {
            Node* nextNow = currentNow->nextNode;
            free(currentNow);
            currentNow = nextNow;
        }
        return;
    }


    Node* insertedLast = searchHead;

    while (insertedLast->nextNode != NULL)
    {
        insertedLast = insertedLast->nextNode;
    }

    insertedLast->nextNode = current;
    if (previous == NULL)
    {
        head = searchHead;
    }
    else
    {
        previous->nextNode = searchHead;
    }

    printf("Text is successfully inserted!\n");
    return;

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
        return head;
    }

    strcat_s(name, sizeof(name), ".txt");
    if (fopen_s(&file, name, "r") != 0)
    {
        printf("Error opening file\n");
        return head;
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


static struct Node* head = NULL;
static struct Node* last = NULL;

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
            CaseThree(head);
            break;
        case 4:
            head = CaseFour(head);
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

