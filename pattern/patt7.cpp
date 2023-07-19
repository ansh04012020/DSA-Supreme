#include <iostream>
using namespace std;
int main()
{
    int n;
    char a='A';
    char b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
b=a;
        for (int j=n;j>0;j--)
        {

            cout <<b++<<" ";
            
     
        }
        a++;
         cout << endl;
                
    }
        return 0;
    }
 