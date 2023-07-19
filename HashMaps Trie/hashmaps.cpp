#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    // unordered_map<char ,int>mp;
   map<char ,int>mp;
    
 

   string s="thrivananthapuram";

 for(int i=0;i<s.length();i++){
    
   mp[s[i]]++;

 }

 for(auto i:mp){
    cout<<i.first<<" "<<i.second<<endl;
 }
    return 0;
}