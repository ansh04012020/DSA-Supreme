#include <iostream>
using namespace std;
int main()
{
    int Pyr_Size;
    cout << "Enter Size of Pyramid::";
    cin >> Pyr_Size;

    for (int levels = 0; levels <= Pyr_Size; levels++)
    {
        for (int space = 0; space <=levels; space++)
        {
            cout << " ";
        }
        for (int row = 0; row <Pyr_Size - levels ; row++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}