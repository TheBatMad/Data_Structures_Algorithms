
#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val) //Constructor
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val) //Here head taken by reference not by value since the linked list has to be modified
{
    node *n = new node(val); //dynamically created a new node

    //Considering there isnt even a single node in the list
    if (head == NULL)
    {
        head = n; //so now n will become the first node
        return;
    }

    //For traversing the list we create an iterator "temp" so--
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

//To print our Linked List we make a function

void display(node *head) //Call by value since we aren't modifying the linked list here
{
    node *temp = head; //to store the value of head
    while (temp != NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << endl;
}

//Corner case; head deletion
void deleteAtHead(node *&head) //val not reqd cos we'll delete what's at head
{
    node *todelete = head;
    head = head->next;

    delete todelete; //important to do or there'll be memory leak
}

//Deletion; to delete nth node we go to (n-1)th node
void deletion(node *&head, int val)
{
    if (head == NULL)   //Empty link list
    {
        return;
    }

    if(head->next == NULL)      //Only one element in the list
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;   //temp->next is the one we're deleting
    temp->next = temp->next->next; //Changing link on (n-1)th node; first next is the one we are deleting; second is the one we're linking

    delete todelete;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    //display(head);
    //deletion(head,3);
    deleteAtHead(head);
    display(head);
}
