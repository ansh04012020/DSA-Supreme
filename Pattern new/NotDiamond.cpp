#include <iostream>
using namespace std;
int main()
{
    int Pyr_Size;
    cout << "Enter Size of Pyramid::";
    cin >> Pyr_Size;
int n=Pyr_Size+1;
    for (int row = 0; row <=n/2; row++)
    {
        for (int col = 0; col <=n    ; col++)
        {
            if(col>=n/2-row +1&& col<=n/2-1+row )
            cout<<"  ";
            else
            cout<<"* "; 
        }
        
        cout << endl;
    }

       for (int row =n/2-1; row >=0; row--)
    {
        
        for (int col = 0; col <=n    ; col++)
        {
            if(col>= n/2-row+1 && col<=n/2+row-1  )
            cout<<"  ";
            else
            cout<<"* ";
        }
        cout << endl;
    }
      
  

    return 0;
}