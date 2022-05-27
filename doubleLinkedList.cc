#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct doublyLinkedList
{
    int value;
    struct doublyLinkedList* prev;
    struct doublyLinkedList* next;
} doublyLinkedList;

doublyLinkedList* search (doublyLinkedList* head, int key)      //  O(N)
{ 
    if (head == NULL)                       return NULL;    
    if (head -> value == key)               return head;

    doublyLinkedList* iter = head -> next;

    while (iter != NULL)
    {
        if (iter -> value == key)
        {
            printf ("\nFOUND\n");
            return iter;
        }
        iter = iter -> next;
    }

    printf ("\nNOT FOUND\n");
    return NULL;
}

bool push (doublyLinkedList** head, doublyLinkedList** tail,  int key)      //O(1)
{
    doublyLinkedList* newNode = (doublyLinkedList*) malloc (sizeof (doublyLinkedList));
    if (newNode == NULL)            return false;
    newNode -> value = key;
    newNode -> prev  = NULL;
    newNode -> next  = (*head);

    if ((*head) != NULL)                // not the first entry
    {
        (*head) -> prev = newNode;        
    }

    else                                // first entry, got to take care of the tail pointer
    {       
        (*tail) = newNode;
    }

    (*head) = newNode;
    return true;    
}

bool append (doublyLinkedList** head, doublyLinkedList** tail, int key)     //O(1)
{
    doublyLinkedList* newNode = (doublyLinkedList*) malloc (sizeof (doublyLinkedList));
    if (newNode == NULL)            return false;

    newNode -> value = key;
    newNode -> prev  = (*tail);
    newNode -> next  = NULL;

    if ((*tail) != NULL)                    // not the first entry
    {
        (*tail) -> next = newNode;
    }

    else                                    // first entry, got to take care of the head pointer
    {   
        (*head) = newNode;
    }

    (*tail) = newNode;
    return true;
}

bool insertAfter (doublyLinkedList** head, doublyLinkedList** tail, int key, int keyPrev)   //O(N)
{
    if ((*tail) -> value == keyPrev)        // if we are appending to the tail indirectly
    {
        bool status = append (head, tail, key);
        return status;
    }

    doublyLinkedList* prevNode = search (*head, keyPrev);       
    if (prevNode != NULL)
    {
        doublyLinkedList* newNode = (doublyLinkedList*) malloc (sizeof (doublyLinkedList));
        if (newNode == NULL)            return false;

        doublyLinkedList* nextNode = prevNode -> next;

        newNode -> value = key;
        newNode -> prev  = prevNode;
        newNode -> next  = nextNode;       

        nextNode -> prev = newNode;
        prevNode -> next = newNode;

        return true;
    }
    return false;
}

bool insertBefore (doublyLinkedList** head, doublyLinkedList** tail, int key, int keyNext)
{
    if ((*head) -> value == keyNext)        // if we are pushing a value to the head indirectly
    {
        bool status = push (head, tail, key);
        return status;
    }

    doublyLinkedList* nextNode = search (*head, keyNext);

    if (nextNode != NULL)
    {
        doublyLinkedList* newNode = (doublyLinkedList*) malloc (sizeof(doublyLinkedList));
        if (newNode == NULL)                return false;        

        doublyLinkedList* prevNode = nextNode -> prev;

        newNode -> value = key;
        newNode -> prev = prevNode;
        newNode -> next = nextNode;

        prevNode -> next = newNode;
        nextNode -> prev = newNode;

        return true;
    }
    return false;
}

bool deleteNode (doublyLinkedList** head, doublyLinkedList** tail, int key)
{
    doublyLinkedList* deletedNode = search (*head, key);
    if (deletedNode != NULL)
    {
        doublyLinkedList* nextNode = deletedNode -> next;
        doublyLinkedList* prevNode = deletedNode -> prev;

        if (prevNode == NULL && nextNode == NULL)           // singular linkedlist deletion
        {
            (*head) = NULL;
            (*tail) = NULL;   
        }

        else if (prevNode == NULL)                               // head node deletion
        {
            (*head) = nextNode;
            nextNode -> prev = NULL;
        }

        else if (nextNode == NULL)                              // tail node deletion
        {
            (*tail) = prevNode;
            prevNode -> next = NULL;
        }

        else                                               // any other node
        {
            nextNode -> prev = prevNode;
            prevNode -> next = nextNode;
        }        

        free (deletedNode);

        return true;
    }

    return false;
}
bool printDLL (doublyLinkedList* head)
{
    if (head == NULL)                       return false;

    doublyLinkedList* iter = head -> next;
    printf ("\t\t\t\t\t  %d", head -> value);

    while (iter != NULL)
    {
        printf ("  -> %d", iter -> value);
        iter = iter -> next;
    }
    printf ("\n");
    return true;
}

