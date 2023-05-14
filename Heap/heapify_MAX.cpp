#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
    int larger=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[larger]<arr[left]){
        larger=left;
    }
    if(right<=n && arr[larger]<arr[right]){
        larger=right;
    }
    if(larger!=i){
        swap(arr[larger],arr[i]);
        heapify(arr,n,larger);
    }
}
int main(){
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"the printing of array after max heap"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}