#include<iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
class LNode{
    
    public:
    int data;
    LNode* next;

   LNode(){
    this->data=0;
    this->next=nullptr;
   }
   LNode(int data){
    this->data=data;
    this->next=nullptr;
   }


}; 


class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insertLast(LNode * &head,LNode* &tail,int data){
    LNode* newNode=new LNode(data);
   

    if(tail==nullptr){
        head=newNode;
        tail=newNode;
    }
    else{

    tail->next=newNode;
    tail=newNode;

    }

} 
void inOrd(Node *root)
{
    if (root == nullptr)
        return;

        inOrd(root->left);
        cout<<root->data<<" ";
        inOrd(root->right);

   
  
}

Node* ListtoBST(LNode* &head,int n){
    if(n<=0||head==nullptr)
        return nullptr;



        Node *leftTree=ListtoBST(head,n-n/2-1);

        Node * root=new Node(head->data);
        root->left=leftTree;

        head=head->next;

       root->right=ListtoBST(head,n/2);


       return root;

}
int main(){

    LNode * head=nullptr;
    LNode * tail=nullptr;
    insertLast(head,tail,10);
    insertLast(head,tail,20);
    insertLast(head,tail,30);
    insertLast(head,tail,40);
    insertLast(head,tail,50);
    insertLast(head,tail,60);
    insertLast(head,tail,70);

     int n=0;
       LNode*temp=head;
       while(head!=nullptr)
       {
           n++;
           head=head->next;
       }
       inOrd(ListtoBST(temp,n));
    return 0;
}