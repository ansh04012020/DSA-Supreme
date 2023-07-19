#include<iostream>

using namespace std;
class Stack{
    int top1;
    int top2;
    int *arr;
    int size;
public:
    Stack(int size){
        this->size=size;
        top1=-1;
        top2=this->size;
        arr= new int[this->size]{0};
    }
    void push1(int data){
        if(this->top1==this->size-1)
        cout<<"Stackoverflow 1"<<endl;
        else{
        this->top1++;
        this->arr[this->top1]=data;
        }
    }
    void pop1(){
           if(this->top1==-1)
        cout<<"Stack underflow 1"<<endl;
        else{
        cout<<this->arr[this->top1]<<endl;
        this->top1--;
        }
    }
    int empty1(){
           if(this->top1==-1){
            cout<<"Stack Empty 1"<<endl;
            return 0;
           }
        else{
        cout<<"Stack Not Empty 1"<<endl;
        }
        return 1;
    }
    void topget1(){
           if(this->top1==-1)
        cout<<"Stack underflow 1"<<endl;
        else{
        cout<<this->arr[this->top1]<<endl;
        }
    }

   void push2(int data){
        if(this->top2==this->top1+1)
        cout<<"Stackoverflow 2"<<endl;
        else{
        this->top2--;
        this->arr[this->top2]=data;
        }
    }
    void pop2(){
        if(this->top2==size)
        cout<<"Stack underflow 2"<<endl;
        else{
        cout<<this->arr[this->top2]<<endl;
        this->top2++;
        }
    }
    int empty2(){
           if(this->top2==size){
            cout<<"Stack Empty 2 "<<endl;
            return 0;
           }
        else{
        cout<<"Stack Not Empty 2"<<endl;
        }
        return 1;
    }
    void topget2(){
           if(this->top2==size)
        cout<<"Stack underflow 2"<<endl;
        else{
        cout<<this->arr[this->top2]<<endl;
        }
    }

    void print(){
        for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    }
};
int main(){
Stack st(3);
st.push1(110);
st.push1(120);
// st.topget1();
// st.pop1();
// st.topget1();
// cout<<st.empty1()<<endl;

cout<<"------------------------"<<endl;

st.push2(130);
st.push2(140);
// st.topget2();
// st.pop2();
// st.topget2();
// cout<<st.empty2()<<endl;

st.print();

return 0;
}