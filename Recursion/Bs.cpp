#include<iostream>
#include<vector>
using namespace std;
int BS(vector<int> &v,int &s,int &e,int& key){
    
    int mid=s+(e-s)/2;

    if(s>=e)
    return -1;
    else if(v[mid]==key)
    return mid;
    else if(v[mid]<key)
    s=mid+1;
    else
    e=mid;
 
 return BS(v,s,e,key);

}
int main(){

vector<int> res={1,11,22,31,47,55,58,66,77};
int s=0,e=res.size(),key=77;
cout<<BS(res,s,e,key);

    return 0;
}
