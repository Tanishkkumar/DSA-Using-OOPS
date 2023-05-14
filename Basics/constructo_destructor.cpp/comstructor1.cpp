// #include<iostream>
// using namespace std;
// class a{
//     int a1;
//     public:
//     a();
//    void pri(){
//        cout<<"the value of a is as follows::"<<a1;
//    }
// };
// a::a(){
//     cout<<"enter the value of a in the field\n";
//     cin>>a1;
// }
// int main(){
//     a ob;
//     ob.pri();
    
//     return 0;
// }




#include<iostream>
using namespace std;
class a{
    int a1;
    public:
    a(int a2);
   void pri(){
       cout<<"the value of a is as follows::"<<a1;
   }
};
a::a(int a2){
    //cout<<"enter the value of a in the field\n";
    a1=a2;;
}
int main(){
    a ob(85);
    ob.pri();
    
    return 0;
}