#include<iostream>
using namespace std;
int main(){
int Square_Size;
cout<<"Enter Size of Square::";
cin>>Square_Size;


for(int row=0;row<Square_Size;row++){
for(int col=0;col<Square_Size;col++)
  cout<<"* ";

cout<<endl;
}

return 0;
}