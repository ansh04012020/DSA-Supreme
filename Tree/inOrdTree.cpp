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
    root->left = createTree(data, i);
    root = new Node(data[i]);
    i = i + 1;
    root->right = createTree(data, i);

    return root;
}

int main()
{
    vector<int> data = {3,1,4,5,2};
    int i = 0;
    Node *head = createTree(data, i);

  
    return 0;
}