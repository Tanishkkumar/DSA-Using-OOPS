#include<bits/stdc++.h>
using namespace std;
class a;

class b{
    private:
    b(){
        cout<<"b constructor"<<endl;
    }
    friend class a;
};

class a:virtual b{
    public:
    a(){
        cout<<"aconstructor"<<endl;
    }
};

class derived:public a{
    public:
    derived(){
        cout<<"derived constructor"<<endl;
    }
};
int main(){
    derived d; 
    return 0;
}