#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,string>m;
    m[1]="hello";
    m[3]="tanishk";
    m[2]="oraab";
    map<int,string>::iterator it;  //iterator ot print
    for(it=m.begin();it!=m.end();++it){
        cout<<(*it).first<<":::"<<(*it).second<<endl;
    }
    cout<<"\nSecond way to print"<<endl;
    
     for(it=m.begin();it!=m.end();++it){
        cout<<it->first<<":::"<<it->second<<endl;
    }
    
    return 0;
}