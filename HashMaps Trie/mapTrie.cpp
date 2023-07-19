#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Node
{
public:
    char data;
    bool term;
    unordered_map<char,Node*> *mp;

    Node(char d)
    {
        data = d;
        term = false;
       this->mp = new unordered_map<char,Node*>;
    }
};
void insertWord(Node *root, string s)
{
    if (s.length() == 0)
    {
        root->term = true;
        return;
    }

    if (root->mp->count(s[0])==0)
    {
        root->mp->insert({s[0], new Node(s[0])});
    }
       

    insertWord(root->mp->at(s[0]), s.substr(1));
}
bool search( Node* root, string s){
    if(s.length() == 0)
    return root->term;
   
    
    if(root->mp->count(s[0])==0)
    return false;

    if(root->mp->count(s[0])==1)
   return search(root->mp->at(s[0]),s.substr(1));
   

   return false;
}
void deleteWord( Node* root, string s){
    if(s.length() == 0&&root->term){
    root->term=false;
    return;
    }
   
    
    if(root->mp->count(s[0])==0)
    return;

    if(root->mp->count(s[0])==1)
   return deleteWord(root->mp->at(s[0]),s.substr(1));
   
}
int main()
{
    Node *root = new Node('-');
    insertWord(root,"coding");
    insertWord(root,"hello");
    insertWord(root,"codg");
    insertWord(root,"cbhukhang");
    insertWord(root,"cillengo");
    cout<<search(root,"codg")<<endl;
    deleteWord(root,"codg");
    cout<<search(root,"codg")<<endl;
    cout<<search(root,"hello")<<endl;
    deleteWord(root,"hello");
    cout<<search(root,"hello");


    for(auto i:*root->mp)
    cout<<i.first;

    return 0;
}