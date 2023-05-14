#include<bits\stdc++.h>
using namespace std;
void fun(){
   

   class a{
       public:
       int a1=78;
       void pri(){
           cout<<"hello this is local class"<<endl;
           cout<<"the value of x is as follows::::"<<a1<<endl;
       }

   };
   class b{
       public:
       //a tr;
       void tri(a&tr){
           cout<<"the value in of second local class:::\n"<<tr.a1;
       }
   };
   a tr;
   b pr;
   pr.tri(tr);
   


}
int main(){
    fun();
    return 0;
}
