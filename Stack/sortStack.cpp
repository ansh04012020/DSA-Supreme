#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int target)
{
if(!st.empty()&&target>st.top()){
    int temp = st.top();
    st.pop();
    insertSorted(st,target);
    st.push(temp);
}
else
st.push(target);
}
void sort(stack<int> &st)
{

    if (st.empty())
        return;
    int curr = st.top();
    st.pop();
    sort(st);

    if (!st.empty() && curr > st.top())
    {
        insertSorted(st, curr);
    }
    else
        st.push(curr);
}
int main()
{
    stack<int> st;
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