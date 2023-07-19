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
bool isLoop(Node *&slow, Node *&fast)
{
    
     fast = fast->next;
    if (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    if (slow == nullptr)
    {
        return false;
    }
    else if (fast == nullptr)
    {
        return false;
    }
    else if (fast == slow)
    {
        return true;
    }

   
    return isLoop(slow, fast);
}

Node* findEnd(Node *&head,Node *&fast){
  Node *slow = head;
    
while(slow->next!=fast->next){
    slow=slow->next;
    fast=fast->next;
}
return fast;
}

void loopHandle(Node *&head){
  Node *slow = head;
    Node *fast = head;

    if(isLoop(slow,fast)){
        // slow=head;
      Node *start=findEnd(head,fast);
      cout<<start->data<<endl;
      start->next=nullptr;
    }
    else
    cout<<"No loop";
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    insertLast(head, tail, 5);
    insertLast(head, tail, 9);
    Node *temp = tail;
    insertLast(head, tail, 7);
    insertLast(head, tail, 4);
    insertLast(head, tail, 1);
    insertLast(head, tail, 11);
    insertLast(head, tail, 9);
    insertLast(head, tail, 7);
    insertLast(head, tail, 4);
    insertLast(head, tail, 1);
    insertLast(head, tail, 8);
    insertLast(head, tail, 12);
    tail->next=temp;
//    Display(head);
   loopHandle(head);
   Display(head);
    return 0;
}