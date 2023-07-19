#include <iostream>
#include <vector>
#include <string>
using namespace std;
void keyPad(vector<string> &v, string temp, string &s, int i)
{
    if (i >= s.size())
    {
        v.push_back(temp);
        return;
    }
    int ind = 3*(s[i] - '2');
    if(ind==18||ind==21)
    ind=ind+1;

    temp.push_back(ind+'a');
    keyPad(v, temp, s, i + 1);
    temp.pop_back();
    temp.push_back(ind+1+'a');
    keyPad(v, temp, s, i + 1);
    temp.pop_back();
    temp.push_back(ind+2+'a');
    keyPad(v, temp, s, i + 1);
    temp.pop_back();

    if(ind==15||ind==22){
    temp.push_back(ind+3+'a');
    keyPad(v, temp, s, i + 1);
    temp.pop_back();
    }
}
int main()
{
    int i = 0;
    string s = "7";
    string ans = "";
    vector<string> v;
    keyPad(v, ans, s, i);
    cout << "{";
    for (auto i : v)
        cout << i << " ";
    cout << "}";
    return 0;
}