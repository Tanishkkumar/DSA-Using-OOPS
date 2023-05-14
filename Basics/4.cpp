#include<iostream>
using namespace std;
class a{

};

class ch:a{
    
};

class cha:virtual ch{
    
};
int main(){
    cout<<sizeof(cha);
    return 0;
}