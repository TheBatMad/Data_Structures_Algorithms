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

void insertAtHead(node* &head, int val)
{   
    node* n = new node(val);
    n->next = head;           //next of n now points to the first node i.e. head
    head = n;                 //head moved to n since n became the first
}

//To print our Linked List we make a function

void display(node* head)      //Call by value since we aren't modifying the linked list here
{
    node* temp = head;        //to store the value of head
    while(temp!=NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << endl;
}

//Searching

bool Search(node* head, int key)
{ node* temp = head;
  while(temp!= NULL)
  { 
      if(temp->data == key)
      {
          return true;
      }
      temp=temp->next;
  }
 return false;
}


int main()
{
    node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    display(head);
    cout << search(head,2) <<endl;
}
