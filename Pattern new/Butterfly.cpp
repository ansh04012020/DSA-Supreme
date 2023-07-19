#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
for(int row=0;row<=n;row++){
    for(int col=0;col<=2*n+1;col++)
    {
        if(col>row&&col<2*n-row+1)
        cout<<"  ";
        else
        cout<<"* ";
    }
    cout<<endl;
}
for(int row=0;row<=n;row++){
    for(int col=0;col<=2*n+1;col++)
    {
        if(col>n-row&&col<n+row+1)
        cout<<"  ";
        else
        cout<<"* ";
    }
    cout<<endl;
}
return 0;
}