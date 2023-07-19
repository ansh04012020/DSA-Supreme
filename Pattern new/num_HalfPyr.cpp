#include<iostream>
using namespace std;
int main(){
int Row_Size,Column_Size;
cout<<"Enter Size of Row::";
cin>>Row_Size;



for(int row=0;row<Row_Size;row++){
for(int col=0;col<=row;col++){

  cout<<col+1<<" ";
}


cout<<endl;
}

return 0;
}