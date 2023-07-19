#include<cmath>
#include<iostream>
using namespace std;

    bool isPowerOfTwo(long long int n) {
   
        if ( n>0){
            
        if(log2(n)==(long long int)log2(n))
           return true;  
        else
            return false;
        }
        else
           return false;
    }

int main(){
  cout<<  isPowerOfTwo(16);

}