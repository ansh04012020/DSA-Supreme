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

int heightTree(Node*root){
    if (root ==nullptr)
    {
        // ans.push_back(-1);
        return 0;
    }
 int h1= heightTree(root->left);
 int h2=  heightTree(root->right); 
 h1=max(h1,h2);
 return h1+1;
}
int main()
{
    vector<int> data = {10,20,40,11,-1,-1,-1,50,-1,-1,30,60,-1,-1,70,-1,-1};
    int i = 0;
    Node *head = createTree(data, i);
   cout<< heightTree(head);
    
    return 0;
}