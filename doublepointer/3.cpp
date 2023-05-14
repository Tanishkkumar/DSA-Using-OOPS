//pointer ans referenv=ce variable

#include<iostream>
using namespace std;
void incre(int **pt){
    ++**pt;
}

void incre1(int &pt){   //referce variable..
    ++pt;
}
int main(){
    int a=45;
    int *p=&a;
    int **q=&p;
    // int *r=*q;
     cout<<&a<<endl;
    cout<<&p<<endl;
    cout<<q<<endl;
    incre1(a);
    cout<<"new:::"<<a<<endl;
    //  cout<<a<<endl;
    return 0;
}