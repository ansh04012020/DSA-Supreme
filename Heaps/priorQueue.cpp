#include<queue>
#include<iostream>

using namespace std;
int main(){

    // priority_queue <int> pq;
    // pq.push(3);
    // pq.push(6);
    // pq.push(9);
    // pq.push(4);
    // pq.push(8);
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.size()<<endl;
    // cout<<pq.empty()<<endl;


     priority_queue<int,vector<int>,greater<int>>pq;
     
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.size()<<endl;
    cout<<pq.empty()<<endl;
    return 0;
}