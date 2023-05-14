#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int>m;
    m["first"]=1;
    m["third"]=3;
    m["second"]=2;
    map<string,int>::iterator it;  //iterator ot print
    for(it=m.begin();it!=m.end();++it){
        cout<<(*it).first<<":::"<<(*it).second<<endl;
    }
    cout<<"\nSecond way to print"<<endl;
    
     for(it=m.begin();it!=m.end();++it){
        cout<<it->first<<":::"<<it->second<<endl;
    }

    cout<<"\nWithout using of iterator---here we dont have to include line 8 for iterator"<<endl;
    for(auto &pr:m){
        cout<<pr.first<<":::"<<pr.second<<endl;
    }
    return 0;
}