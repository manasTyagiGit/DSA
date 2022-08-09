#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool enqueue (int* queue, int queueSize, int* rear, int key)
{
    if ((*rear) == queueSize - 1)           return false;               // queue is full

    (*rear)++;
    queue[(*rear)] = key;                  

    return true;
}

bool dequeue (int* queue, int queueSize, int* front, int* rear)
{
    if ((*rear) == -1)                      return false;               // queue is empty

    printf ("\nVALUE = %d Dequeued\n", queue[(*front)]);
    for (int i = 0; i <= (*rear); i++)
    {
        queue[i] = queue[i + 1];
    }

    (*rear)--;

    return true;
}

void printQueue (int* queue, int* front, int* rear)
{
    if ((*rear) == -1)
    {
        printf ("\nQUEUE is empty\n");
        return;
    }

    printf ("\t\tfront --->  | %d", queue[(0)]);
    if ((*rear) > 0)
    {
        for (int i = 1; i < (*rear); i++)
        {
            printf (" -> %d", queue[i]);        
        }  

        printf (" -> %d | <---rear\n", queue[(*rear)]);          
    }
}

bool peekRear (int* queue, int* rear)
{
    if((*rear) == -1)           return false;

    printf ("\nQUEUE REAR = %d\n", queue[(*rear)]);
    return true;
}

bool peekFront (int* queue, int* front, int* rear)
{
    if ((*rear) == -1)          return false;

    printf ("\nQUEUE FRONT = %d\n", queue[(*front)]);
    return true;
}

int main (void)
{
    printf ("\nWelcome to QUEUE simulator!\n");

    int queueSize = 0;
    printf ("\nEnter the max queue size :: ");
    scanf ("%d", &queueSize);

    int choice = -1;
    int rear   = -1, front = 0;
    int* queue = (int*) calloc (queueSize, sizeof(int));

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
                printf ("\nEnter the value you want to enqueue to the rear of the queue :: ");
                scanf("%d", &key);

                if (enqueue (queue, queueSize, &rear, key))                 printf ("\nVALUE = %d enqueued\n", key);
                else                                                        printf ("\nFAILURE. QUEUE may be full\n");
                
                break;
            }

            case 2 :
            {
                if (dequeue (queue, queueSize, &front, &rear))              printf ("\nSUCCESS\n");
                else                                                        printf ("\nFAILURE. QUEUE may be empty\n");

                break;
            }

            case 3 :
            {
                if (peekRear (queue, &rear));
                else                            printf ("\nFAILURE. QUEUE may be empty\n");
                break;   
            }

            case 4 :
            {
                if (peekFront (queue, &front, &rear));
                else                             printf ("\nFAILURE. QUEUE may be empty\n");                            
                break;
            }

            case 5 :
            {
                printf ("\nThe queue is :: \n");
                printQueue (queue, &front, &rear);

                break;
            }
            default :
            {
                printf ("\nNot defined. ERROR!\n");
                break;
            }
        }

        printf("\n\n");

        printf ("\nDo you want to continue (1) or exit (0) :: ");
        scanf ("%d", &chc);
    }  

    return EXIT_SUCCESS;    
}