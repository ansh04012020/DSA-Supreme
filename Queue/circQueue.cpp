#include <iostream>
using namespace std;
class cirQueue
{
public:
    int front, rear, size;
    int *q;
    cirQueue(int n)
    {
        int *q = new int[n];
        front = -1, rear = -1;
        size = n;
    }
    void insert(int data)
    {

        if (rear == -1 && front == -1)
        {
            rear = 0;
            front = 0;
            this->q[this->rear] = data;
        }
        else if ((rear + 1) % size == front)
            cout << "Q is full" << endl;
        else
        {
            rear = (rear + 1) % size;
            this->q[this->rear] = data;
        }
    }
    void pop()
    {

        if (rear == -1 && front == -1)
        {
            cout<<"Q is Empty"<<endl;
           
        }
        else if (rear== front)
        {
           this->q[this->front] = -1;
            front = -1,rear=-1;
        }
        else
        {
            this->q[this->front] = -1;
            front = (front + 1) % size;
        }
    }
    int getFront()
    {

        if (rear == (front + 1) % size)
        {

            cout << "Q is empty" << endl;
            return -1;
        }

        return this->q[this->front];
    }
    int getsize()
    {
        return (size + rear - front) % size;
    }
    bool isEmpty()
    {
        if (rear == -1 && front == -1)
        {
            return 1;
        }
        return 0;
    }
    void Display()
    {
        if(!isEmpty()){
            int i = -1;
            for (i = front; (i) % size != rear; i = (i + 1) % size)
                cout << q[i] << " ";
            cout << q[i];
            cout << endl;
        }
        else
        cout<<"Nothing to Display"<<endl;
       
    }
};
int main()
{
    cirQueue que(5);
    que.insert(2);
    que.insert(3);
    que.insert(4);
    que.insert(5);
    que.insert(6);
    que.insert(7);
    que.Display();
    que.pop();
    que.pop();
    que.Display();
    que.insert(7);
    que.insert(8);
    que.Display();
    que.pop();
    que.pop();
    que.pop();
    que.pop();
    que.pop();
    que.pop();
  
    que.Display();



    return 0;
}