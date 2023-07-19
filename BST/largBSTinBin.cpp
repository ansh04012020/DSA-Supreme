#include<iostream>
#include <math.h>
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

void inOrd(Node *root)
{
    if (root == nullptr)
        return;

        inOrd(root->left);
        cout<<root->data<<" ";
        inOrd(root->right);

   
  
}

int main(){

    return 0;
}
