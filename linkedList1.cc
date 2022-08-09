#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linkedList
{
    int value;
    struct linkedList* next;
}linkedList;

linkedList* search (linkedList* head, int key)
{
    if (head == NULL)               return NULL;

    while (head != NULL)
    {        
        if (head -> value == key)
        {
            printf ("\nFound\n");
            return head;
        }        
        head = head -> next;
    }
    printf ("\nNot found\n");
    return NULL;
}

linkedList* findPredecessor (linkedList* head, int key)
{
    if ((head == NULL) || (head -> next == NULL))           return NULL;
    
    if((head -> next) -> value == key)                      return head;
   
    return findPredecessor (head -> next, key);   
}

void push (linkedList** head, int key)
{
    linkedList* newNode;
    newNode = (linkedList*) malloc (sizeof (linkedList));

    newNode -> value = key;
    newNode -> next = *head;

    *head = newNode;
}

void append (linkedList** head, int key)
{
    linkedList* newNode = (linkedList*) malloc (sizeof (linkedList));
    newNode -> value = key;
    newNode -> next = NULL;

    linkedList* end = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (end -> next != NULL)
    {
        end = end -> next;
    }

    end -> next = newNode;   
}

void insertAfter (linkedList** head, int key, int keyPred)
{
    linkedList* prevNode = search (*head, keyPred);

    if (prevNode != NULL)
    {
        linkedList* newNode = (linkedList*) malloc (sizeof(linkedList));
        newNode -> value = key;
        newNode -> next = prevNode -> next;

        prevNode -> next = newNode;
    }
    else
    {
        printf("\nNot Found\n");
    }  
}

void deleteNode (linkedList** head, int key)
{
    linkedList* node = search (*head, key);
    if (node != NULL)
    {
        linkedList* predNode = findPredecessor (*head, key);
        if (predNode == NULL)
        {
            *head = node -> next;
        }
        else
        {
            predNode -> next = node -> next;
        }

        free (node);
    }   
}

void print (linkedList* head)
{
    if (head == NULL)
    {
        printf ("Linked List is Empty\n");
        return;
    }

    linkedList* iter = head;

    printf ("%d ", iter -> value);
    iter = iter -> next;

    while (iter != NULL)
    {
        printf ("-> %d ", iter -> value);
        iter = iter -> next;
    }
    printf("\n");
}

int main (void)
{
    linkedList* head = NULL; 

    int choice = 0;
    int key = 0, keyPred = 0;
    
    printf ("\nWelcome to the simulator for a Linked List\n");
    printf ("------------------------------------------\n");

    int chc = 1;

    while (chc == 1)
    { 
        printf ("Choose out of the options below :: \n");
        printf ("1. For inserting an element into the Linked List\n");
        printf ("2. For deleting an element from the Linked List\n");
        printf ("3. For displaying the Linked List\n");
        printf ("4. For searching a certain element in the Linked List\n");
        printf ("Your choice is : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 1 :
            {
                int subChoice = 0;

                printf ("To insert a node at the head, i.e., push a node, press 1.\n");
                printf ("To insert an element after any element, press 2.\n");
                printf ("To insert an element at the end of the Linked List, press 3.\n");

                scanf ("%d", &subChoice);

                switch (subChoice)
                {
                    case 1 :                  
                    
                        printf ("Enter the value of the node you want to push onto the head :: ");
                        scanf ("%d", &key);

                        push (&head, key);
                        break;
                    
                    case 2 :

                        printf ("Enter the value of the node you want to input :: ");
                        scanf ("%d", &key);
                        
                        printf ("Enter the value of the node you want to enter it after :: ");
                        scanf ("%d", &keyPred);

                        insertAfter (&head, key, keyPred);
                        break;
                    
                    case 3 :

                        printf ("Enter the value of the node you want to input :: ");
                        scanf ("%d", &key);

                        append (&head, key);
                        break;
                    
                    default :
                        printf ("\nWrong choice\n");
                        break;
                }            
                break;
            }

            case 2 :
            {
                printf ("Enter the value of the node you want to delete :: ");
                scanf ("%d", &key);

                deleteNode (&head, key);
                break;
            }

            case 3 :
            {
                printf("\nThe linked list is :: ");
                print (head);
                printf("\n");
                break;
            }

            case 4 :
            {
                printf ("Enter the value of the node you want to search :: ");
                scanf ("%d", &key);
                
                linkedList* node = search (head, key);
                break;
            }
            default :
            {
                printf ("\nNot defined. ERROR!\n");
            }
        }

        printf("\n\n");

        printf ("\nDo you want to continue (1) or exit (0) :: ");
        scanf ("%d", &chc);
    }

    return EXIT_SUCCESS;
}