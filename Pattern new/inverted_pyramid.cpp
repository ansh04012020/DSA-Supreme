#include<iostream>
using namespace std;
int main(){
int Row_Size;
cout<<"Enter Size of Row::";
cin>>Row_Size;



for(int row=Row_Size;row>0;row--){
for(int col=0;col<row;col++){

  cout<<"* ";
}


cout<<endl;
}

return 0;
}