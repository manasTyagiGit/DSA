#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
    int value;
    struct queue* next;
} queue;

bool enqueue (queue** rear, queue** front, int key)
{
    queue* newNode = (queue*) malloc (sizeof (queue));
    newNode -> value = key;
    newNode -> next  = NULL;    

    if ((*rear) == NULL)               // queue is empty
    {
        (*rear)  = newNode;
        (*front) = newNode;
        return true;
    }

    (*rear) -> next = newNode;
    (*rear) = newNode;

    return true;
}

bool dequeue (queue** rear, queue** front)
{
    queue* deletedNode = *front;
    
    if (deletedNode != NULL)
    {
        *front = deletedNode -> next;            

        if (*front == NULL)             // only one node is present
        {              
            *rear = NULL;
        }

        int valDequeued = deletedNode -> value;
        free (deletedNode);
       
        printf ("\nVALUE DEQUEUED = %d\n", valDequeued);
        return true;
    }    
    return false;
}   

void printQueue (queue* rear, queue* front)
{
    if (rear == NULL)
    {
        printf ("\nQUEUE is empty\n");
        return;
    }

    printf ("\t\tfront --->  | %d", front -> value);
    queue* iter = front -> next;

    while (iter != NULL)
    {
        printf (" -> %d", iter -> value);
        iter = iter -> next; 
    }
    printf (" |   <--- rear\n");
}

bool peekRear (queue* rear)
{
    if (rear != NULL)
    {
        printf ("\nREAR ELEMENT = %d\n", rear -> value);
        return true;
    }
    return false;
}

bool peekFront (queue* front)
{
    if (front != NULL)
    {
        printf ("\nFRONT ELEMENT = %d\n", front -> value);
        return true;
    }
    return false;
}

int main (void)
{
    queue* front = NULL;
    queue* rear  = NULL;

    printf ("\nWelcome to QUEUE simulator!\n");   

    int choice = -1;

    int chc = 1;
    while (chc == 1)
    {
        printf ("\nPlease enter your choice regarding what operation you want to perform\n");
        printf ("1. Enqueue a value into the queue rear\n");
        printf ("2. Dequeue a value from the front of the queue\n");
        printf ("3. Print the rear value of the queue\n");
        printf ("4. Print the front value of the queue\n");
        printf ("5. Print the entire queue\n");
        printf ("Your choice :: ");
        scanf ("%d", &choice);

        switch (choice)
        {
            case 1 :
            {
                int key = 0;
                printf ("\nEnter the value of the key you want to enqueue :: ");
                scanf("%d", &key);

                if ((enqueue (&rear, &front, key)))         printf ("\nSUCCESS! Value = %d has been enqueued\n", key);
                else                                        printf ("\nFAILURE\n");

                break;
            }

            case 2 :
            {
                if (dequeue (&rear, &front))               printf ("\nSUCCESS\n");
                else                                       printf ("\nFAILURE. QUEUE might be empty\n");
                break;
            }

            case 3 :
            {
                if (!peekRear (rear))                      printf ("\nFAILURE. QUEUE might be empty\n");
                break;               
            }

            case 4 :
            {
                if (!peekFront (front))                      printf ("\nFAILURE. QUEUE might be empty\n");
                break;
            }

            case 5 :
            {
                printf ("\nThe queue is :: \n");
                printQueue (rear, front);
                break;
            }

            default :
            {
                printf ("\nWRONG CHOICE! ERROR!\n");
                break;
            }
        }
        printf("\n\n");

        printf ("\nDo you want to continue (1) or exit (0) :: ");
        scanf ("%d", &chc);
    }

    return EXIT_SUCCESS;
}