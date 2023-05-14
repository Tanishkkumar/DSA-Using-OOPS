#include<iostream>
using namespace std;
class stack{
    public:
    int top1;
    top2;
    int *arr;
    int size;
    stack(int val){
        this->size=val;
        arr=new int[val];
        top1=-1;
        top2=val;
    }

    void push1(int a){
        if(top2-top1>1){
            top++;
            arr[top]=a;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }

    }
    void push2(int a){
        if(top2-top1>1){
            top2--;
            arr[top2]=a;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }

    }

   int pop1(){
      if(top>=0){
          int ans=arr[top1];
          top--;
          return ans;
      }
      else{
          return -1;

      }
    }

    int  pop2(){
      if(top2<size){
          int ans=arr[top2];
          top++;
          return ans;
      }
      else{
          return -1;

      }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }

    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }

    }
};
int main(){
    stack st(5);
    st.push(12);
    st.push(16);
    st.push(19);
    st.push(52);
    st.push(1996);
    st.push(1);
    cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    if(st.isEmpty()){
        cout<<"EMPTY"<<endl;

    }
    else{
        cout<<"not empty"<<endl;
    }
    
    return 0;
}