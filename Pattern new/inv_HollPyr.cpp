#include<iostream>
using namespace std;
int main(){
int Row_Size,Column_Size;
cout<<"Enter Size of Row::";
cin>>Row_Size;



for(int row=Row_Size;row>0;row--){
for(int col=0;col<row;col++){
if(col==0||col==row-1||row==Row_Size)
  cout<<"* ";
  else
  cout<<"  ";


}
cout<<endl;

}
return 0;}