#include <iostream>
#include <vector>
#include <string>
using namespace std;
void perm(vector<vector<int>> &v, vector<string> &ans, string &temp, int s, int d)
{
    int row = s / 5, col = s % 5;

 
    if (s == d)
    {
       
        // temp.push_back();
        ans.push_back(temp);
        return;
    }
    if (v[row][col]==0){
        temp.push_back('x');
        ans.push_back(temp);
        return;
    }
    int news;
    if (row - 1 >= 0 && v[row - 1][col] == 1  )
    { 
      
      
        
        v[row][col]=0;
        temp.push_back('U');
        news = row * 5 + col - 5;
        perm(v, ans, temp, news, d);
        temp.pop_back();
        v[row][col]=1;
    }
    if (row + 1 < 5 && v[row + 1][col] == 1  )
    {
       
        v[row][col]=0;
       
        temp.push_back('D');
        news = row * 5 + col + 5;
        perm(v, ans, temp, news, d);
        temp.pop_back();   v[row][col]=1;
    }
    if (col - 1 >= 0 && v[row][col - 1] == 1)
    {
       
        v[row][col]=0;
        temp.push_back('L');
        news = row * 5 + col - 1;
        perm(v, ans, temp, news, d);
        temp.pop_back();   v[row][col]=1;
    }
    if (col + 1 < 5 && v[row][col + 1] == 1 )
    {
      
        v[row][col]=0;

        temp.push_back('R');
        news = row * 5 + col + 1;
        perm(v, ans, temp, news, d);
        temp.pop_back();   v[row][col]=1;
    }
}
int main()
{
    int i = 0;
    string temp;
    vector<string> ans;
    vector<vector<int>> v = {
        { 1, 0, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 1, 1},
    };
    perm(v, ans, temp, 0, 24);
    for(auto j:ans){
        cout << j <<endl;
    }
    return 0;
}