#include<iostream>
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
node*make(node*root){
    int val;
    cout<<"enter the value in the field"<<endl;              //TIME COMPLEXITY---->O(n^2).  ->>>recursive approch.
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left child of->>"<<val<<endl;
    root->left=make(root->left);
     cout<<"enter the right child of->>"<<val<<endl;
    root->right=make(root->right);
    return root;
}
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    if(l>r){
        return l+1;
    }
    return r+1;
}
void spi(node*root,int i){
    if(root==NULL){
        return ;
    }
    if(i==1){
        cout<<root->data<<" ";
    }
    if(i>1){
        spi(root->left,i-1);
        spi(root->right,i-1);
    }
}

void reverse(node*root){
    int h=height(root);
    for(int i=h;i>=1;i--){
        spi(root,i);
    }
}
int main(){
    node*root=NULL;
    root=make(root); 
    cout<<"the reverse traversal of the tree is as follows"<<endl;
    reverse(root); 
    return 0;
}