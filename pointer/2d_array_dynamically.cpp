#include<iostream>
using namespace std;
int main(){
    int **arr=new int*[3];
    for(int i=0;i<3;i++){
        arr[i]=new int[2];
    }
    cout<<"enter the array element in the field"<<endl;
     for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
     cout<<"enter the array element in the field"<<endl;
     for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


   //free up the array 
    for(int i=0;i<3;i++){
        delete []arr[i];
    }
    delete []arr;
    return 0;
}