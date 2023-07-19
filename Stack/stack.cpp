#include<iostream>

using namespace std;
class Stack{
    int top;
    int *arr;
    int size;
public:
    Stack(int size){
        this->size=size;
        top=-1;
        arr= new int[this->size];
    }
    void push(int data){
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
        cout<<this->arr[this->top]<<endl;
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
Stack st(4);
st.push(110);
st.push(120);

st.topget();
// st.pop();
// st.pop();
// st.pop();
st.pop();
st.topget();
cout<<st.empty()<<endl;


return 0;
}