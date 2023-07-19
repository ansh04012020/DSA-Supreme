#include <iostream>
#include <vector>
#include <string>
using namespace std;
void perm(vector<string>&v, string &temp, string &s)
{
    if ( s.size()==0)
    {
        v.push_back(temp);
        return;
    }
   for(int j=0;j<s.size();j++){
    char curr=s[j];
    temp.push_back(curr);
    int n=s.find(curr);
    swap(s[n],s[s.size()-1]);
    s.pop_back();
    perm(v,temp,s);
    s.push_back(curr);
    swap(s[n],s[s.size()-1]);
    temp.pop_back();
   }
}
int main()
{
    int i = 0;
    string s = "xyz";
    string ans = "";
    vector<string> v;
    perm(v,ans, s);
    for(auto i:v)
    cout<<i<<" ";
    return 0;
}