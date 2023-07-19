#include <iostream>
using namespace std;
int main()
{
    int Pyr_Size;
    cout << "Enter Size of Pyramid::";
    cin >> Pyr_Size;
int temp=1;
    for (int levels = 0; levels <= Pyr_Size; levels++)
    {
        temp=levels;
        for (int space = 0; space <= Pyr_Size - levels; space++)
        {
            cout << "  ";
        }
        for (int row = 0; row <  2*levels -1; row++)
        {
            cout << temp<<" ";
            if(temp<=2*levels-2)
            temp++;
            else
            temp--;
        }
        cout << endl;
    }

    return 0;
}