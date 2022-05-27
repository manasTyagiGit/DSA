#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bst 
{
    int val;
    struct bst* left;
    struct bst* right;
    struct bst* parent;
}bst;

void inorder (bst* root)
{
    if (root)
    {
        inorder (root -> left);
        printf ("\t%d", root -> val);
        inorder (root -> right);
    }
}

void preorder (bst* root)
{
    if (root)
    {
        printf ("\t%d", root -> val);
        preorder (root -> left);        
        preorder (root -> right);        
    }
}

void postorder (bst* root)
{
    if (root)
    {
        postorder (root -> left);        
        postorder (root -> right);
        printf ("\t%d", root -> val);
    }
}

void insert (bst** root, int key, bst* par)
{
    bst* newNode = (bst*) malloc (sizeof (bst));

    if ((*root) == NULL)
    {
        newNode -> val = key;
        newNode -> right = newNode -> left = NULL;
        newNode -> parent = par;

        *root = newNode;
        return;
    }

    if ((*root) -> val > key)       insert (&((*root) -> left), key, *root);
    else                            insert (&((*root) -> right), key, *root);
}

bst* getMin (bst* root)
{
    bst* min = root;
    if (!min)      return NULL;
    while (min -> left != NULL)     min = min -> left;

    return min;
}

bst* getMax (bst* root)
{
    bst* max = root;

    if (!max)      return NULL;
    while (max -> right != NULL)    max = max -> right;

    return max;
}

bst* search (bst* root, int key)
{
    if (root == NULL)               return NULL;
    if (root -> val == key)         return root;

    if (root -> val > key)          return search (root -> left, key);
    else                            return search (root -> right, key);  
}

bst* Successor (bst* root, int key)
{
    bst* node = search (root, key);

    if (!node)                      return NULL;

    if (node -> right)              return getMin (node -> right);
    return NULL;
}

bst* Predecessor (bst* root, int key)
{
    bst* node = search (root, key);

    if (!node)                      return NULL;

    if (node -> left)               return getMax (node -> left);

    return NULL;
}

void deleteNode (bst** root, int key)
{
    bst* delNode = search (*root, key);

    if (!delNode)                   return;

    else
    {
        bst* parentNode = delNode -> parent;

        //CASE - 0 : The node to be deleted is the root node, and it is the only node;
        if (parentNode == NULL && delNode -> left == NULL && delNode -> right == NULL)                  
        {
            (*root) = NULL;
            return;
        }

        //CASE - 0 : The node to be deleted is the root node and it is a left-only tree, e.g. {5, 4, 3, 2, 1}
        else if (parentNode == NULL && delNode -> left != NULL && delNode -> right == NULL)
        {
            (*root) = (*root) -> left;
            return;
        }

        //CASE - 0 : The node to be deleted is the root node and it is a right-only tree, e.g. {1, 2, 3, 4, 5}
        else if (parentNode == NULL && delNode -> left == NULL && delNode -> right != NULL)
        {
            (*root) = (*root) -> right;
            return;
        }

        //CASE - I : The node to be deleted has no children
        else if (delNode -> left == NULL && delNode -> right == NULL)
        {
            if ((parentNode -> left) -> val == delNode -> val)  parentNode -> left = NULL;
            else                                                parentNode -> right = NULL;
            
            free (delNode);
            return;
        }

        //CASE - II : The node to be deleted has only one children
        else if (delNode -> left != NULL && delNode -> right == NULL)
        {
            (delNode -> left) -> parent = delNode -> parent;

            if ((parentNode -> val) < (delNode -> val))         parentNode -> right = delNode -> left;
            else                                                parentNode -> left  = delNode -> left;            

            free (delNode); 
            return;
        }

        else if (delNode -> left == NULL && delNode -> right != NULL)
        {
            (delNode -> right) -> parent = delNode -> parent;

            if ((parentNode -> val) < (delNode -> val))         parentNode -> right = delNode -> right;
            else                                                parentNode -> left  = delNode -> right;            

            free (delNode); 
            return;
        }

        //CASE - III : The node to be deleted has 2 children

        else
        {
            bst* successor = Successor (delNode, delNode -> val);

            int temp = delNode -> val;
            delNode -> val = successor -> val;
            successor -> val = temp;

            deleteNode (&(delNode -> right), key);
            return; 
        }
    }
    
}

int height(bst* node)
{
    if (node == NULL)               return -1;
    else
    {
        int lDepth = height (node -> left);
        int rDepth = height (node -> right);     
       
        if (lDepth > rDepth)        return(lDepth + 1);
        else                        return (rDepth + 1);
    }
}

int main (void)
{
    bst* root = NULL;
    int n = 0, key = 0, i = 0;

    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf ("%d", &key);
        insert (&root, key, NULL);
    }

    printf ("\nIN-ORDER :: ");
    inorder (root);

    printf ("\nPRE-ORDER :: ");
    preorder (root);

    printf ("\nPOST-ORDER :: ");
    postorder (root);

    printf ("\nMIN ELEMENT = %d\n", (getMin (root)) -> val);
    printf ("\nMAX ELEMENT = %d\n", (getMax (root)) -> val);

    printf ("\nEnter a key to search :: ");
    scanf ("%d", &key);

    if (search (root, key))         printf ("\nFOUND !!");
    else                            printf ("\nNOT-FOUND !!");

    printf ("\nEnter a key to delete :: ");
    scanf ("%d", &key);
    
    deleteNode (&root, key);

    printf ("\nIN-ORDER :: ");
    inorder (root);

    printf ("\nEnter a key to find the successor of :: ");
    scanf ("%d", &key);

    bst* succ = Successor (root, key);
    if (succ)   printf ("\nSucessor of %d = %d", key, succ -> val);

    printf ("\nEnter a key to find the predecessor of :: ");
    scanf ("%d", &key);

    bst* pred = Predecessor (root, key);

    if (pred)   printf ("\nPredecessor of %d = %d", key, pred -> val);
    
    int h = height (root);
    printf ("\nHeight :: %d", h + 1);
    
    printf ("\n\n");
    return EXIT_SUCCESS;
}
