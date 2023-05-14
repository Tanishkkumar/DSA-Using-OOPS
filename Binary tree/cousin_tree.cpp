#include<iostream>
#include<queue>
#include<stack>
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
node*makeNODE(node*root){
    int a;
    cout<<"enter the root node\n";
    cin>>a;
    root=new node(a);
    if(a==-1){
        return NULL;
    }
    else{
      cout<<"enter the left node of->>"<<a<<endl;
      root->left=makeNODE(root->left);
      cout<<"enter the right node of->>"<<a<<endl;
      root->right=makeNODE(root->right);
    }
    return root;
}
int isSibling(node*root,node*a,node*b){
  if(root==NULL){
      return 0;
  }
  if(root->right==a && root->left==b){
      return 1;
  }
  if(root->right==b && root->left==a){
      return 1;
  }
  isSibling(root->left,a,b);
  isSibling(root->right,a,b);
}
int level(node*root,node*a,int pt){
    if(root==NULL){
        return 0;
    }
    if(root==a){
        return pt;
    }
    int l=level(root->left,a,pt+1);
    if(l!=0){
        return l;
    }
    return level(root->right,a,pt+1);
}
int isCousin(node*root,node*a,node*b){
    if((level(root,a,1)==level(root,b,1)) && !(isSibling(root,a,b))){
        return 1;
    }
    return 0;
}
int main(){
    node*root=NULL;
    root=makeNODE(root);  //// 4 5 7 -1 -1 8 -1 -1 10 -1 2 -1 -1;
    node*a=root->left->right;
    node*b=root->right->right;
    if(isCousin(root,a,b)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
    return 0;
}