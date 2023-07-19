#include <iostream>
using namespace std;
int main()
{
    int Pyr_Size,count=1,temp;
    cout << "Enter Size of Pyramid::";
    cin >> Pyr_Size;

    for (int levels = 0; levels <= Pyr_Size; levels++)
    {
        
        for (int space = 0; space <= Pyr_Size - levels; space++)
        {
            cout << " ";
        }
        for (int row = 0; row <  2*levels+1 ; row++)
        {temp=count;
            cout <<temp++;
        }
        cout << endl;
       count++;
    }

    return 0;
}