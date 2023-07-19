#include<iostream>
#include<vector>
#include<string>
using namespace std;
void subSeq(vector<string> &v,string temp,string &s, int i){
    if (i>=s.size())
    {
        v.push_back(temp);
        return;
    }
    

    subSeq(v,temp,s,i+1);

    temp.push_back(s[i]);

    subSeq(v,temp,s,i+1);
    }
int main(){
    int i=0;
    string s="agam";
    string ans="";
    vector<string>v;
    subSeq(v,ans,s,i);
    cout<<"{";
    for(auto i:v)
    cout<<i<<" ";
    cout<<"}";
return 0;
}