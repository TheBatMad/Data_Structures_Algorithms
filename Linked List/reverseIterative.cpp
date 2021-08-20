#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val)           //Constructor
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val)     //Here head taken by reference not by value since the linked list has to be modified
{
    node* n = new node(val);  //dynamically created a new node

    //Considering there isnt even a single node in the list
    if(head == NULL)
    {
        head = n;        //so now n will become the first node
        return;
    }


    //For traversing the list we create an iterator "temp" so--
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

//To print our Linked List we make a function

void display(node* head)  //Call by value since we aren't modifying the linked list here
{
    node* temp = head;  //to store the value of head
    while(temp!=NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//Reversing the linked list by iterative way

node* reverse(node* &head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        
        prevptr=currptr;
        currptr=nextptr;
    }

    return prevptr;  //since prevptr is the new head
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);

    node* newhead= reverse(head);
    display(newhead);

    return 0;
}
#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val)           //Constructor
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val)     //Here head taken by reference not by value since the linked list has to be modified
{
    node* n = new node(val);  //dynamically created a new node

    //Considering there isnt even a single node in the list
    if(head == NULL)
    {
        head = n;        //so now n will become the first node
        return;
    }


    //For traversing the list we create an iterator "temp" so--
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

//To print our Linked List we make a function

void display(node* head)  //Call by value since we aren't modifying the linked list here
{
    node* temp = head;  //to store the value of head
    while(temp!=NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//Reversing the linked list by iterative way

node* reverse(node* &head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        
        prevptr=currptr;
        currptr=nextptr;
    }

    return prevptr;  //since prevptr is the new head
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);

    node* newhead= reverse(head);
    display(newhead);

    return 0;
}
