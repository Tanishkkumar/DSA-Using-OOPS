#include<iostream>
using namespace std;
int main(){
    int arr[]={1,5,3,4};
    cout<<*(arr+1)<<endl;
    cout<<*arr+1<<endl;
     cout<<(*arr)+1<<endl;
    cout<<&arr[1]<<endl;
    cout<<&arr<<endl;
    cout<<1[arr]<<endl;
    int *p=arr;
    cout<<"pointer:::"<<++(*p)<<endl;
    cout<<"pointer:::"<<(*++p)<<endl; 
    cout<<"sizeof array::"<<sizeof(&arr)<<endl;
    cout<<"sizeof pointer:::"<<sizeof(p)<<endl;
    return 0;
}