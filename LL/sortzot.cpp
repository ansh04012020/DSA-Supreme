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

void sort(Node *head)
{
    int zero=0,one=0,two=0;
 Node * temp=head;
    while(temp!=nullptr){
        if(temp->data==0)
        zero++;
        else if(temp->data==1)
        one++;
        else if(temp->data==2)
        two++;

        temp=temp->next;
    }
temp=head;
while(temp!=nullptr){

    while(zero--){
        temp->data=0;    
    temp=temp->next;
    }
    while(one--){
        temp->data=1;    
    temp=temp->next;
    
    }
    while(two--){
        temp->data=2;    
    temp=temp->next;
    }

}
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertLast(head, tail, 0);

    insertLast(head, tail, 1);

    insertLast(head, tail, 1);
    insertLast(head, tail, 2);

    insertLast(head, tail, 1);

    insertLast(head, tail, 1);

    insertLast(head, tail, 2);
    insertLast(head, tail, 0);

    Display(head);
    sort(head);
    Display(head);
    return 0;
}