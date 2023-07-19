#include <iostream>
#include <vector>

using namespace std;
void perm(vector<vector<int>> &v, vector<vector<int>> &ans, vector<int> &temp, int s, int d)
{
    int row = s / 5, col = s % 5;

    int ch;
    if (s == d)
    {
        ch = row * 5 + col ;
        temp.push_back(ch);
        ans.push_back(temp);
        return;
    }
    if (v[row][col]==0){
        temp.push_back(-1);
        ans.push_back(temp);
        return;
    }
    
    int news;
    if (row - 1 >= 0 && v[row - 1][col] == 1  )
    { 
      
        ch = row * 5 + col ;
        
        v[row][col]=0;
        temp.push_back(ch);
        news = row * 5 + col - 5;
        perm(v, ans, temp, news, d);
        temp.pop_back();
        v[row][col]=1;
    }
    if (row + 1 < 5 && v[row + 1][col] == 1  )
    {
        ch = row * 5 + col;
        v[row][col]=0;
       
        temp.push_back(ch);
        news = row * 5 + col + 5;
        perm(v, ans, temp, news, d);
        temp.pop_back();   v[row][col]=1;
    }
    if (col - 1 >= 0 && v[row][col - 1] == 1)
    {
        ch = row * 5 + col;
        v[row][col]=0;
        temp.push_back(ch);
        news = row * 5 + col - 1;
        perm(v, ans, temp, news, d);
        temp.pop_back();   v[row][col]=1;
    }
    if (col + 1 < 5 && v[row][col + 1] == 1 )
    {
        ch = row * 5 + col;
        v[row][col]=0;

        temp.push_back(ch);
        news = row * 5 + col + 1;
        perm(v, ans, temp, news, d);
        temp.pop_back();   v[row][col]=1;
    }
}
int main()
{

    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> v = {
        {1, 0, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 1, 1, 1},
    };
    perm(v, ans, temp, 0, 24);
    for(auto &j:ans){
    for (auto i : j)
        cout << i<< " ";
    cout<<endl;
    }
    return 0;
}