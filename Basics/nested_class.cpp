#include<bits/stdc++.h>
using namespace std;
class a{
    int a1=36;
    class nested{
        int a2=85;
        void nest(a*p){
            cout<<"the value of a1 through nested class is s follows::::"<<p->a1<<endl;
        }
    };
    // void emp(nested*p){
    //      cout<<"the value of a1 through nested class is s follows::::"<<p->a2<<endl; ///this will show error
    // }
};
int main(){
    a ob;
    ob.nest();
    
    
    return 0;
}