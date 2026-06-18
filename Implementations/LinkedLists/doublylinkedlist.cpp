#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;

    Node(int val): val(val), next(nullptr), prev(nullptr) {}
}Node;

typedef struct DLL{
    Node* head = nullptr;
    Node* tail = nullptr;

    int size = 0;
}DLL;

void printLinkedList (DLL* list)
{
    Node* curr = list -> head;

    while (curr)
    {
        cout << curr -> val << "\t";
        curr = curr -> next;
    }

    cout << endl;
}

DLL* insertAtHead (DLL* list)
{
    cout << "Enter value of the new node :: ";
    int value = 0;
    cin >> value;

    Node* newNode = new Node(value);
    
    if (list -> size == 0)
    {
        list -> head = newNode;
        list -> tail = newNode;
    }
    else
    {
        newNode -> next = list -> head;
        (list -> head) -> prev = newNode;
        list -> head = newNode;
    }    

    list -> size += 1;

    return list;
}

DLL* insertAtTail (DLL* list)
{
    cout << "Enter value of the new node :: ";
    int value = 0;
    cin >> value;

    Node* newNode = new Node(value);

    if(list -> size == 0)
    {
        list -> head = newNode;
        list -> tail = newNode;
    }

    else
    {
        newNode -> prev = list -> tail;
        (list -> tail) -> next = newNode;
        list -> tail = newNode;
    }

    list -> size += 1;

    return list;
}

DLL* insertAtPosition(DLL* list)
{
    int position = 0;
    cout << "Enter the position you want to enter the value at :: ";
    cin >> position;

    if (position > (list -> size) + 1)
    {
        cout << "Position not available, list too small for that" << endl;
        return list;
    }

    if (position < 0)
    {
        cout << "No such position exists" << endl;
        return list;
    }

    if (position == 0 || position == 1)                 return insertAtHead(list);
    if (position == (list -> size) + 1)                 return insertAtTail(list);

    int value = 0;
    cout << "Enter value you want to enter :: ";
    cin >> value;

    Node* iter = list -> head;
    while (position != 1)
    {
        iter = iter -> next;
        position -= 1;
    }

    Node* newNode = new Node(value);
    newNode -> next = iter;
    newNode -> prev = iter -> prev;
    iter -> prev = newNode;
    newNode -> prev -> next = newNode;

    list -> size += 1;

    return list;
}

DLL* deleteAtHead (DLL* list)
{
    
}

int main(void)
{
    DLL* myList = new DLL();

    cout << "****Welcome to MARS: Doubly Linked List****\n";
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
            // case 6:
            //     myList = deleteAtEnd(myList);
            //     break;
            // case 7:
            //     myList = deleteByPosition(myList);
            //     break;
            default:
                cout << "Wrong choice entered, please re-enter\n";
                break;
        }

        printLinkedList (myList);
        
    }
    return EXIT_SUCCESS;
}