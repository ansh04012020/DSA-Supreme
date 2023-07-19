#include <iostream>
#include <queue>

using namespace std;
void restA(queue<int> &que, int k)
{

    for (int i = 0; i < que.size() - k; i++)
    {
        int data = que.front();
        que.pop();
        que.push(data);
    
    }
}
void revKQueue(queue<int> &que, int k, int count)
{
    if (que.empty())
    {
        return;
    }
    if (count < k)
    {
        count++;
        int data = que.front();
        que.pop();
        revKQueue(que, k, count);
        que.push(data);
    }
    
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

    revKQueue(que, 4, 0);
    restA(que,4);
    while (!que.empty())
    {
        cout << que.front();
        que.pop();
    }

    return 0;
}