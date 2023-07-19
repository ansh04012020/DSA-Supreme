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
    Node *zero = nullptr, *one = nullptr, *two = nullptr, *temp = head, *curr;
    Node *zerot = nullptr, *onet = nullptr, *twot = nullptr;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            curr = temp;
            temp = temp->next;
            curr->next = nullptr;
            if (zero == nullptr)
            {
                zero = curr;
                zerot = curr;
            }

            zerot->next = curr;
            zerot = zerot->next;
        }
        else if (temp->data == 1)
        {
            curr = temp;
            temp = temp->next;
            curr->next = nullptr;
            if (one == nullptr)
            {
                one = curr;
                onet = curr;
            }

            onet->next = curr;
            onet = onet->next;
        }
        else if (temp->data == 2)
        {
            curr = temp;
            temp = temp->next;
            curr->next = nullptr;
            if (two == nullptr)
            {
                two = curr;
                twot = curr;
            }

            twot->next = curr;
            twot = twot->next;
        }
   
    }
    if(zerot==nullptr&&onet!=nullptr){
    zero=one;
    onet->next = two;
    twot->next=nullptr;

    }
    else if(zerot==nullptr&&onet==nullptr){
    zero=two;
    twot->next=nullptr;
    }
    else if(zerot!=nullptr&&onet!=nullptr){
    zerot->next=one;
    onet->next=two;
    }
    else if(zerot!=nullptr&&onet==nullptr){
    zerot->next=two;
    twot->next=nullptr;
    }
   

    Display(zero);
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertLast(head, tail, 0);
    insertLast(head, tail, 0);

    insertLast(head, tail, 1);
    insertLast(head, tail, 0);

    insertLast(head, tail, 1);
    insertLast(head, tail, 2);

    insertLast(head, tail, 1);

    insertLast(head, tail, 1);

    insertLast(head, tail, 2);
    insertLast(head, tail, 0);
    insertLast(head, tail, 2);

    Display(head);
    sort(head);
    // Display(head);
    return 0;
}