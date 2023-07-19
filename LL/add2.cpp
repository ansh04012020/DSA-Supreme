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
        cout << list->data;
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
Node *Rev(Node *head)
{
    // tail=head;
    if (head == nullptr)
       return nullptr;
    if (head->next == nullptr)
       return head;
    Node *prev = nullptr;
    Node *curr = head;
    Node *forward = head->next;
    while (forward != nullptr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void Add(Node *head1, Node *head2)
{
    head1 = Rev(head1);
    head2 = Rev(head2);
    Node *result=nullptr;
    Node *resultT=nullptr;
    int carry = 0, val = 0;
    while (head1 != nullptr && head2 != nullptr)
    {
        val = head1->data + head2->data + carry;
        carry = val / 10;
        val = val % 10;

        insertBeg(result, resultT, val);

        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1 != nullptr && head2 == nullptr)
    {
        val = head1->data + carry;
        carry = val / 10;
        val = val % 10;

        insertBeg(result, resultT, val);

        head1 = head1->next;
    }
    while (head1 == nullptr && head2 != nullptr)
    {
        val = head2->data + carry;
        carry = val / 10;
        val = val % 10;
        insertBeg(result, resultT, val);
        head2 = head2->next;
    }

    Display(result);
}

int main()
{
    Node *head1 = nullptr;
    Node *tail1 = nullptr;
    insertLast(head1, tail1, 1);
    insertLast(head1, tail1, 3);
    insertLast(head1, tail1, 4);
    insertLast(head1, tail1, 7);
    insertLast(head1, tail1, 8);
    insertLast(head1, tail1, 9);

    Node *head2 = nullptr;
    Node *tail2 = nullptr;
    insertLast(head2, tail2, 7);
    insertLast(head2, tail2, 8);
    insertLast(head2, tail2, 1);
    insertLast(head2, tail2, 3);

  
    
  

    Add(head1, head2);

    return 0;
}