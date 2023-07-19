#include<iostream>
using namespace std;
class Node{
    
    public:
    int data;
    Node* next;

   Node(){
    this->data=0;
    this->next=nullptr;
   }
   Node(int data){
    this->data=data;
    this->next=nullptr;
   }


}; 
void Display(Node * list){
  while(list!=nullptr){
  cout<<list->data<<" ";
  list=list->next;
  }

  cout<<endl;
}
void insertBeg(Node * &head,Node * &tail,int data){
    Node* newNode=new Node(data);
    
    if(head==nullptr)
    tail=newNode;

    newNode->next=head;
    head=newNode;
}
void insertLast(Node * &head,Node* &tail,int data){
    Node* newNode=new Node(data);
   

    if(tail==nullptr){
        head=newNode;
        tail=newNode;
    }
    else{

    tail->next=newNode;
    tail=newNode;

    }

} 
void insertPos(Node * &head, Node* &tail,int posn,int data){
   
    if(posn==1)
    {
        insertBeg(head,tail,data);
        return;
    }
    Node* newNode=new Node(data);
   Node *temp=head;
int i=1;
while(i<posn-1)
{temp=temp->next;
if(temp==nullptr)
{ i=0;
    break;
}
i=i+1;
}

if(i==0){
    insertLast(head,tail,data);
   return;
}
newNode->next=temp->next;
temp->next=newNode;
} 
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    insertBeg(head,tail,5);
    // Display(head);
    insertBeg(head,tail,9);
    // Display(head);
    insertLast(head,tail,7);
    // Display(head);
    insertPos(head,tail,4,6);
    // Display(head);
    insertPos(head,tail,1,3);
    // Display(head);
    insertPos(head,tail,11,13);
   
    Display(head);

return 0;
}