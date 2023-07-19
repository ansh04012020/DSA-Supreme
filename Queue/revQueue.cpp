#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void revQueue(queue <int> & que){
if(que.empty()){
    return;
}

int data= que.front();
que.pop();
revQueue(que);
que.push(data);

}

int main(){


    queue<int> que;
    stack<int> st;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    // while(!que.empty()){
    //     st.push(que.front());
    //     que.pop();
    // }
    // while(!st.empty()){
    //     que.push(st.top());
    //     st.pop();
    // }

   
    revQueue(que);
    while(!que.empty()){
        cout<<que.front();
        que.pop();
    }
    
return 0;
}