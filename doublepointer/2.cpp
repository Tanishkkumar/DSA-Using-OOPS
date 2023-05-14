#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    char pr[]="hello";
    cout<<arr<<endl;
    cout<<pr<<endl;
    char *c=pr;
    cout<<c<<endl;
    char a='t';
    char *r=&a;
   // cout<< r <<endl;77 
    return 0;
}