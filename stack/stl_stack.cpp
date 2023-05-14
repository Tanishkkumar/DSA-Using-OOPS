#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>ctr;
    stack<int>ptr;
    ptr.push(21);
    ptr.push(22);
    ptr.push(23);
    ptr.push(24);
    ptr.push(35);

    ctr.push(23);
    ctr.push(21);
    ctr.push(24);
    ctr.push(35);
    ctr.push(22);
    ctr.swap(ptr);
    cout<<"the size is:"<<ptr.size()<<endl;
    cout<<"the size is ctr:"<<ctr.size()<<endl;
       while(ptr.empty()!=true){
            //cout<<"the top element is:"<<ptr.top()<<endl;
           cout<<ptr.top()<<" ";
           ptr.pop();
       }
    return 0;
}