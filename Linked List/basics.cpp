#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    //constructor to enter data in the node
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node*head)
{
    //Create a temp variable to store the value of head
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int main()
{
    //Statically creating a linked list
    Node n1(1);

    //Storing the address of head as n1
    Node *head = &n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print (head);

    /*
    //For Storing address of n2 in n1
    n1.next = &n2;

    //Dynamically creating a linked list
    Node *n3 = new Node(10);
    Node *head = n3;
    Node *n4 = new Node(30);

    //For connecting n1 and n2 while dynamically creating Linked list=
    n3->next = n4;
    //here we use n3 as pointer to store the address of n4 so "&" isn't required
*/    

}
