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
vector<int> lev_OrdTrav(Node *root)
{
    queue<Node *> que;

    vector<int> ans;
    que.push(root);
    que.push(nullptr);
    while (!que.empty())
    {
        Node *temp = que.front();
        que.pop();
        if (temp == nullptr)
        {
            ans.push_back(-1);
            // cout<<endl;
            if (!que.empty())
                que.push(nullptr);
        }
        else
        {
           
            ans.push_back(temp->data);
            // cout<<temp->data<<" ";

            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
    }
    return ans;
}
int main()
{
    vector<int> data = {20, 30, 50, -1, 60, -1, 70,-1,-1, 40, -1, -1, 100, -1, -1};
    int i = 0;
    Node *head = createTree(data, i);

    vector<int> ans = lev_OrdTrav(head);
    for(auto i : ans)
    {
        if (i == -1)
            cout << endl;
        else
            cout << i<<" ";
    }
    return 0;
}