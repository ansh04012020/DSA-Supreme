#include<iostream>
#include <cstring>

using namespace std;
void  ArrDo(int arr[]){

cout<<sizeof(arr);

}
int main(){

int brr[10]={1,2,3,4};


ArrDo(brr);
cout<<sizeof(brr);
cout<<sizeof(&brr);
return 0;
}