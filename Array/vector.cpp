#include<iostream>
#include<vector>
using namespace std;
int main(){
vector <int> arr(10,1);
 for(int i=0;i<=10;i++)
 cout<<arr[i];

cout<<arr.capacity();
cout<<endl<<arr.size();
arr.push_back(1);
cout<<endl<<arr.capacity();
cout<<endl<<arr.size();
return 0;
}