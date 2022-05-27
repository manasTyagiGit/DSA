#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray (int* arr, int n)
{
    int i = 0;

    printf ("The array is :: ");

    while (i < n - 1)
    {
        printf ("%d, ", *(arr + i));
        i++;
    }

    printf ("%d\n", *(arr + n - 1));
}

void bubbleUp (int* arr, int i)
{
    int indexParentOfI = (i - 1) / 2;

    if (indexParentOfI == -1)    return;
    if (arr[indexParentOfI] > arr[i])
    {
        swap (&arr[indexParentOfI], &arr[i]);
        bubbleUp (arr, indexParentOfI);
    }
}

void createHeap (int* arr, int n)
{
    int i = 0;
    int parentIndex = -1;

    for (i = 0; i < n; i++)
    {                     
        bubbleUp (arr, i);
    }       
}

int main (void)
{
    int n = 0, key = 0;;
    scanf ("%d", &n);
    int* arr = (int*) calloc (n, sizeof (int));
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &key);
        arr[i] = key;
    }

    printArray (arr, n);
    createHeap (arr, n);
    printArray (arr, n);

    return EXIT_SUCCESS;
}