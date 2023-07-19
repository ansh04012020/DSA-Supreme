#include <iostream>
#include <queue>

using namespace std;
queue<int> *interleave(queue<int> &que)
{
    if (que.empty())
        cout << "Empty Queue,Can Not" << endl;

    int n = que.size();
    queue<int> temp1;
    queue<int> *result=new queue<int>;
    while (temp1.size() < n / 2)
    {
        int data = que.front();
        que.pop();
        temp1.push(data);
    }
    while (temp1.size() != 0 || que.size() != 0)
    {

        if (temp1.size() != 0 && que.size() != 0)
        {
            int data1 = temp1.front();
            int data2 = que.front();
            que.pop();
            temp1.pop();
            (*result).push(data1);
            (*result).push(data2);
        }
        else if (temp1.size() == 0 && que.size() != 0)
        {
            int data2 = que.front();
            que.pop();
            (*result).push(data2);
        }
        else if (temp1.size() != 0 && que.size() == 0)
        {
            int data1 = temp1.front();
            temp1.pop();
            (*result).push(data1);
        }
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