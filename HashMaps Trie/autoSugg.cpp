#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Node
{
public:
    char data;
    bool term;
    unordered_map<char, Node *> *mp;

    Node(char d)
    {
        data = d;
        term = false;
        this->mp = new unordered_map<char, Node *>;
    }
};
void insertWord(Node *root, string s)
{
    if (s.length() == 0)
    {
        root->term = true;
        return;
    }

    if (root->mp->count(s[0]) == 0)
    {
        root->mp->insert({s[0], new Node(s[0])});
    }

    insertWord(root->mp->at(s[0]), s.substr(1));
}

void solve(Node *root, vector<string> &ans, string temp)
{

    if (root == nullptr)
        return;

    temp.push_back(root->data);

    if (root->term)
        ans.push_back(temp);
    

    for (auto i : *root->mp)
        solve(i.second, ans, temp);
    
}
void getSugg(Node *root,string s, string temp, vector<vector<string>> &sol)
{
    if (s.length() == 0 || root->mp->count(s[0]) == 0)
        return;

    vector<string> x;
    solve(root->mp->at(s[0]), x, temp);
    temp.push_back(s[0]);
    getSugg(root->mp->at(s[0]), s.substr(1), temp, sol);
    sol.push_back(x);
}
int main()
{

   
    vector<vector<string>> sol;
    Node *root = new Node('-');

    //example 1
    insertWord(root, "lover");
    insertWord(root, "lane");
    insertWord(root, "lost");
    insertWord(root, "lend");
    insertWord(root, "loving");
    insertWord(root, "love");
    insertWord(root, "lord");
    insertWord(root, "least");
    insertWord(root, "last");
    insertWord(root, "list");
    insertWord(root, "live");


    //example2
    // insertWord(root, "coding");
    // insertWord(root, "coder");
    // insertWord(root, "codehelp");
    // insertWord(root, "code");
    // insertWord(root, "codeverse");
    // insertWord(root, "codingduniya");
    // insertWord(root, "codeforces");
   string search="lost",temp="";
    getSugg(root, search, temp, sol);

    for(int i=0;i<sol.size();i++){
        for(int j=0;j<sol[i].size();j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}