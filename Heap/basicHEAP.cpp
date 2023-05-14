#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val; 
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
     void delheap(){
       arr[1]=arr[size];
         size--;
         int i=1;
         while(i<size){
         int l=2*i;
         int r=2*i+1;
         if(l<=size && arr[i]<arr[l] && arr[l]>=arr[r]){
             swap(arr[l],arr[i]);
             i=l;
         }
         else if(r<=size && arr[i]<arr[r] && arr[r]>=arr[l]){
             swap(arr[r],arr[i]);
             i=r;
         }

         else{
             return ;
         }
         }

    }
};    
int main(){
    heap h;
    int a;
    for(int i=0;i<9;i++){
        cout<<"enter the "<<i<<" element---> ";
        cin>>a;
        h.insert(a);
    }
    cout<<"the max heap in array is as follows"<<endl;
    h.print();
    cout<<"\nheap after deltion is"<<endl;
    h.delheap();
    h.print();

    return 0;
}