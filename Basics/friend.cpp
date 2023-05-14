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
    friend class amp;
    friend void fun(am&pr); 
};

class amp{
   public:
   void dis(am&t){
       cout<<"the value of a is::"<<t.a<<endl;
       cout<<"the value of b is::"<<t.b<<endl;
   }
};
void fun(am &pr){
       cout<<"the value of a in fun is::"<<pr.a<<endl;
       cout<<"the value of b in fun is::"<<pr.b<<endl;
}

int main(){
    am obj1;
    amp tri;
    tri.dis(obj1);
    fun(obj1);
    return 0;
}