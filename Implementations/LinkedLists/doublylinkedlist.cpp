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
    if ((list -> size) == 0){
        cout << "The list is already empty" << endl;
        return list;
    }

    Node* tbd = list -> head;

    if ((list -> size) == 1){
        list -> head = nullptr;
        list -> tail = nullptr;
    }

    else{
        Node* newHead = tbd -> next;

        newHead -> prev = nullptr;
        tbd -> next = nullptr;

        list -> head = newHead;
    }

    list -> size -= 1;
    delete tbd;    

    return list;
}

DLL* deleteAtEnd (DLL* list)
{
    if ((list -> size) == 0)
    {
        cout << "List is already empty" << endl;
        return list;
    }

    Node* tbd = list -> tail;

    if ((list -> size) == 1)
    {
        list -> head = nullptr;
        list -> tail = nullptr;        
    }

    else{
        Node* newTail = tbd -> prev;
        newTail -> next = nullptr;

        tbd -> prev = nullptr;
        list -> tail = newTail;
    }

    delete tbd;

    list -> size -= 1;

    return list;
}

DLL* deleteByPosition (DLL* list)
{
    int position = 0;
    cout << "Enter position to be deleted :: ";
    cin >> position;

    if (position == 0 || position == 1)             return deleteAtHead(list);
    if (position == (list -> size))                 return deleteAtEnd(list);

    if (position < 0){
        cout << "Negative positions do not exist" << endl;
        return list;
    }

    if (position > (list -> size)){
        cout << "List is too small for that deletion" << endl;
        return list;
    }

    Node* tbd = list -> head;

    while (position != 1)
    {
        tbd = tbd -> next;
        position -= 1;
    }

    Node* pre = tbd -> prev;

    pre -> next = tbd -> next;
    tbd -> next -> prev = pre;

    tbd -> prev = nullptr;
    tbd -> next = nullptr;

    delete tbd;

    list -> size -= 1;

    return list;
}

DLL* reverseDLL(DLL* list)
{
    if ((list -> size) == 0){
        cout << "List is empty" << endl;
        return list;
    }

    if ((list -> size) == 1){
        cout << "List is just 1 element" << endl;
        return list;
    }

    Node* curr = list -> head;
    Node* temp = curr -> prev;

    while (curr){
        temp = curr -> prev;

        curr -> prev = curr -> next;
        curr -> next = temp;

        // we go forward like this as we changed the pointers now
        curr = curr -> prev;
    }

    temp = list -> head;
    list -> head = list -> tail;
    list -> tail = temp;

    return list;
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
        cout << "8. Reverse the DLL\n";

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
            case 8:
                myList = reverseDLL(myList);
                break;
            default:
                cout << "Wrong choice entered, please re-enter\n";
                break;
        }

        printLinkedList (myList);
        
    }
    return EXIT_SUCCESS;
}