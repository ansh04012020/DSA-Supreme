#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int bs(vector<int> a,int t, int s,int e){
// int s=0;int e=a.size();
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
vector <int> a{3,4,6,11,13,14,15,56,70};
int t;
cout<<"enter no."<<endl;
cin>>t;

int i=1;
if(a[0]==t)
i=0;
while(i<a.size()&&a[i]<=t)
i=2*i;

 
cout<<bs(a,t,i/2,min(i,a.size()-1));
return 0;
}