#include<iostream>
using namespace std;
int main(){
    // string ch="fdscscs";
    // string *c=&ch;
    // cout<<"sizeof charcter::"<<sizeof(ch)<<endl;
    // cout<<"sizeof pointer:::"<<sizeof(c)<<endl;

    int *arr=new int[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    cout<<"printing of array is as follows:::"<<endl;
     for(int i=0;i<5;i++){
       cout<<arr[i]<<" ";
    }
    delete []arr;
    return 0;
}