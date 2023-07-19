#include <iostream>
using namespace std;
class Node
{

public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
void Display(Node *list)
{
    while (list != nullptr)
    {
        cout << list->data << " ";
        list = list->next;
    }

    cout << endl;
}
void insertBeg(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
        tail = newNode;

    newNode->next = head;
    head = newNode;
}
void insertLast(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {

        tail->next = newNode;
        tail = newNode;
    }
}
void insertPos(Node *&head, Node *&tail, int posn, int data)
{

    if (posn == 1)
    {
        insertBeg(head, tail, data);
        return;
    }
    Node *newNode = new Node(data);
    Node *temp = head;
    int i = 1;
    while (i < posn - 1)
    {
        temp = temp->next;
        if (temp == nullptr)
        {
            i = 0;
            break;
        }
        i = i + 1;
    }

    if (i == 0)
    {
        insertLast(head, tail, data);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void remDup(Node * &head)
{
    if(head->next==nullptr)
    return;
    Node*temp;
    if(head->data==head->next->data)
    {
        temp=head->next;
        head->next=temp->next;
        temp->next=nullptr;
        delete temp;
    }
    else
    head=head->next;

    remDup(head);
}


int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    insertLast(head, tail, 1);
    insertLast(head, tail, 3);
    insertLast(head, tail, 3);
    insertLast(head, tail, 3);
    insertLast(head, tail, 4);
    insertLast(head, tail, 4);
    insertLast(head, tail, 7);
    insertLast(head, tail, 8);
    insertLast(head, tail, 9);
    insertLast(head, tail, 11);
    insertLast(head, tail, 18);
    insertLast(head, tail, 18);
  
   Display(head);
   Node * temp=head;
   remDup(temp);
   Display(head);
    return 0;
}