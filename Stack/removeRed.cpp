#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool Red(stack<int> &st, string &s)
{
    int oper = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            oper = 1;
        }

        if (!st.empty() && s[i] == ')' && oper == 1)
        {
            st.pop();
            oper = 0;
        }
        else if(!st.empty() && s[i] == ')' && oper == 0)
        return true;

       
    }
    return false;
}
int main()
{
    stack<int> st;
    string s = "(a+b)+()";

    cout << Red(st, s);

    // while(!st.empty()){
    // cout<<st.top()<<" ";
    // st.pop();
    // }

    return 0;
}