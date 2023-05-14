#include<bits/stdc++.h>
using namespace std;
class am{
    int a;
    public:
    void get(int a){
      this->a=a;
    }
    void pri();
};
void am::pri(){
    cout<<"the value if a is as follows:::"<<a<<endl;
}
int main(){
    int a=10;
    am obj;
    obj.get(a);
    obj.pri();
    return 0;

}