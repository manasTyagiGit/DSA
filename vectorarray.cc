#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int capacity;
    int* data;
}vector;

vector* newVector (int cap)
{
    vector* v = (vector*) malloc (sizeof(vector));

    v -> size = 0;                                      // nothing filled initially
    v -> capacity = cap;                                // maximum initial capacity
    v -> data = (int*) calloc (cap, sizeof(int));       // the actual pointer (or array)

    return v;
}

int size (vector* v)
{
    return (v -> size);
}

int capacity (vector* v)
{
    return (v -> capacity);
}

bool is_empty (vector* v)
{
    return (v -> size == 0) ? (true) : (false);
}

void run_init_test (vector* v)
{
    printf ("Size :: %d\tCapacity :: %d\n", size(v), capacity(v));

    if (is_empty (v))       printf ("The vector is empty\n");    
    else                    printf ("The vector is not empty\n");    
}

void resize (vector* v, int new_cap)
{
    v -> capacity = new_cap;        
    v -> data = (int*) realloc ((v -> data), (v -> capacity) * sizeof(int));
}

void push (vector* v, int key)
{
    if (size(v) < capacity(v))
    {
        *(v -> data + v -> size) = key;
        (v -> size)++;
        return;
    }

    int cur_cap = capacity(v);
    resize (v, (cur_cap * 2));
    push (v, key);  
}

int at (vector* v, int index)
{
    if ((index > size(v) - 1) || (index < 0))   return -1;
    return (*(v -> data + index));
}

void print_vector (vector* v)
{
    int iter = size(v) - 1;
    for (int i = 0; i < iter; i++)
    {
        printf ("%d, ", *(v -> data + i));
    }

    printf ("%d\n", *(v -> data + iter));
}

int pop (vector* v)
{
    int ret = *(v->data + v->size - 1);
    v -> size = v -> size - 1;

    return ret; 
}

int find (vector* v, int key)
{
    int i = 0, iter = size(v);

    for (i = 0; i < iter; i++)
    {
        if (*(v -> data + i) == key)    return i;
    }
    return -1;
}

void insert (vector* v, int key, int index)
{
    if (index > size(v))
    {
        printf ("\nCannot Skip Places in the vector\n");
        return;
    }

    if (capacity(v) == size(v))         resize (v, 2 * capacity(v));
    int i = size(v);

    v -> size = v -> size + 1;

    for (i = size(v); i > index; i--)
    {
        *(v -> data + i) = *(v -> data + i - 1);
    }

    *(v -> data + index) = key;
}

void prepend (vector* v, int key)
{
    insert (v, key, 0);
}

void deleteV (vector* v, int index)
{
    if (index < 0 || index >= v -> size)
    {
        printf ("\nNot Possible\n");
        return;
    }

    int i = index;
    int iter = size(v) - 2;

    for (i = index; i <= iter; i++)
    {
        *(v -> data + i) = *(v -> data + i + 1);
    }

    v -> size = v -> size - 1;
}

void removeV (vector*v, int key)
{
    int index = find (v, key);

    while (index != -1)
    {
        deleteV (v, index);
        index = find (v, key);
    }
}

int main (void)
{
    vector* v1 = newVector (4);
    //run_init_test (v1);

    int key = 0, index = 0;

    printf ("\nEnter your input values :: ");
    scanf ("%d", &key);

    do
    {
        push (v1, key);
        scanf ("%d", &key);
    } while (key != -1);

    printf ("\nThe vector is :: ");
    print_vector(v1);
    
    /*

    printf ("\nEnter an index to return a key :: ");
    scanf ("%d", &index);

    printf ("\nThis key at :: %d index is :: %d", index, at (v1, index));

    printf ("\nThe popped element is :: %d", pop(v1));

    printf ("\nThe vector is :: ");
    print_vector(v1);

    printf ("\nEnter a value of the key to be found :: ");
    scanf ("%d", &key);

    printf ("\nThe index of the key %d is :: %d", key, find(v1, key));
    
    */

    printf ("Enter the key and index where to put the key :: ");
    scanf ("%d%d", &key, &index);

    insert (v1, key, index);

    //run_init_test (v1);    

    printf ("\nEnter the value for prepend :: ");
    scanf ("%d", &key);

    prepend (v1, key);

    printf ("\nEnter the index of the entry you want to remove :: ");
    scanf ("%d", &index);

    deleteV(v1, index);

    printf ("\nThe vector is :: ");
    print_vector(v1);

    printf ("\nEnter the value you want to remove :: ");
    scanf ("%d", &key);

    removeV (v1, key);

    printf ("\nThe vector is :: ");
    print_vector(v1);

    printf ("\n\n");
    return EXIT_SUCCESS;
}