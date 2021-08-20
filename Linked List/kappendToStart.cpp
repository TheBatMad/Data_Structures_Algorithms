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
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}

//to find length of the LL
int length(node* head)
{
    int l = 0;
    node* temp = head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}

//Append k nodes to start of LL
node* kappend(node* &head, int k)
{
    node* newHead;
    node* newTail;
    node* tail=head;

    int l=length(head);
    k=k%l;  //because k could be greater than l
    int count = 1;
    while(tail->next!=NULL)
    {
        if(count==l-k)
        {
            newTail = tail;
        }
        if(count==l-k+1)
        {
            newHead = tail;
        }
        tail=tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main()
{
    node* head = NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0; i<6; i++)
    {
        insertAtTail(head,arr[i]);
    }
    display(head);
    node* newhead = kappend(head, 3); //newhead is different from newHead
    display(newhead);

    return 0;
}
