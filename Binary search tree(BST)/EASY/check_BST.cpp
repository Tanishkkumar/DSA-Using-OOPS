#include<bits/stdc++.h>
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
// node*intoBST(node*root,int a){
//     if(root==NULL){
//         root=new node(a);
//         return root;
//     }
//     if(a>root->data){
//       root->right=intoBST(root->right,a);
//     }
//     else{
//         root->left=intoBST(root->left,a);
//     }
//     return root;
// }
node*make(node*root){
    int a;
    if(root==NULL){
    cout<<"enter the node val in the field"<<endl;
    }
    cin>>a;
    root=new node(a);
    if(a==-1){
        return NULL;
    }
    else{
        cout<<"enter the left node of-->"<<root->data<<endl;
        root->left=make(root->left);
        cout<<"enter the right node-->"<<root->data<<endl;
        root->right=make(root->right);
    }
    return root;
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
int max(node*root){
    node*ptr=root;
    while(ptr->right!=NULL){
        ptr=ptr->right;
    }
    return ptr->data;
}
int min(node*root){
    node*ptr=root;
    while(ptr->left!=NULL){
        ptr=ptr->left;
    }
    return ptr->data;
}

int check(node*root){
    if(root==NULL){
        return 1;
    }
    if(root->left!=NULL && root->left->data>root->data){
        return 0;
    }
     if(root->right!=NULL && root->right->data<root->data){
        return 0;
    }
    if(!check(root->left) || !check(root->right)){
        return 0;
    }
    return 1;
}
int main(){                
  node*root=NULL;            //50 30 20 -1 -1 40 -1 -1 70 60 -1 -1 80 -1 -1
  root=make(root);  
  cout<<"the level oreder traversal of the tree is as follows"<<endl;
  level(root);
  if(check(root)==1){
      cout<<"the tree is a binary search tree"<<endl;
  }
  else{
      cout<<"it is not a binary search tree"<<endl;
  }
    return 0;
}
