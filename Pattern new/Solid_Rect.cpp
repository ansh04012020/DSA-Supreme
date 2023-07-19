#include<iostream>
using namespace std;
int main(){
int Row_Size,Columnn_Size;
cout<<"Enter Size of Row::";
cin>>Row_Size;
cout<<"Enter Size of ColiRow_Sizen::";
cin>>Columnn_Size;

for(int i=0;i<Row_Size;i++){
for(int i=0;i<Columnn_Size;i++)
  cout<<"* ";

cout<<endl;
}

return 0;
}