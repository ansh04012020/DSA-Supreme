#include <iostream>
using namespace std;
class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
void display(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int len(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }

    return len;
}
void insertBeg(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertLast(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertPos(Node *&head, Node *&tail, int pos, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    if (pos == 1)
    {
        insertBeg(head, tail, data);
        return;
    }
    int length = len(head);
    if (pos >= length)
    {
        insertLast(head, tail, data);
    }
    else
    {
        Node *temp = head;
        while (--pos != 1)
        {
            temp = temp->next;
        }
        Node *curr = temp->next;

        curr->prev = newNode;
        newNode->next = curr;
        newNode->prev = temp;
        temp->next = newNode;
    }
}
void deltPos(Node *&head, Node *&tail, int pos)
{
    Node *temp;

    if (head == nullptr)
    {
    cout<<"List is Empty"<<endl;
    }
    if (pos == 1)
    {
       temp=head;
       head=head->next;
       head->prev=nullptr;

       temp->next=nullptr;

       delete temp;

       return;
       
    }
    int length = len(head);
    if (pos >= length)
    {
        temp=tail;

        tail=tail->prev;
        tail->next=nullptr;


       temp->prev=nullptr;

       delete temp;
      return;
    }
    else
    {
        Node *left = head;
        while (--pos != 1)
        {
            left = left->next;
        }
        Node *curr = left->next;
        Node *right = curr->next;


        left->next=right;
        right->prev=left;


        curr->next=nullptr;
        curr->prev=nullptr;
        delete curr;

         
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    insertBeg(head, tail, 5);
    insertBeg(head, tail, 6);
    insertBeg(head, tail, 57);
    insertLast(head, tail, 53);
    insertLast(head, tail, 23);
    insertPos(head, tail, 61, 3);
    insertPos(head, tail, 5, 43);
    display(head);
    deltPos(head, tail, 1);
    display(head);
    deltPos(head, tail, 11);
    display(head);
    deltPos(head, tail, 11);
    display(head);
    deltPos(head, tail,3);
    display(head);
    deltPos(head, tail,2);
    display(head);
    return 0;
}