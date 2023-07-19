#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &v,int i,int sum){
int maxi=INT_MIN;

if(i>=v.size())
return sum ;
//EXCLUDE
int ans1=solve(v,i+1,sum);
//INCLUDE
int ans2=solve(v,i+2,sum+v[i]);

maxi=max(ans1,ans2);
// maxi=max(maxi,ans2);


return maxi;

}
int main(){
vector <int> nums={4,2,3,5,9}; 

cout<<solve(nums,0,0);
return 0;
}