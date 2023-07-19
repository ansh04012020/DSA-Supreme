#include<iostream>
#include<vector>
#include<string>
using namespace std;
void genPar(vector<string> &ans,string &temp,int open,int close){

    if(open==0 && close==0){
        ans.push_back(temp);
        return;
    }

    //include open

    if(open>0){
        open--;
        temp.push_back('(');
        genPar(ans,temp,open,close);
        open=open+1;
        temp.pop_back();

    }
    if(close>open){
        close--;
        temp.push_back(')');
        genPar(ans,temp,open,close);
        close=close+1;
        temp.pop_back();

    }

}
int main(){
int n=3;
// cin>>n;
int open=n,close=n;
vector<string> ans;
string temp;
genPar(ans,temp, open,close);

for(auto i:ans)
cout<<i<<endl;
return 0;
}