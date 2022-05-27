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

void createHeap (int* arr, int n)
{
    int i = (n / 2) - 1;
    
    /*
    * We need not worry about the leaf nodes from index = [n / 2] to index = [n - 1]
    * as they are already heaps which have proper labelling, and dominance relations
    * 
    * We only call bubble down on the nodes which have atleast one child
    */

    for (i = (n / 2) - 1; i >= 0; i--)                 
    {
        bubbleDown (arr, n, i);        
    }    
}

void heapSort (int* arr, int n)
{
    int i = 0;

    for (i = n - 1; i >= 0; i--)
    {
        swap (&arr[0], &arr[i]);
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