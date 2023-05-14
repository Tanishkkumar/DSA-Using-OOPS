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
node*make(node*root){
    int a;
    cout<<"enter the root node\n";
    cin>>a;
    root=new node(a);
    if(a==-1){
        return NULL;
    }
    else{
      cout<<"enter the left node of->>"<<a<<endl;
      root->left=make(root->left);
      cout<<"enter the right node of->>"<<a<<endl;
      root->right=make(root->right);
    }
    return root;
}
int sibling(node*root,node*a,node*b){
    if(root==NULL){
        return 0;
    }
    if(root->left==a && root->right==b){
        return 1;
    }
    if(root->left==b && root->right==a){
        return 1;
    }
    sibling(root->left,a,b);
    sibling(root->right,a,b);
    //return ((root->left==a && root->right==b) || (root->left==b && root->right==a)||sibling(root->left,a,b) || sibling(root->right,a,b));
}
int level(node*root,node*ptr,int a){
    if(root==NULL){
        return 0;
    }
    if(root==ptr){
        return a;
    }
    int l=level(root->left,ptr,a+1);
    if(l!=0){
        return l;
    }
    return level(root->right,ptr,a+1);
}
int cousin(node*root,node*a,node*b){
    if((level(root,a,1)==level(root,b,1)) && !(sibling(root,a,b))){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    node*root=NULL;
    root=make(root);    // 4 5 7 -1 -1 8 -1 -1 10 -1 2 -1 -1;
    node*a=root->left->right;
    node*b=root->right->right;
    //cout<<a->data<<endl<<b->data<<endl;
    if(cousin(root,a,b)){
        cout<<"yes"<<endl;
    }
    else{
    cout<<"No"<<endl;
    }
    return 0;
}