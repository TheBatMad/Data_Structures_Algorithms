#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = head;
    }
    //since n->prev=NULL already specified in constructor so no need again
    head = n;
}

void insertAtTail(node *&head, int val)
{

    if (head == NULL) //we write a new function
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

//Deletion


//condition for when we have to delete the first node
void deleteAtHead(node* &head)
{
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion(node *&head, int pos)
{
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    
    node *temp = head;
    int count = 1;

    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;

    //Condition for when we have to delete last node in the linked list
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    insertAtHead(head, 5);
    display(head);
    deletion(head,5);
    display(head);
}
