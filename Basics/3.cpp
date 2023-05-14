#include<iostream>
using namespace std;
class parent{
    public:
    int a;
};
class child:public parent{
      public:
      int b;
};
int main(){
   child obj1;
   obj1.b=78;
   obj1.a=1;
   cout<<obj1.b+obj1.a;
   return 0;
}