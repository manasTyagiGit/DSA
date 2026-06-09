#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node* next;

    // Constructor for memory
    node(int val) : val(val), next(nullptr) {}
}node;

typedef struct LinkedList
{
    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;
}LinkedList;

void printLinkedList (LinkedList* list)
{
    if (list -> size == 0)
    {
        cout << "List is empty bruhh !! ";
        return;
    }

    node* curr = list -> head;

    while ((curr -> next) != nullptr)
    {
        cout << curr -> val << ", ";
        curr = curr -> next;
    }

    cout << curr -> val << endl;
}

LinkedList* insertAtHead (LinkedList* list)
{
    int value;
    cout << "Enter the value to be inserted :: ";
    cin >> value;

    node* newNode = new node(value);

    newNode -> next = list -> head;
    list -> head = newNode;

    // Empty list
    if ((list -> size) == 0)
    {
        list -> tail = newNode;
    }

    list -> size += 1;
    
    return list;
}

LinkedList* insertAtTail (LinkedList* list)
{
    int value;
    cout << "Enter the value to be inserted :: ";
    cin >> value;

    node* newNode = new node (value);

    // Empty list
    if ((list -> size) == 0)
    {
        list -> head = newNode;
        list -> tail = newNode;
    }
    else
    {
        list -> tail -> next = newNode;
        list -> tail = newNode;
    }

    list -> size += 1;

    return list;
}

LinkedList* insertAtPositionHelper (LinkedList* list, int pos, int value)
{
    node* curr = list -> head;
    node* prev = list -> head;
    int count = 1;

    while (count != pos)
    {
        prev = curr;
        curr = curr -> next;
        count++;
    }

    node * newNode = new node (value);
    newNode -> next = curr;
    prev -> next = newNode;

    list -> size += 1;

    return list;
}

LinkedList* insertAtPosition (LinkedList* list)
{
    int pos;
    cout << "Enter the position to insert :: ";
    cin >> pos;

    // user enters (-infinity, 0]
    if (pos <= 0)
    {
        cout << "Denied, not a good input\n";
        return list;
    }

    // user enters position too big
    if (pos > ((list -> size) + 1))
    {
        cout << "The linked list is way too small for that buddy\n";
        cout << "List's size = "<< list -> size << endl;

        return list;
    }

    // Indirect call to insertion at tail
    if (pos == (list -> size) + 1)
    {
        return insertAtTail(list);
    }

    // Indirect call to insertion at head
    if (pos == 1)
    {
        return insertAtHead(list);
    }

    // Any other place
    int value;
    cout << "Enter the value to be inserted :: ";
    cin >> value;

    return insertAtPositionHelper(list, pos, value);
}

LinkedList* deleteAtHead (LinkedList* list)
{
    if ((list -> size) == 0)
    {
        cout << "List is empty bruhh!" << endl;
        return list;
    }

    node* tbd = list -> head;
    list -> head = list -> head -> next;

    tbd -> next = nullptr;
    delete tbd;
    
    if ((list -> size) == 1)
    {
        list -> tail = nullptr;

        cout << "List has been emptied" << endl;
    }

    list -> size -= 1;

    return list;
}

LinkedList* deleteByPositionHelper (LinkedList* list, int pos)
{
    if (pos == 1)
        return deleteAtHead(list);
    
    int count = 1;
    node* curr = list -> head;
    node* prev = curr;

    while (count != pos)
    {
        prev = curr;
        curr = curr -> next;
        count += 1;
    }

    prev -> next = curr -> next;
    curr -> next = nullptr;

    if (pos == list -> size)
    {
        list -> tail = prev;
    }

    list -> size -= 1;

    delete curr;

    return list;
}

LinkedList* deleteAtEnd (LinkedList* list)
{
    if ((list -> size) == 0)
    {
        cout << "List is empty bruhh\n";
        return list;
    }

    // We only have 1 element, so head = tail, special O(1) case
    if ((list -> size) == 1)
    {
        delete list -> tail;

        list -> head = nullptr;
        list -> tail = nullptr;

        list -> size = 0;
        return list;
    }

    return deleteByPositionHelper(list, list -> size);
}

LinkedList* deleteByPosition (LinkedList* list)
{
    cout << "Please tell us the position to delete :: ";
    int pos;
    cin >> pos;

    if (pos <= 0)
    {
        cout << "Wrong input\n!!!EXITING!!!" << endl;
        return list;
    }

    if (pos == 1)
    {
        return deleteAtHead(list);
    }

    if (pos == list -> size)
    {
        return deleteAtEnd(list);
    }

    return deleteByPositionHelper (list, pos);
}

int main (void)
{
    LinkedList* myList = new LinkedList();
    cout << "****Welcome to MARS****\n";
    while (true)
    {
        int choice = 0;
        cout << "Choose your option\n";
        cout << "1. Insert at the head\n2. Insert at the end\n3. Insert at a position\n";
        cout << "4. Print the current linked List\n";
        cout << "5. Delete from the head\n6. Delete from the end\n7. Delete at a position\n";

        cin >> choice;

        if (choice == -1)
        {
            cout << "Okay Byee!!!\n";
            return EXIT_SUCCESS;
        }

        switch (choice)
        {
            case 1 :
                myList = insertAtHead(myList);
                break;
            case 2:
                myList = insertAtTail(myList);
                break;
            case 3:
                myList = insertAtPosition(myList);
                break;
            case 4:
                printLinkedList(myList);
                break;
            case 5:
                myList = deleteAtHead(myList);
                break;
            case 6:
                myList = deleteAtEnd(myList);
                break;
            case 7:
                myList = deleteByPosition(myList);
                break;
            default:
                cout << "Wrong choice entered, please re-enter\n";
                break;
        }

        printLinkedList (myList);
        
    }
    return EXIT_SUCCESS;
}