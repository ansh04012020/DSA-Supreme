#include <iostream>
#include <vector>
using namespace std;
class Heap
{
public:
    vector<int> heap;
    int size;
    Heap()
    {
        heap.push_back(-1);
        size = 0;
    }

    void insert(int value)
    {
        size++;
        this->heap.push_back(value);
        int i = size;
        while (i > 1)
        {
            if (heap[i] > heap[i / 2])
            {
                swap(heap[i], heap[i / 2]);
                i = i / 2;
            }
            else
                break;
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << heap[i] << " ";

        cout << endl;
    }

    int deleteion()
    {

        swap(heap[1], heap[size]);
        int ele = heap[size];
        heap.pop_back();
        size--;
        int i = 1;
        while (i <= size)
        {

            if (2 * i + 1 <= size && heap[2 * i] < heap[2 * i + 1] && heap[i] < heap[2 * i + 1])
            {
                swap(heap[i], heap[2 * i + 1]);
                i = 2 * i + 1;
            }
            else if (2 * i <= size && heap[i] < heap[2 * i])
            {
                swap(heap[i], heap[2 * i]);
                i = 2 * i;
            }
            else
                break;
        }
        return ele;
    }
};

void heapify(vector<int> &heap, int n, int i)
{

    if (2 * i + 1 <= n && heap[2 * i] < heap[2 * i + 1] && heap[i] < heap[2 * i + 1])
    {
        swap(heap[i], heap[2 * i + 1]);
        i = 2 * i + 1;
    }
    else if (2 * i <= n && heap[i] < heap[2 * i])
    {
        swap(heap[i], heap[2 * i]);
        i = 2 * i;
        // heapify(heap,n,i);
    }
    else
        return;
        
        heapify(heap,n,i);
}
void buildheap(vector<int> &heap){
 
    int size = heap.size()-1;
   for(int i=size/2;i>0;i--){
     heapify(heap,size,i);
   }
   
}
int main()
{

//    vector<int> heap={-1,50,60,70,80,90,10,12,15,11,13,8,6,2};
   vector<int> heap={-1,12,15,13,11,14};
//    vector<int> heap={-1,12,56,43,6,78,87,5,44,3,23,32};
   //how to create heap?  No need to Heapify leef nodes;
   
   buildheap(heap);
   for(int i=1;i<=heap.size()-1;i++)
   cout<<heap[i]<<" ";
  
    return 0;
}