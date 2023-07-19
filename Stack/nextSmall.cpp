#include <iostream>
#include <stack>  
#include <vector>  
using namespace std;

void sort(stack<int> &st,vector<int>ip )
{

  
}
int main()
{
    stack<int> st;
    vector<int> st=;
    st.push(3);
    st.push(9);
    st.push(7);
    st.push(8);
    st.push(2);

    
    sort(st);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}