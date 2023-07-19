#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
       
       vector <char> chars= {'a','a','b','b','b','b','b','b','b','b','b','b','b','b'};
      int len=1;
        vector<char> ans;
       for(int i=0;i<chars.size()-1;i++){
           if(chars[i]==chars[i+1]){
           len=len+1;
           }
           else if(chars[i]!=chars[i+1]){
                ans.push_back(chars[i]);
                if(len>1){
                char a=len;
                ans.push_back(a);
                }
                     len=1;

           }
           else if(i==chars.size()-2 &&chars[i]==chars[i+1])
           {
            ans.push_back(chars[i]);
            if(len>1)
            ans.push_back(len);

           }
       } 
       len= ans.size();
     cout<<ans<<endl;
     cout<<len;

return 0;
}