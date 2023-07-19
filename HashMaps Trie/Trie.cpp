#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Node
{
public:
    char data;
    bool term;
    Node *child[26];

    Node(char d)
    {
        data = d;
        term = false;
        for(int i=0;i<26;i++)
        child[i]=nullptr;
    }
};
void insertWord(Node *root, string s)
{
    if (s.length() == 0)
    {
        root->term = true;
        return;
    }

    if (root->child[s[0] - 'a']==nullptr)
    {
        root->child[s[0] - 'a'] = new Node(s[0]);
    }
       

    insertWord(root->child[s[0] - 'a'], s.substr(1));
}
bool search( Node* root, string s){
    if(s.length() == 0)
    return root->term;
   
    
    if(root->child[s[0]-'a'])
   return search(root->child[s[0]-'a'],s.substr(1));
   

   return false;
}
int main()
{
    Node *root = new Node('-');
    insertWord(root,"coding");
    insertWord(root,"hello");
    insertWord(root,"codg");
    insertWord(root,"cbhukhang");
    insertWord(root,"cillengo");
    cout<<search(root,"hello");
    return 0;
}