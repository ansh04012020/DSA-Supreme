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

Node* findNode(Node *root, int target)
{

    if (root == nullptr)
        return nullptr;
    // bool ans1, ans2;
    if (root->data == target)
        return root;
    else if (root->data < target)
        return findNode(root->right, target);
    else
        return findNode(root->left, target);

}
int maxVal(Node *root)
{
    if (root == nullptr)
        return -1;
    while (root->right != nullptr)
        root = root->right;

    return root->data;
}
int minVal(Node *root)
{
    if (root == nullptr)
        return -1;
    while (root->left != nullptr)
        root = root->left;

    return root->data;
}

int inorderpred(Node *root, int target, int near)
{

    if (root == nullptr)
        return -1;

    if (root->data == target)
    {
        if (root->left)
            return maxVal(root->left);
        else
            return near;
    }
    else if (root->data < target)
    {
        near = root->data;
        return inorderpred(root->right, target, near);
    }
    else
        return inorderpred(root->left, target, near);
}
int inordersucc(Node *root, int target, int near)
{

    if (root == nullptr)
        return -1;

    if (root->data == target)
    {
        if (root->right)
            return minVal(root->right);
        else
            return near;
    }
    else if (root->data < target)
        return inordersucc(root->right, target, near);
    else
    {
        near = root->data;
        return inordersucc(root->left, target, near);
    }
}

Node *deltNodeBst(Node *root, int target)
{
    if (root == nullptr)
        return nullptr;
    Node *temp;
    if (root->data == target)
    {
       
        if (root->right == nullptr && root->left == nullptr){
        
            delete root;
            temp=nullptr;
        }
        else if (root->right && root->left == nullptr)
        {
            temp= root->right;
            root->right = nullptr;
            delete root;

           
        }
        else if (root->right == nullptr && root->left)
        {
            temp= root->left;
            root->left = nullptr;
             delete root;
        }
        else{
            int x;
            x= inordersucc(root,target,0);
            deltNodeBst(root,x);
            root->data=x;
            temp=root;
        }



        return temp;
    }
    if(root->data>target)
    root->left = deltNodeBst(root->left, target);
    if(root->data<target)
    root->right = deltNodeBst(root->right, target);
        
        return root;
}
bool validBST(Node* root,int lb,int rb){
    if(root==nullptr)
    return true;

    if(root->data>lb && root->data<rb)
    {
    bool ans1=validBST(root->left,lb,root->data);
    bool ans2=validBST(root->right,root->data,rb);
    return ans1 && ans2;
    }
    
    return false;

   

}
int main()
{

    Node *root = nullptr;
    buildBST(root);
    levelOrd(root);
    // cout<<findNode(root,25);
    // cout << minVal(root) << endl;
    // cout << maxVal(root) << endl;
    // cout << inorderpred(root, 20, 0) << endl;
    // cout << inordersucc(root, 5, 0) << endl;
    // deltNodeBst(root,100);
    // levelOrd(root);
    // deltNodeBst(root,60);
    // levelOrd(root);
      int l=INT_MIN;
        int r=INT_MAX;
        // cout<< valid(root,l,r)<<endl;
    return 0;
}