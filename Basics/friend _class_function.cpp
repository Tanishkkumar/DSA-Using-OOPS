#include<iostream>
using namespace std;
class am{
    int a;
    public:
    int b;
    am(){
        a=10;
        b=96;
    } 
    //friend class amp; 
};

class amp{
   public:
   void dis(am&t){
       cout<<"the value of a is::"<<t.a<<endl;
       cout<<"the value of b is::"<<t.b<<endl;
   }
};

int main(){
    am obj1;
    amp tri;
    tri.dis(obj1);
    return 0;
}