int main (void)
{
    doublyLinkedList* head = NULL;
    doublyLinkedList* tail = NULL;

    int choice = 0;
    int key = 0, keyPrev = 0, keyNext = 0;
    
    printf ("\nWelcome to the simulator for a Doubly-Linked List\n");
    printf ("------------------------------------------\n");

    redo: 
    printf ("Choose out of the options below :: \n");
    printf ("1. For inserting an element into the Doubly-Linked List\n");
    printf ("2. For deleting an element from the Doubly-Linked List\n");
    printf ("3. For displaying the Doubly-Linked List\n");
    printf ("4. For searching a certain element in the Doubly-Linked List\n");
    printf ("Your choice is : ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {
        case 1 :
        {
            int subChoice = 0;

            printf ("1.  To insert a node at the head, i.e., push a node.\n");
            printf ("2.  To insert an element after any element.\n");
            printf ("3.  To insert an element before any element.\n");
            printf ("4.  To insert an element at the end of the Linked List.\n");

            scanf ("%d", &subChoice);

            switch (subChoice) 
            {
                case 1 :
                {
                    printf ("Enter the value of the node you want to push onto the head :: ");
                    scanf ("%d", &key);

                    if (push (&head, &tail, key))          printf ("\nVALUE = %d pushed onto the head\n", key);
                    else                                   printf ("\nERROR. FAILURE\n");

                    break;
                }
            
                case 2 :
                {   
                    printf ("Enter the value of the node you want input :: ");
                    scanf ("%d", &key);

                    printf ("Enter the value of the node you want to enter it after :: ");
                    scanf ("%d", &keyPrev);

                    if (insertAfter (&head, &tail, key, keyPrev))           printf ("\nVALUE = %d inserted\n", key);
                    else                                                    printf ("\nERROR. FAILURE\n");
                    
                    break;
                }

                case 3 :
                {
                    printf ("Enter the value of the node you want input :: ");
                    scanf ("%d", &key);

                    printf ("Enter the value of the node you want to enter it before :: ");
                    scanf ("%d", &keyNext);

                    if (insertBefore (&head, &tail, key, keyNext))          printf ("\nVALUE = %d inserted\n", key);
                    else                                                    printf ("\nERROR. FAILURE\n");                    
                    
                    break;
                }

                case 4 :
                {
                    printf ("Enter the value of the node you want to append to the tail :: ");
                    scanf ("%d", &key);

                    if (append (&head, &tail, key))          printf ("\nVALUE = %d appended to the tail\n", key);
                    else                                     printf ("\nERROR. FAILURE\n");

                    break; 
                }
            }

            break;
        }

        case 2 :
        {
            int key = 0;
            printf ("Enter the value of the node you want to delete :: ");
            scanf ("%d", &key);

            if (deleteNode (&head, &tail, key))            printf ("\nVALUE = %d deleted\n", key);
            else                                           printf ("\nERROR. FAILURE\n");
            break;
        }

        case 3 :
        {
            printf ("\nThe Doubly - Linked list is :: ");
            if (!printDLL (head))                           printf ("\nLIST IS EMPTY!\n");
            break;
        }

        case 4 :
        {
            int key = 0;
            printf ("Enter the value of the node you want to search :: ");
            scanf ("%d", &key);
            
            doublyLinkedList* node = search (head, key);
            break;
        }
        default :
        {
            printf ("\nWrong choice!\n");
            break;
        }
    }

    printf("\n\n");

    printf ("\nDo you want to continue (1) or exit (0) :: ");
    scanf ("%d", &choice);

    if (choice == 1)
    {
        goto redo;
    }

    return EXIT_SUCCESS;
}