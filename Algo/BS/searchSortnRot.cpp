#include <iostream>
#include <vector>
using namespace std;
int bs(vector<int> a,int s,int e,int t){

int m= s +(e-s)/2;



       int m=s +(e-s)/2;
        while(s<e){
    
            if(t==a[m]){
            return m;
            }
            else if(t<a[m])
            e=m;
            else if(t>a[m])
            s=m+1;

            m= s +(e-s)/2;
        }
     return -1;
}
int findPivot(vector<int> a)
{
    int s = 0, e = a.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if(s==e)
        return s;

        else if(a[m + 1] < a[m])
        {
           return m;
            
        }
        else if (a[m] < a[m - 1])
        {
            return m - 1;
           
        }
        else if (a[m] < a[s])
            e = m-1;
        else if (a[m] > a[s])
            s = m;

        m = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    vector<int> a{9,10,11,12,1,2,3,4,5,6,7,8};
    int t;
    cin>>t;
    int s=0,e=a.size();
    if(t>a[0]&&t< a[findPivot(a)] && findPivot(a)!=-1){
       cout<< bs(a,0,findPivot(a),t);
    }
    else if(t<a[0]&&t< a[findPivot(a)] && findPivot(a)!=-1){
       cout<< bs(a,findPivot(a),e,t);
    }
    return 0;
}