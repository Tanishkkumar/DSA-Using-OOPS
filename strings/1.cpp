#include<bits/stdc++.h>
using namespace std;
int main(){
    string arr("hello world");
    int arr1[]={1,2,3,4,5,6,7};
    cout<<arr<<endl;
    string  ptr(arr);
    cout<<ptr<<endl;
    string ctr(5,'A');
    cout<<ctr<<endl;
    string rw(arr,7,6);
    cout<<rw<<endl;
    string pt(arr.begin(),arr.begin()+7);
    cout<<pt<<endl; 
    //int len=
    cout<<"the lenth of string is:::"<<arr.length()<<endl;
    cout<<"the lenght of arrau s::::"<<sizeof(arr1)/sizeof(arr1[0])<<endl;
    const char*tr=arr.c_str();
    //cout<<"rhe fsdfs:::"<<tr;
    printf("dfdfs::::%s",tr);

    return 0;
}