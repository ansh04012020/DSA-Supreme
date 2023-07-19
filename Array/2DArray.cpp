#include <iostream>
using namespace std;
void sum(int a[][4], int row, int col)
{
    int sumi = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            sumi = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = sumi;
        }
    }
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout<<a[i][j];
           
    //     }
    // }
    
}

int main()
{
    int Arr[3][4];
    int row = 3, col = 4;
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            cin >> Arr[i][j];
        }
    }

    sum(Arr, 3, 4);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << Arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}