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
int len(Node *head){
    int count=0;
    while(head!=nullptr){
        head=head->next;
        count++;
    }
    return count;
}
Node * kgroupRev(Node*head,int k){
  if(head==nullptr)
  cout<<"No nodes to reverse";

  else if(len(head)<k)
  return head;

  Node*prev=nullptr;
  Node*curr=head;
  Node*forward=head->next;
 int count=0;
 while(count<k){
     forward=curr->next;
     curr->next=prev;
     prev=curr;
     curr=forward;

     count++;
    
 }
     Display(prev);

if(forward!=nullptr)
head->next=kgroupRev(forward,k);

return prev;
  

}


int main(){
    Node* head=nullptr;
    Node* tail=nullptr;


    insertLast(head,tail,7);
   
    insertLast(head,tail,4);
    
    insertLast(head,tail,1);
   
    insertLast(head,tail,11);
    insertLast(head,tail,5);
    
    insertLast(head,tail,6);
   
    insertLast(head,tail,13);
    insertLast(head,tail,15);
    insertLast(head,tail,19);
    insertLast(head,tail,18);
    insertLast(head,tail,20);
   
    Display(head);

   Display(kgroupRev(head,2));


return 0;
}