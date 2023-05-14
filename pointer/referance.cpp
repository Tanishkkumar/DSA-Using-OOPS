#include<bits/stdc++.h>
using namespace std;
void fun(int &a){
    a=96325;    
}
int main(){
  cout<<"hello world"<<endl;
  int a=10;
  int &b=a;
  b=100;
  a=5;
  cout<<b;
  int arr=100;
  fun(arr);
  cout<<"\nthe value of ar is::"<<arr<<endl;


  vector<int>v1{1,2,5,4,7,8};

  for(int& x:v1){
   x=x+5;
  }

  for(int x:v1){
   cout<<x<<endl;
  }
  vector<string>arr1{"hello every one","this is tanishk kumar","fron planet earth"};
  for(const auto& x:arr1){
      cout<<x<<endl;
  }

  return 0;
}