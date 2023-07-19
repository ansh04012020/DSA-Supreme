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

int maxDepth(Node* root) {
         if (root ==nullptr)
    {
        // ans.push_back(-1);
        return 0;
    }
 int h1= maxDepth(root->left);
 int h2= maxDepth(root->right); 
 h1=max(h1,h2);
 return h1+1;
    }
    int diameterOfBinaryTree(Node* root) {
          if (root ==nullptr)
    {
        // ans.push_back(-1);
        return 0;
    }
 int h1= diameterOfBinaryTree(root->left);
 int h2=  diameterOfBinaryTree(root->right); 
   int h3=maxDepth(root->left)+maxDepth(root->right);
 return max(h1,max(h2,h3));
    }
int main()
{
    vector<int> data = {20,30,50,-1,60,-1,-1,40,-1,-1,100,-1,-1};
    int i = 0;
    Node *head = createTree(data, i);
   std::cout<<diameterOfBinaryTree(head);
    
    return 0;
}