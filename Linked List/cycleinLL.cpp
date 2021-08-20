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

void makeCycle(node* &head, int pos)        //forms a cycle on the given position
{
    node* temp=head;
    node* startNode;

    int count = 1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startNode = temp;
        }
        temp=temp->next;
        count++;
    }           
    //after exiting the loop temp will be at last node and startNode will signify the start of the cycle
    //So we point the last node(temp->next) to the starting point of cycle i.e startNode    
    temp->next=startNode;
}

//Detection of cycle in linked list 
//Based on Hare & Tortoise OR Flyod's algorithm
bool detectCycle(node* &head)
{
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL)    //to check if cycle isnt present
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}

//Removing cycle

void removeCycle(node* &head)
{
    node* slow = head;
    node* fast = head;

    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);

    fast=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
    slow->next=NULL;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    makeCycle(head,3);
    //display(head);
    cout << detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);

    return 0;
}
 
