#include<iostream>
using namespace std;
int main(){
int Row_Size,Column_Size;
cout<<"Enter Size of Row::";
cin>>Row_Size;
cout<<"Enter Size of Column::";
cin>>Column_Size;


for(int row=0;row<Row_Size;row++){
for(int col=0;col<Column_Size;col++)
  if(row==0||row==Row_Size-1||col==0||col==Column_Size-1)
  cout<<"* ";
  else
  cout<<"  ";

cout<<endl;
}

return 0;
}