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
int len(Node *head)
{
    int count = 0;
    while (head != nullptr)
    {
        head = head->next;
        count++;
    }
    return count;
}

Node *findMid(Node *slow, Node *fast)
{
    if (slow == nullptr)
        cout << "LinkList is Empty";
    else if (fast == nullptr)
        return slow;

    fast = fast->next;
    if (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        slow = slow->next;
    }
    return findMid(slow, fast);
}
bool palindrome(Node *head, Node *mid)
{
    if (head == nullptr)
    {
        cout<<"LL is empty";
        return true;
    }
    else if (head->next == nullptr)
    {
        cout<<"LL has 1 Node";
        return true;
    }

    if(head->data!=mid->data)
    return false;
    if(head->data==mid->data)
    return true;

    return palindrome(head->next,mid->next);   
}
Node *Rev(Node*head){
  if(head==nullptr)
  cout<<"No nodes to reverse";
  Node*prev=nullptr;
  Node*curr=head;
  Node*forward=head->next;
 int count=0;
 while(forward!=nullptr){
     forward=curr->next;
     curr->next=prev;
     prev=curr;
     curr=forward;
     count++;
    
 }
return prev; 
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertLast(head, tail, 1);

    insertLast(head, tail, 2);


    // Display(head);

    Node *mid = findMid(head, head);
    Node * join =Rev(mid);
    mid->next=join;
//    
    // Display(head);
    // cout<<head->data;
    cout<<join->data;
    // cout<<palindrome(head,join);

    return 0;
}