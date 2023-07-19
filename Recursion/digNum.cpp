#include<iostream>
using namespace std;
void print(int n[],int ind,int size,int &max){
   if(ind>=size)
   return;

   

   if(n[ind]>max)
   max=n[ind];

   print(n,ind+1,size,max);

  // return max;


}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];

int max=INT_MIN;

print(arr,0,n,max);
cout<<max;
return 0;
}