#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack 
{
    int value;
    struct stack* next;
} stack;

void push (stack** top, int key)
{
    stack* newNode = (stack*) malloc (sizeof(stack));
    newNode -> value = key;
    newNode -> next = *top;

    *top = newNode;
}

int pop (stack** top)
{
    stack* deletedNode = *top;
    if (deletedNode != NULL)
    {
        *top = (deletedNode -> next);
        int valPopped = deletedNode -> value;

        free (deletedNode);

        return valPopped;
    }
    return -1;
}

int peek (stack* top)
{
    if (top == NULL)        return -1;
    return (top -> value);
}

void printStack (stack* top)
{
    stack* iter = top;
    if (iter == NULL)           printf ("\nError! Stack is empty\n");

    printf ("\t\t\t| %2d |    <-- top\n", iter -> value);
    printf ("\t\t\t|____|\n");
    iter = iter -> next;
    
    while (iter != NULL)
    {
        printf("\t\t\t| %2d |\n", iter -> value);
        printf ("\t\t\t|____|\n");
        iter = iter -> next;
    }

}

int main (void)
{
    printf ("\nWelcome to Stack simulator!\n");

    int choice = -1;
    stack* top = NULL;

    int chc = 1;

    while(chc == 1)
    {  

        printf ("\nPlease enter your choice regarding what operation you want to perform\n");
        printf ("1. Push a value onto the stack\n");
        printf ("2. Pop a value from the top of the stack\n");
        printf ("3. Peek the top value of stack\n");
        printf ("4. Print the stack\n");
        printf ("Your choice :: ");
        scanf ("%d", &choice);

        switch (choice)
        {
            case 1 :
            {
                int key = 0;
                printf ("\nEnter the value you want to push onto the stack top :: ");
                scanf("%d", &key);

                push (&top, key);
                printf ("\nValue = %d pushed onto the top of the stack.", key);
                break;
            }

            case 2 :
            {
                int valPopped = pop (&top);
                (valPopped >= 0) ? (printf ("\nValue = %d popped", valPopped)) : (printf ("\nStack is empty! Error!\n"));
                break;
            }

            case 3 :
            {
                int valTop = peek (top);
                (valTop >= 0) ? (printf ("\nValue of the top = %d", valTop)) : (printf ("\nStack is empty! Error!\n"));
                break;
            }

            case 4:
            {
                printf ("\nThe stack is :: \n");
                printStack (top);
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
