#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
        int larger=i;
        int l=2*i;
        int r=2*i+1;
        if(l<=n && arr[larger]>arr[l]){
            larger=l;
        }
        if(r<=n && arr[larger]>arr[r]){
            larger=r;
        }
        if(larger!=i){
            swap(arr[larger],arr[i]);
            heapify(arr,n,larger);
        }    
    }
    void heapsort(int arr[],int n){
        int size=n;
        while(size>1){
            swap(arr[size],arr[1]);
            size--;
            heapify(arr,size,1);
        }
    }
int main(){
    int a,b;
    int arr[]={-1,54,53,55,52,50};
    for(int i=5/2;i>0;i--){
        heapify(arr,5,i);
    }
    cout<<"the printing of heap is as follows"<<endl;
    for(int i=1;i<=5;i++){
            cout<<arr[i]<<" ";
        }
        heapsort(arr,5);
        cout<<"\nthe printing of heap after heapsort"<<endl;
    for(int i=1;i<=5;i++){
            cout<<arr[i]<<" ";
        }
        return 0;
}