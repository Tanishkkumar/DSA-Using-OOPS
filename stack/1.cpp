#include<iostream>
using namespace std;
class stack{
    public:
    int top;
    int *arr;
    int size;
    stack(int val){
        this->size=val;
        arr=new int[val];
        top=-1;
    }

    void push(int a){
        if(size-top>1){
            top++;
            arr[top]=a;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }

    }

    void pop(){
      if(top>=0){
          top--;
      }
      else{
          cout<<"stack underflow"<<endl;

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