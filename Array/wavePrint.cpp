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






    for(int i=0;i<col;i++){
        if(i%2==0){
            for(int j=0;j<row;j++){
            cout<<a[j][i]<<" ";
            }
        }
        else{
            for(int j=row-1;j>=0;j--)
            cout<<a[j][i]<<" ";
        }
    

    }
    return 0;
}
