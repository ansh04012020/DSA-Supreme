#include <iostream>
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

void placeNode(Node *&root, Node *temp)
{

    if (root == nullptr)
        root = temp;
    else if (temp->data > root->data)
        placeNode(root->right, temp);
    else if (temp->data < root->data)
        placeNode(root->left, temp);
}

void levelOrd(Node *root)
{
    if (root == nullptr)
        cout << "Tree is Empty" << endl;

    queue<Node *> que;
    que.push(root);
    que.push(nullptr);

    while (!que.empty())
    {
        Node *temp = que.front();
        que.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!que.empty())
                que.push(nullptr);
            continue;
        }
        if (temp->data == -1)
        {
            cout << temp->data << " ";
            continue;
        }
        cout << " " << temp->data << " ";

        if (temp->left != nullptr)
        {
            que.push(temp->left);
        }
        if (temp->left == nullptr)
            que.push(new Node(-1));
        if (temp->right != nullptr)
        {
            que.push(temp->right);
        }
        if (temp->right == nullptr)
            que.push(new Node(-1));
    }
}

Node* inorderBST(vector<int> inorder,int s,int e){

    if(s>e)
    return nullptr;

    int mid=s+(e-s)/2;

    Node* root=new Node(inorder[mid]);

    root->left=inorderBST(inorder,s,mid-1);
    root->right=inorderBST(inorder,mid+1,e);

    return root;

}

int main()
{
    
    vector<int> inorder={2,4,5,6,8,10,11,15,17,20,25};
    // vector<int> inorder={1,2,3,4,5,6,7,8,9};
    
      int s=0;
        int e=inorder.size()-1;
    Node *root = inorderBST(inorder,s,e);
    levelOrd(root);
      
    return 0;
}