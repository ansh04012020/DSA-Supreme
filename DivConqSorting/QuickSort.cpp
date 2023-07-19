#include<iostream>
#include<vector>
using namespace std;
int part(vector<int>&v,int s,int e){
int pivot= v[s];
int pI=s;
if(s==e)
return s;
int count=0;
for(int i=s+1;i<=e;i++){ 
    if(v[i]<=pivot)
    count++;
}
swap(v[pI],v[s+count]);
pI=s+count;
while(s<pI && e>pI){
    if(v[s]<=v[pI])
    s++;
    else if(v[e]>v[pI])
    e--;
    else if(s<pI && e>pI){
    swap(v[s],v[e]);  
    }
}
return pI;
}
void quickSort(vector<int> &v,int s,int e){
    if(s>=e)
    return;
    int pI=part(v,s,e);
    quickSort(v,s,pI-1);
    quickSort(v,pI+1,e);
}
int main(){
 vector<int> nums = {4,2,5,9,1,6,11,8,16};
    quickSort(nums, 0, nums.size()-1);
    for (auto i : nums)
        cout << i<<" ";
    return 0;
return 0;
}