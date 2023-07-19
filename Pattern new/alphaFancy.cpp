#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
for(int i=0;i<=n;i++){
    int j;
    for ( j = 0; j <i; j++)
    {
        int ans=j;
        char ch=ans+'A';
        cout<<ch; 
         
    }
    for(j=j-1;j>=1;j--){
        int ans=j-1;
        char ch=ans+'A';
        cout<<ch;  
    }
    cout<<endl;
}

return 0;
}