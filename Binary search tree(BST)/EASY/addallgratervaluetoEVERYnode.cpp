#include<iostream>
#include<vector>
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
node*intoBST(node*root,int a){
    if(root==NULL){
        root=new node(a);
        return root;
    }
    else{
        if(a>root->data){
            root->right=intoBST(root->right,a);
        }
        else{
            root->left=intoBST(root->left,a);
        }
    }
    return root;
}
node*make(node*root){
    int a;
    cout<<"enter the main  root val in the field"<<endl;
    cin>>a;
    while(a!=-1){
        root=intoBST(root,a);
        cout<<"enter the root val in the field---> ";
        cin>>a;
    }
    return root;
}
void inorder(node*root,vector<int>&arr){
    if(root==NULL){
        return ;
    }
    else{
        inorder(root->left,arr);
        cout<<root->data<<" ";
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
}
void adin(node*&root,vector<int>&arr,int *size,int *p){
    if(root==NULL){
      *p=*p+arr[*size];
      (*size)--;
      return ;
    }
    else{
     adin(root->right,arr,size,p);
     root->data=*p;
     adin(root->left,arr,size,p);
    }
}
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
int main(){
    int a=0;    //50 30 70 20 40 60 80 -1
    node*root=NULL;
    vector<int>arr;
    root=make(root);
    cout<<"the inorde traversal before addin is---> "<<endl;
    inorder(root,arr);
    int si=arr.size()-1;
    adin(root,arr,&si,&a);
    cout<<"\nthe level traversal After addin is---> "<<endl;
    level(root);
    return 0;
}