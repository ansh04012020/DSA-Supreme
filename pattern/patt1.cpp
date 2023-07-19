#include <iostream>
using namespace std;
int main()
{
    int temp = 1, count = 1, n;
    cin >> n;
    for (int i = 1; i <= count; i++)
    {
        for (int j=1;j<=count;j++)
        {
            cout << temp++<<" ";
            if(temp>n)
            break;

               
            
        }
            if(temp>n)
            break;
         cout << endl;
                count++;
    }
        return 0;
    }
