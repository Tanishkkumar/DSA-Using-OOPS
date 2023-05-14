//count the number of frequencies in the stirng.

#include<iostream>
//#include<string>
using namespace std;
void count(string arr,int *a){
    for(int i=0;i<arr.size();i++){
        //*p=arr[i];
        a[arr[i]]++;
    }
}
int main(){
    string arr;
    cout<<"enter the string in the field"<<endl;
    cin>>arr;
    int *a=new int[256]{0};  //**main
    // int a[256]={0};
    int p=0;
    count(arr,a);
    cout<<"the priting of the list is as follows"<<endl;
    for(int i=0;i<=255;i++){
        if(a[i]!=0){
            cout<<"the frequency of-> "<<char(i)<<" is--> "<<a[i]<<endl;
        }
    }
    cout<<"total number of letters are--> "<<arr.size();
    return 0;
}