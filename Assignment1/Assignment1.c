// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Functions.h"




//===========================================MAIN===================================================================================


static Node* head = NULL;
static Node* last = NULL;
int line = -1;
int index = -1;

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
        "8-Delete from position\n"
        "9-Undo\n"
        "10-Redo\n"
        "11-Copy\n"
        "12-Cut\n"
        "13-Paste\n"
        "14-Insert with replacement\n"
        "15-Cursor placement\n"
        "15-Finish program\n"
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
            
            remove("undo3.txt");
            rename("undo2.txt", "undo3.txt");
            remove("undo2.txt");
            rename("undo1.txt", "undo2.txt");
            SaveWithName("undo1.txt", head);
            remove("redo1.txt");
            remove("redo2.txt");
            remove("redo3.txt");

            head = CaseOne(head);
            break;
        case 2:
            remove("undo3.txt");
            rename("undo2.txt", "undo3.txt");
            remove("undo2.txt");
            rename("undo1.txt", "undo2.txt");
            SaveWithName("undo1.txt", head);
            remove("redo1.txt");
            remove("redo2.txt");
            remove("redo3.txt");

            head = CaseTwo(head);
            break;
        case 3:
            

            CaseThree(head);
            break;
        case 4:
            remove("undo3.txt");
            rename("undo2.txt", "undo3.txt");
            remove("undo2.txt");
            rename("undo1.txt", "undo2.txt");
            SaveWithName("undo1.txt", head);
            remove("redo1.txt");
            remove("redo2.txt");
            remove("redo3.txt");

            head = CaseFour(head);
            break;
        case 5:
            

            CaseFive(head);
            break;
        case 6:
            FreeList(head);
            head = LoadFile();
            break;
        case 7:
            SaveFile(head);
            break;
        
        case 8:
        {
            if (index == -1 || line == -1)
            {
                printf("Your cursor is not put\n");
                break;
            }
            remove("undo3.txt");
            rename("undo2.txt", "undo3.txt");
            remove("undo2.txt");
            rename("undo1.txt", "undo2.txt");
            SaveWithName("undo1.txt", head);
            remove("redo1.txt");
            remove("redo2.txt");
            remove("redo3.txt");

            
            int length;
            
            printf(">Choose length: ");
            if (scanf_s("%d", &length) != 1)
            {
                printf("Wrong input\n");
                break;
            }
            head = DeleteCase(head, line, index, length);
            
            
            break;
        }
        case 9:
        {
              
            FILE* fileCheck = fopen("undo1.txt", "r");
            if (fileCheck != NULL)
            {
                       
                fclose(fileCheck);
                remove("redo3.txt");
                rename("redo2.txt", "redo3.txt");
                remove("redo2.txt");
                rename("redo1.txt", "redo2.txt");
                SaveWithName("redo1.txt", head);

                FreeList(head);
                head = LoadWithName("undo1.txt");

                remove("undo1.txt");
                rename("undo2.txt", "undo1.txt");
                remove("undo2.txt");
                rename("undo3.txt", "undo2.txt");
            }
            else
            {
                printf("File does not exist.\n");
            }
                
            
            break;
        }
        case 10:
        {
            FILE* fileCheck = fopen("redo1.txt", "r");
            if (fileCheck != NULL)
            {

                fclose(fileCheck);


                remove("undo3.txt");
                rename("undo2.txt", "undo3.txt");
                remove("undo2.txt");
                rename("undo1.txt", "undo2.txt");
                SaveWithName("undo1.txt", head);



                FreeList(head);
                head = LoadWithName("redo1.txt");

                remove("redo1.txt");
                rename("redo2.txt", "redo1.txt");
                remove("redo2.txt");
                rename("redo3.txt", "redo2.txt");
            }
            else
            {
                printf("File does not exist.\n");
            }


            break;
        }
        case 11:
        {
            if (index == -1 || line == -1)
            {
                printf("Your cursor is not put\n");
                break;
            }
            remove("undo3.txt");
            rename("undo2.txt", "undo3.txt");
            remove("undo2.txt");
            rename("undo1.txt", "undo2.txt");
            SaveWithName("undo1.txt", head);
            remove("redo1.txt");
            remove("redo2.txt");
            remove("redo3.txt");


            
            int length;
            
            printf(">Choose length: ");
            if (scanf_s("%d", &length) != 1)
            {
                printf("Wrong input\n");
                break;
            }
            Copy(head, line, index, length);

            break;
        }
        case 12:
        {
            if (index == -1 || line == -1)
            {
                printf("Your cursor is not put\n");
                break;
            }
            remove("undo3.txt");
            rename("undo2.txt", "undo3.txt");
            remove("undo2.txt");
            rename("undo1.txt", "undo2.txt");
            SaveWithName("undo1.txt", head);
            remove("redo1.txt");
            remove("redo2.txt");
            remove("redo3.txt");


            
            int length;
           
            printf(">Choose length: ");
            if (scanf_s("%d", &length) != 1)
            {
                printf("Wrong input\n");
                break;
            }

            Copy(head, line, index, length);
            head = DeleteCase(head, line, index, length);
            break;
        }
        case 13:
        {
            if (index == -1 || line == -1)
            {
                printf("Your cursor is not put\n");
                break;
            }
            remove("undo3.txt");
            rename("undo2.txt", "undo3.txt");
            remove("undo2.txt");
            rename("undo1.txt", "undo2.txt");
            SaveWithName("undo1.txt", head);
            remove("redo1.txt");
            remove("redo2.txt");
            remove("redo3.txt");

            
            
            Node* pasteNode = LoadWithName("copy.txt");
            head = PasteInsertion(head, pasteNode, line, index);
            break;
        }
        case 14:
        {
            if (index == -1 || line == -1)
            {
                printf("Your cursor is not put\n");
                break;
            }
            remove("undo3.txt");
            rename("undo2.txt", "undo3.txt");
            remove("undo2.txt");
            rename("undo1.txt", "undo2.txt");
            SaveWithName("undo1.txt", head);
            remove("redo1.txt");
            remove("redo2.txt");
            remove("redo3.txt");

           
            
            head = InsertWithReplasement(head, line, index);
            break;

        }
        case 15:
            printf("Cursor input:\n");
            printf(">Choose line: ");
            if (scanf_s("%d", &line) != 1)
            {
                printf("Wrong input\n");
                break;
            }
            printf(">Choose index: ");
            if (scanf_s("%d", &index) != 1)
            {
                printf("Wrong input\n");
                break;
            }
            break;
        case 16:
            printf("Program is finished");
            return 0;
        default:
            printf(">This command is not valid");
            break;

        }
    }

    return 0;
}

