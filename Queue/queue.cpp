#include <iostream>
using namespace std;
class Queue
{
public:
    int front, rear, size;
    int *q;
    Queue(int n)
    {
        int *q = new int[n];
        front = 0, rear = 0;
        size = n;
    }
    void insert(int data)
    {

        if (rear == size)
            cout << "Q is full";
        else
        {
            this->q[this->rear] = data;
            rear++;
        }
    }
    void pop()
    {

        if (rear == front)
            cout << "Q is empty";
        else
        {
            this->q[this->front]=-1;
            front++;
        }
    }
    int getFront()
    {

        if (rear == front){

            cout << "Q is empty";
            return -1;
        }
        
            
            return this->q[this->front];
           
        
    }
    int getsize()
    {
        return rear-front;   
    }
    bool isEmpty(){
        if (rear == front){
            return 1;
        }
        return 0;
    }
    void Display(){
       for (int i = front; i < rear; i++)
        cout << q[i] << " "; 

        cout<<endl;
    }
};
int main()
{
    Queue que(5);
    que.insert(2);
    que.insert(3);
    que.insert(4);
    que.Display();
    que.pop();
    que.Display();

cout<<que.getFront()<<endl;
cout<<que.getsize();
    return 0;
}