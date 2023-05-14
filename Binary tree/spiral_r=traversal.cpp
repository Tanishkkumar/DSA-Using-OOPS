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
        node*left=NULL;
        node*right=NULL;
    }
};
node*binary(node*root){
    int val;
    cout<<"enter the value in the field"<<endl;
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left node of the tree"<<endl;
    root->left=binary(root->left);
    cout<<"enter the right node of the tree"<<endl;
    root->right=binary(root->right);
    return root;
}
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    if(l>r){
        return 1+l;
    }
    return 1+r;
}

void traversal(node*root,int le,int itr){
    if(root==NULL){
        return ;
    }
    if(le==1){
        cout<<root->data<<" ";
    }
    if(le>1){
        if(itr){
            traversal(root->left,le-1,itr);
            traversal(root->right,le-1,itr);
        }
        if(!itr){
            traversal(root->right,le-1,itr);
            traversal(root->left,le-1,itr);
            
        }
    }
}

void spiral(node*root){
    int a=height(root);
    bool itr=false;
    for(int i=1;i<=a;i++){
        traversal(root,i,itr);
        itr=!itr;
    }
}
int main(){
  node*root=NULL;
  root=binary(root); 
  cout<<"the spiral order traversal of the tree isas follows"<<endl;
  spiral(root); 
    return 0;
}