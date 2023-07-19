#include <iostream>
#include<stack>
using namespace std;
// class Stack
// {
//     int top;
//     int *arr;
//     int size;

// public:
//     Stack(int size)
//     {
//         this->size = size;
//         top = -1;
//         arr = new int[this->size];
//     }
//     void push(int data)
//     {
//         if (this->top == this->size - 1)
//             cout << "Stackoverflow" << endl;
//         else
//         {
//             this->top++;
//             this->arr[this->top] = data;
//         }
//     }
//     void pop()
//     {
//         if (this->top == -1)
//             cout << "Stack underflow" << endl;
//         else
//         {
//             cout << this->arr[this->top] << endl;
//             this->top--;
//         }
//     }
//     int empty()
//     {
//         if (this->top == -1)
//         {
//             cout << "Stack Empty" << endl;
//             return 0;
//         }
//         else
//         {
//             cout << "Stack Not Empty" << endl;
//         }
//         return 1;
//     }
//     void topget()
//     {
//         if (this->top == -1)
//             cout << "Stack underflow" << endl;
//         else
//         {
//             cout << this->arr[this->top] << endl;
//         }
//     }

//     void mid()
//     {
//         int slow = top, fast = top;

//         while (fast != -1)
//         {
//             fast = fast - 1;
//             if (fast != -1)
//             {
//                 fast = fast - 1;
//                 if (fast != -1)
//                     slow = slow - 1;
//             }
//         }
//     cout<<arr[slow];
//     }

// };
void insertBottom(stack<int> &st,int &target){
if(st.empty()){
st.push(target);
return;
}

int temp=st.top();
st.pop();
insertBottom(st,target);
st.push(temp);
}

void reverse(stack<int> &st){
    if(st.empty())
    return;
   
    int tar=st.top();
    st.pop();
    reverse(st);
    insertBottom(st,tar);
   
}
int main()
{
    stack <int>st;
    st.push(110);
    st.push(120);
    st.push(130);

    st.push(140);

    

   
    reverse(st);
   
    while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
    }

    return 0;
}