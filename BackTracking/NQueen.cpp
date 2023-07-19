#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>> &v, int row, int col)
{
    int i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (v[i][j] == 1)
            return false;

        i--, j--;
    }
    i = row, j = col;
    while (j >= 0)
    {
        if (v[i][j] == 1)
            return false;

        j--;
    }
    i = row, j = col;
    while (i < v.size() && j >= 0)
    {
        if (v[i][j] == 1)
            return false;

        i++, j--;
    }
    return true;
}
void print(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void nQueen(vector<vector<int>> &v, int col)
{

    if (col >= v.size())
    {
        print(v);
        return;
    }

    int row = v.size();
    for (int i = 0; i < row; i++)
    {
        if (isSafe(v, i, col))
        {
            v[i][col] = 1;
            nQueen(v, col + 1);
            v[i][col] = 0;
        }
    }
}
int main()
{
    int n = 4;
    vector<vector<int>> v(n, vector<int>(n, 0));

    nQueen(v, 0);
    return 0;
}