#include<iostream>
#include<vector>
using namespace std;
int bs(vector<int> a,int t){
int s=0;int e=a.size();
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

int main(){
vector <int> a{0,1,2,3,4,9,10,11,12,13,14};
int t;
cout<<"enter no."<<endl;
cin>>t;
cout<<bs(a,t);
return 0;
}