#include <iostream>
using namespace std;
int main()
{
    int n;
    char a='D';
    char b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
b=a;
        for (int j=i;j>0;j--)
        {
            cout <<b++<<" ";
            
        }
        a--;
         cout << endl;
                
    }
        return 0;
    }
 