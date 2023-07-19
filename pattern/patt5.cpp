#include <iostream>
using namespace std;
int main()
{
    int n;
    char a='A';
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j=n;j>0;j--)
        {


            cout <<a<<" ";
            
        }
     a++;
        
         cout << endl;
                
    }
        return 0;
    }
