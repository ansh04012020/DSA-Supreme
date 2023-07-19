#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &v,int target){
int mini=INT_MAX;
if(target==0)
return 0;
if(target<0)
return INT_MAX;

for(int i=0;i<v.size();i++){
    
   int ans=solve(v,target-v[i]);
    if(ans!=INT_MAX)
    mini=min(mini,ans+1);
  
}
return mini;
}
int main(){
vector <int> nums={1,2,3}; 
int target=7;
cout<<solve(nums,target);
return 0;
}