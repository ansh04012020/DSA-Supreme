#include <iostream>
#include <vector>
#include <string>
using namespace std;
void perm(vector<string>&v, string &s,int i)
{
    if (i>= s.size())
    {
        v.push_back(s);
        return;
    }
   for(int j=i;j<s.size();j++){
    swap(s[i],s[j]);
    perm(v,s,i+1);
    swap(s[i],s[j]);
   }
}
int main()
{
    int i = 0;
    string s = "exqc";
 
    vector<string> v;
    perm(v, s,0);
    for(auto i:v)
    cout<<i<<" ";
    return 0;
}