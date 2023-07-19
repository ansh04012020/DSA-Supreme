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

Node *createTree(vector<int> &data, int &i)
{
    Node *root;
    if (data[i] == -1)
    {
        i = i + 1;
        return nullptr;
    }
    root = new Node(data[i]);
    i = i + 1;
    root->left = createTree(data, i);
    root->right = createTree(data, i);

    return root;
}
void left(Node* root,vector<int> &ans){
    if(root!=nullptr&&root->left==nullptr&&root->right==nullptr||root==nullptr)
    return;
    
    
    ans.push_back(root->data);
    
    if(root->left )
    left(root->left,ans);
     else
    left(root->right,ans);
}
void leaf(Node* root,vector<int> &ans){
    if(root==nullptr)
    return;
    
    if(root!=nullptr&&root->left==nullptr&&root->right==nullptr){
    ans.push_back(root->data);
    }
    
    
    leaf(root->left,ans);
    leaf(root->right,ans);
        
    
}
void right(Node* root,vector<int> &ans){
    if(root!=nullptr&&root->left==nullptr&&root->right==nullptr ||root==nullptr)
    return;
    
    
    
     if(root->right)
    right(root->right,ans);
    else
    right(root->left,ans);
    
    
    ans.push_back(root->data);
}
void solve(Node* root,vector<int> &ans){
    if(root==nullptr)
    return;
    
    Node*parent=root;
    left(root,ans);
    leaf(root,ans);
    right(root,ans);
    
    ans.pop_back();
}
int main()
{
    vector<int> data = {4 ,10 ,-1, 5, 5, -1, 6, 7, -1, 8, 8, -1, 8, 11, -1, 3, 4, -1, 1, 3, -1, 8, 6, -1, 11 ,11, -1, 5, 8};
    int i = 0;
    Node *head = createTree(data, i);

    
    vector<int> ans;
        
        solve(head,ans);
        
        for(auto i:ans)
        cout<<i;
    
    return 0;
}