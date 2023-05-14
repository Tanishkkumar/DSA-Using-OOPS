#include<iostream>
using namespace std;
class am;
class ba{
    public:
    // void pri(am& t){
    //      cout<<"the value of a is::"<<t.a<<endl;
    //      cout<<"the value of b is::"<<t.b<<endl;
    // }
    void pri(am&t);
};
class am{
    int a;
    protected:
    int b;
    public:
     am(){
        a=85;
        b=96;
    }
    friend void ba:: pri(am&t);
};
void ba::pri(am&t){
    cout<<"the value of a is::"<<t.a<<endl;
         cout<<"the value of b is::"<<t.b<<endl;
}


int main(){
    am ob;
    ba re;
    re.pri(ob);
    return 0;
}