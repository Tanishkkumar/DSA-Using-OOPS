#include<iostream>
#include<map> 
#include<unordered_map>
using namespace std;
int main(){
   unordered_map<string,int>arr;
   arr["tanishk"]=1;
   arr["oraab"]=5;
   arr["ranger"]=3;
   arr["harhar"]=6;
   //arr["tanishk"]=999;
   for(auto &pr:arr){
       cout<<pr.first<<" "<<pr.second<<endl;
          }
    return 0;
}