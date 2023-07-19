#include<iostream>
#include<string>

using namespace std;
class Stack{
    int top;
    char *arr;
    int size;
public:
    Stack(int size){
        this->size=size;
        top=-1;
        arr= new char[this->size];
    }
    void push(char data){
        if(this->top==this->size-1)
        cout<<"Stackoverflow"<<endl;
        else{
        this->top++;
        this->arr[this->top]=data;
        }
    }
    void pop(){
           if(this->top==-1)
        cout<<"Stack underflow"<<endl;
        else{
        cout<<this->arr[this->top];
        this->top--;
        }
    }
    int empty(){
           if(this->top==-1){
            cout<<"Stack Empty"<<endl;
            return 0;
           }
        else{
        cout<<"Stack Not Empty"<<endl;
        }
        return 1;
    }
    void topget(){
           if(this->top==-1)
        cout<<"Stack underflow"<<endl;
        else{
        cout<<this->arr[this->top]<<endl;
        }
    }
};
int main(){
Stack st(10);

string ans;
cin>>ans;

for(auto i:ans)
st.push(i);
for(int i=0;i<ans.length();i++)
st.pop();


return 0;
}