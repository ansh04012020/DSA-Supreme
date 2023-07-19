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
void buildBST(Node *&root)
{
    int data;
    cin >> data;
    if (data == -1)
        return;
    Node *temp = new Node(data);
    placeNode(root, temp);
    buildBST(root);
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



void inorder(Node*root,vector<int> &inorderV){
    if(root==nullptr)
    return ;

    inorder(root->left,inorderV);
    inorderV.push_back(root->data);
    inorder(root->right,inorderV);
}

int main()
{
// 10 20 5 11 17 2 4 8 6 25 15 -1
    Node *root = nullptr;
    buildBST(root);
    levelOrd(root);
   
   
    vector<int> inorderv;
    inorder(root,inorderv);
    int target=15;

    int s=0,e=inorderv.size()-1;
    while(s<e){
        if(inorderv[s]+inorderv[e]==target){
        cout<<inorderv[s]<<" "<<inorderv[e]<<endl;
         s=s+1;
         e=e-1;
        }
        else if(inorderv[s]+inorderv[e]<target)
        s=s+1;
        else
        e=e-1;
    }
    return 0;
}