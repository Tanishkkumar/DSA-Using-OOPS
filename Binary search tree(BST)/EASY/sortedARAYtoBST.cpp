#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void level(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*ptr=q.front();
        q.pop();
        if(ptr==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<ptr->data<<" ";
            if(ptr->left){
                q.push(ptr->left);
            }
            if(ptr->right){
                q.push(ptr->right);
            }
        }
    }
}
node*ArraytoBST(int arr[],int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=(st+end)/2;
    node*ptr=new node(arr[mid]);
    ptr->left=ArraytoBST(arr,st,mid-1);
    ptr->right=ArraytoBST(arr,mid+1,end);
    return ptr;
}
int main(){
    int a;
    node*root=NULL;
    cout<<"enter the size of the array in the field"<<endl;
    cin>>a;
    int *arr=new int[a];
    cout<<"enter the array element in the field"<<endl;
    for(int i=0;i<a;i++){
        cout<<i<<"::";
        cin>>arr[i];
    }
    root=ArraytoBST(arr,0,a-1);
    cout<<"the level order traversal of the tree is as follows"<<endl;
    level(root);
    return 0;
}