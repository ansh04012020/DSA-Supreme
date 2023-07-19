#include <iostream>
#include <vector>
#include <queue>
using namespace std;
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
Node* solve(vector<int>& postorder, vector<int>& preorder,int  &preInd,int &size,vector<int> &visited){

     if(preInd>size) return NULL;
     int i;
    for( i=0;i<preorder.size();i++)
    {
        if(postorder[i]==preorder[preInd])
        break;
    }
    visited[preInd]=1;
    if(visited[i]==1){
         Node* root= new Node(preorder[preInd++]);
         root->left=nullptr;
         root->right=nullptr;

    return root;
    }
    else{

    visited[preInd]=1;
     Node* root= new Node(preorder[preInd++]);

     root->left=solve(postorder,preorder,preInd,size,visited);
     root->right=solve(postorder,preorder,preInd,size,visited);

     return root;
    }

 }


int main()
{
    vector<int>preorder={1,2,4,5,3,6,7};
    vector<int>postorder={4,5,2,6,7,3,1};
  int size=postorder.size();
        int preInd=0;
        vector<int> visited(size,0);
   Node * tree= solve(postorder,preorder,preInd,size,visited);
    return 0;
}