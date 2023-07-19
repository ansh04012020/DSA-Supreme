#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[i][j] << " ";
            if (j % 3 == 2)
                cout << "|";
        }
        if ((i) % 3 == 2)
            cout << endl;
        cout << endl;
    }
    cout << endl;
}
bool isSafe(vector<vector<int>> &v, int row, int col, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (v[i][col] == val)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        if (v[row][i] == val)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        if (v[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }

    return true;
}
bool Sudoku(vector<vector<int>> &v, int col)
{
    if(col>=9)
    for (int i = 0; i < 9; i++)
    {
        // row
        if (v[i][col] == 0)
        {
            for (int val = 1; val <= 9; val++)
            {
                if (isSafe(v, i, j, val))
                {
                    v[i][col] = val;
                    bool ans = Sudoku(v);
                    if (ans)
                        return true;

                    v[i][j] = 0;
                }
            }
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 9;
    vector<vector<int>> v = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    Sudoku(v, 0);
    print(v);
    return 0;
}