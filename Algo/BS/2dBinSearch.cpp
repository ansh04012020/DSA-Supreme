#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> a(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            cin >> a.at(i).at(j);
        }
    }
    int s = 0, e = row * col - 1, i = 0, j = 0;
    int m = s + (e - s) / 2;
    int t;
    cin>>t;
    while (s < e)
    {
        i=m/col,j=m%row;

        if (t == a[i][j])
        {
            cout<<i<<" "<<j;
            break;
        }
        else if (t < a[i][j])
            e = m;
        else if (t > a[i][j])
            s = m + 1;

        m = s + (e - s) / 2;
    }

    return 0;
}
