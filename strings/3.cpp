//string operations

#include<bits/stdc++.h>
using namespace std;
string flo(string ptr){
    int a=ptr.find(".");
    if(a==string::npos){
        return "";
    }
    else{
        return ptr.substr(a+1);
    }
}

bool con(string ptr){
    int a=ptr.length();
    for(int i=0;i<a;i++){
        if(ptr.at(i)<'0' || ptr.at(i)>'9'){
            return false;
        }
        
    }
    return true;
}
string repl(string ptr){
    string re="%20";
    int a=0;
    while((a=ptr.find(" ",a))!=string ::npos){
        ptr.replace(a,1,re);
        a+=re.length();
    }
    return ptr;
}
int main(){
    string fnums="23.568";
    cout<<"the floating part is :::"<<flo(fnums)<<endl;
    string num="12345e";
    if(con(num)){
        cout<<"string only comtain only number"<<endl;
    }
    else{
        cout<<"not"<<endl;
    }

    string ptr="google ceo tanishk kumar";
    cout<<repl(ptr)<<endl;

    return 0;
}