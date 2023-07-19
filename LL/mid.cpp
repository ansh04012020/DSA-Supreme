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

void findMid(Node *slow,Node *fast){
    if(slow==nullptr)
    cout<<"LinkList is Empty";
    else if(fast==nullptr)
    cout<<slow->data;

    fast=fast->next;
    if(fast!=nullptr){
    fast=fast->next;
    slow=slow->next;
    }
    findMid(slow,fast);
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;


    insertLast(head,tail,7);
   
    insertLast(head,tail,4);
    
    insertLast(head,tail,1);
   
    insertLast(head,tail,11);
    insertLast(head,tail,4);
    
    insertLast(head,tail,1);
   
    insertLast(head,tail,11);
   
    Display(head);
   findMid(head,head);

return 0;
}