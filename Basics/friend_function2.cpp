#include<iostream>
using namespace std;
class pt;
class am{
    int a;
    public:
    void set(int a1){
        a=a1;
    }  
    friend void max(am,pt);
};
class pt{
    int x;
    public:
    void set(int a2){
        x=a2;
    }
    friend void max(am,pt);

};

void max(am q,pt bt){
    cout<<"the first is::"<<q.a<<"\nthe second is:::"<<bt.x<<endl;
}
int main(){
    am ob1;
    pt ob2;
    ob1.set(98);
    ob2.set(12);
    max(ob1,ob2);
    return 0;
}