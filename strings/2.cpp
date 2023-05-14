#include<bits/stdc++.h>
using namespace std;
int main(){
    string  arr="tanishk kumar oraab";
    // for(int i=0,j=arr.length()-1;i<arr.length()/2;i++,j--){
    //     swap(arr[i],arr[j]);
    // }
    // reverse(arr.begin(),arr.end());
    
    // cout<<"the revrse array is as follows\n";
    // cout<<arr;
    // arr.append(" oraab");
    // cout<<endl<<arr;
   string ptr="oraab";
  // int a=arr.find(ptr);
  // cout<<a;
    if(arr.find(ptr)!=-1){
        cout<<"ptr is ounded at::"<<arr.find(ptr)<<"th position"<<endl;

    }
    else{
        cout<<"not founded";
    }
   cout<<arr.length();
  cout<<arr.erase(8,6)<<endl;
  cout<<arr.length();

    
    return 0;
}