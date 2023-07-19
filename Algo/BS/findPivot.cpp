#include <iostream>
#include <vector>
using namespace std;
int findPivot(vector<int> a)
{
        int s = 0, e = a.size()-1;
    int m = s + (e - s) / 2;
    int ans=-1;
    if(a[0]<=a[e])
    ans=a[0];
    else
    ans=a[e];
    while (s < e)
    {
              

        if((m+1)<a.size()&&a[m]> a[m+1])
        {
           return a[m+1];
        
        }
        else if ((m-1)>=0&&a[m] < a[m-1] )
        {
            return a[m] ;
           
        }
        else if (a[m] > a[e])
            s = m+1;
        else if (a[m] < a[e])
            e = m;

        m = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> a{9,10,11,12,13,14,0,1,2,3,4};

    cout <<findPivot(a) ;
    return 0;
}