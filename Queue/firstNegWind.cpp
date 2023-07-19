#include <iostream>
#include <queue>

using namespace std;
queue<int> *firstneg(queue<int> &que,int ws)
{
    if (que.empty())
        cout << "Empty Queue,Can Not" << endl;

    queue<int> window;
    
    queue<int> *result=new queue<int>;
    int neg=0,temp;

    for(int i=0;i<ws;i++){
     temp= que.front();
     que.pop();

     if(temp<0)
     (*result).push(temp);

     que.push(temp);
        

    }

 
    return result;
}

int main()
{

    queue<int> que;

    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.push(6);
    que.push(7);
    que.push(8);
    que.push(9);

    queue<int>* res=interleave(que);

    while (!(*res).empty())
    {
        cout << (*res).front()<<" ";
        (*res).pop();
    }

    return 0;
}