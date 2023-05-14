#include<iostream>
using namespace std;
class a{
    int age;
    char name[50];
    float salary;
    public:
    a(){
        cout<<"enter the age in teh feield"<<endl;
        cin>>age;
        
        //getline(cin,name);
        cout<<"enter the salary in teh feield"<<endl;
        cin>>salary;
        cout<<"enter the name in teh feield"<<endl;
        cin>>name;
    }
    void pri();
};

void a::pri(){
    cout<<"the name is::"<<name<<"\nthe age is::"<<age<<"\nthe slary is:::"<<salary;
}
int main(){
    a obj;
    obj.pri();
}