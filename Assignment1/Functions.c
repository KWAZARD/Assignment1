#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>





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
void FreeList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        Node* nextNode = current->nextNode;
        free(current);
        current = nextNode;
    }
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
        FreeList(insertedHead);
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

void CaseFive(Node* head)
{

    char a;
    while ((a = getchar()) != '\n' && a != EOF) continue;

    printf("Enter text to search: ");
    Node* searchHead = NULL;

    while ((a = getchar()) != '\n' && a != EOF)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL)
        {
            return;
        }
        newNode->thisChar = a;
        newNode->nextNode = NULL;
        searchHead = AddNodeToLast(searchHead, newNode);
    }


    if (searchHead == NULL)
    {
        printf("Search text is empty\n");
        return;
    }


    int countLine = 0;
    int indexInLine = 0;

    Node* current = head;

    bool found = false;

    while (current != NULL)
    {
        Node* checked = current;
        Node* searched = searchHead;
        while (searched != NULL && checked != NULL && checked->thisChar == searched->thisChar)
        {

            searched = searched->nextNode;
            checked = checked->nextNode;

        }


        if (searched == NULL)
        {
            printf("Text is present in this position: %d, %d\n", countLine, indexInLine);
            found = true;
        }

        if (current->thisChar == '\n')
        {
            countLine++;
            indexInLine = -1;
        }

        current = current->nextNode;
        indexInLine++;
    }
    if (!found)
    {
        printf("There is no such text\n");
    }

    FreeList(searchHead);


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

//===========================================ASSIGNMENT2===================================================================================

Node* DeleteCase(Node* head, int line, int index, int deleteNumber)
{
    
    
    int countLine = 0;
    int indexInLine = 0;

    
    
    if (index == 0 && line == 0)
    {
        if (head == NULL)
        {
            printf("There is nothing to delete\n");
            return head;
        }
        Node* freeDeletedNode = NULL;
        while (deleteNumber != 0 && head != NULL)
        {
            freeDeletedNode = head;

            head = head->nextNode;
            free(freeDeletedNode);
            deleteNumber--;
        }
    }
    else
    {
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
        if (current == NULL)
        {
            printf("There is nothing to delete\n");
            return head;
        }
        while (deleteNumber > 0 && previous->nextNode != NULL)
        {
            
            Node* freeDeletedNode = previous->nextNode;
            previous->nextNode = freeDeletedNode->nextNode;
            free(freeDeletedNode);
            deleteNumber--;
        }
        
    }
    
    
    return head;

}

void Copy(Node* head, int line, int index, int length)
{
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
    if (current == NULL)
    {
        printf("there is nothing to copy\n");
        return;
    }
    Node* copyHead = NULL;
    Node* copyTail = NULL;
    Node* newNode = NULL;
    while (length > 0 && current != NULL)
    {
        newNode = (Node*)malloc(sizeof(Node));

        newNode->thisChar = current->thisChar;
        newNode->nextNode = NULL;
        if (copyHead == NULL)
        {
            copyHead = newNode;
            copyTail = newNode;
        }
        else
        {
            copyTail->nextNode = newNode;
            copyTail = newNode;
        }
        current = current->nextNode;
        
        length--;
    }
    SaveWithName("copy.txt", copyHead);
    FreeList(copyHead);
    
}




Node* PasteInsertion(Node* head, Node* insertedHead, int line, int index)
{
    
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
        FreeList(insertedHead);
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

    printf("Text is successfully pasted!\n");
    return head;

}



Node* InsertWithReplasement(Node* head, int line, int index)
{
    char a;

    while ((a = getchar()) != '\n' && a != EOF) continue;


    printf("Write text:\n");
    

    Node* insertedHead = NULL;
    Node* newNode = NULL;
    int counter = 0;

    while ((a = getchar()) != '\n' && a != EOF)
    {
        counter++;
        newNode = (Node*)malloc(sizeof(Node));
        newNode->thisChar = a;
        newNode->nextNode = NULL;
        insertedHead = AddNodeToLast(insertedHead, newNode);
    }
    DeleteCase(head, line, index, counter);

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
        FreeList(insertedHead);
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





void SaveWithName(char fileName[], Node* head)
{
    
    FILE* file;

    if (fopen_s(&file, fileName, "w") == 0)
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
Node* LoadWithName(char fileName[])
{
    FILE* file;

    Node* head = NULL;
    Node* last = NULL;

    if (fopen_s(&file, fileName, "r") != 0)
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