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

int main()
{

    Heap hp;

    hp.insert(10);
    hp.insert(8);
    hp.insert(4);
    hp.insert(2);
    hp.insert(3);
    hp.insert(6);
    hp.insert(7);
    // hp.insert(50);
    // hp.insert(30);
    // hp.insert(70);
    // hp.insert(40);
    // hp.insert(80);
    // hp.insert(100);
    hp.print();
    cout << hp.deleteion() << endl;
    hp.print();
    cout << hp.deleteion() << endl;
    hp.print();
    cout << hp.deleteion() << endl;
    hp.print();

    return 0;
}