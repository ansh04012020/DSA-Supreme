#include<iostream>
using namespace std;
int main(){
    int Marks;
    cin>>Marks;
    if(Marks>=90)
    cout<<"A grade";
    else if(Marks>=80)
    cout<<"B grade";
    else if(Marks>=60)
    cout<<"C grade";
    else if(Marks>=40)
    cout<<"D grade";
    else
    cout<<"E grade";
    return 0;
}