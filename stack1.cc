#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

bool isFull (int stackSize, int* top)
{
    if (*top == stackSize - 1)      return true;
    return false;
}

bool isEmpty (int stackSize, int* top)
{
    if (*top == -1)                 return true;
    return false;
}

bool push (int* stack, int stackSize, int value, int* top)
{
    if (isFull (stackSize, top))                // i.e., top = stackSize - 1
    {
        printf ("\nCannot enter another value. Stack may overflow\n");
        return false;
    }

    (*top)++;
    stack[*top] = value;
    return true;
}

int pop (int* stack, int stackSize, int* top)
{
    if (isEmpty (stackSize, top))                                // i.e., top = -1
    {
        printf ("\nCannot pop from an empty Stack\n");
        return -1;
    }
    
    int valPopped = stack[*top];

    stack[*top] = 0;
    (*top)--;
    
    return valPopped;
}

void peek (int* stack, int* top)
{
    if ((*top) == -1)
    {
        printf ("\nStack is empty\nFAILURE\n");
        return;
    }

    printf ("\nThe stack top is :: %d\n", stack[*top]);    
}

void printStack (int* stack, int* top)
{
    if ((*top) == -1)
    {
        printf ("\nStack is empty\nFAILURE\n");
        return;
    }

    int i = (*top - 1);
    printf ("\t\t\t| %2d |    <-- top\n", stack[*top]);
    printf ("\t\t\t|____|\n");

    while (i >= 0)
    {
        printf("\t\t\t| %2d |\n", stack[i]);
        printf ("\t\t\t|____|\n");
        i--;
    }    
}

int main (void)
{
    int stackSize;
    printf ("\nWelcome to Stack simulator!\n");
    printf ("Please enter your stack maximum size :: ");
    scanf ("%d", &stackSize);

    int* stack = (int*) calloc (stackSize, sizeof(int));
    int top = -1;
    int choice = -1;

    redo :   

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
            int value = 0;
            printf ("\nEnter the value you want to push onto the stack top :: ");
            scanf ("%d", &value);

            if (push (stack, stackSize, value, &top))       printf ("\nVALUE = %d pushed\n", value);
            else                                            printf ("\nFAILURE\n");

            break;
        }

        case 2 :
        {
            int valPopped = pop (stack, stackSize, &top);

            if (valPopped >= 0)     printf ("\nVALUE = %d popped\n", valPopped);
            else                    printf ("\nFAILURE\n");

            break;
        }

        case 3 :
        {
            peek (stack, &top);
            break;
        }
        case 4 :
        {
            printf ("\nThe stack is :: \n\n\n");
            printStack (stack, &top);
            break;            
        }
        default :
        {
            printf ("\nWrong choice\n");
            exit (EXIT_FAILURE);            
        }
    }

    printf ("\nDo you want to continue ? Press (1) to continue :: ");
    scanf ("%d", &choice);

    if (choice == 1)    goto redo;
    return EXIT_SUCCESS;
}
