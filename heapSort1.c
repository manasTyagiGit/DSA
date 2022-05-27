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
    int parentOfI = (i - 1) / 2;

    if (parentOfI == -1)    return;
    if (arr[i] > arr[parentOfI])                                    // > for Max Heap, < for Min Heap
    {
        swap (&arr[parentOfI], &arr[i]);
        bubbleUp (arr, parentOfI);
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

void bubbleDown (int* arr, int n, int i)
{
    int maxI    = i;
    int left    = (2 * i) + 1;
    int right   = (2 * i) + 2;

    if (arr[left]  > arr[maxI] && left < n)      maxI = left;       // > for Max Heap, < for Min Heap
    if (arr[right] > arr[maxI] && right < n)     maxI = right;      // > for Max Heap, < for Min Heap

    if (maxI != i)
    {
        swap (&arr[maxI], &arr[i]);
        bubbleDown (arr, n, maxI);
    }    
}

void heapSort (int* arr, int n)
{
    int i = 0;

    for (i = n - 1; i >= 0; i--)
    {
        swap (&arr[0], &arr[i]);                                    // swap values of root (max) and last leaf node
        bubbleDown (arr, i, 0);
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

    heapSort (arr, n);
    printArray (arr, n);

    return EXIT_SUCCESS;
}