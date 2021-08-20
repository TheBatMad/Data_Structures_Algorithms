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

//To print our Linked List we make a functionl; complexity O(n)

void display(node* head)  //Call by value since we aren't modifying the linked list here
{
    node* temp = head;  //to store the value of head
    while(temp!=NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}


//Reversing K nodes; time complexity O(n)
node* reversek(node* &head, int k)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count=0;    //to know till where k nodes are present
    //for reversing first k nodes
    while(currptr!=NULL && count<k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    //now we have to call recursively to reverse the rest of the linked list
    if(nextptr!=NULL){      //base case
        head->next = reversek(nextptr,k);
    }

    return prevptr;
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

    display(head);

    int k=2;
    node* newhead = reversek(head,k);
    display(newhead);

    return 0;
}
