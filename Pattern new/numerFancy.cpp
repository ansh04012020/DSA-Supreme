#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
for(int i=0;i<=n;i++){
    for (int j = 0; j <i; j++)
    {
        
        cout<<i; 
        if(j!=i-1)
        cout<<'*'; 
         
    }
    cout<<endl;
}
for(int i=n;i>=0;i--){
     for (int j = 0; j <i; j++)
    {
        if(j!=0)
        cout<<'*'; 
        cout<<i;
   
           
    }
    cout<<endl;
}
return 0;
}