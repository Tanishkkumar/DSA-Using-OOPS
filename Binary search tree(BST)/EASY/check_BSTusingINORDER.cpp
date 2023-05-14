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
        cout<<"enter the left node of-->"<<a<<endl;
        root->left=make(root->left);
        cout<<"enter the right node of-->"<<a<<endl;
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

// ************WITHOUT INORDER***********
// int checkBST(node*root){    
//     if(root==NULL){
//         return 1;
//     }
//     if(root->left!=NULL && root->left->data>root->data){
//         return 0;
//     }
//     if(root->right!=NULL && root->right->data<root->data){
//         return 0;
//     }
//     if(!checkBST(root->left) || !checkBST(root->right)){
//         return 0;
//     }
//     return 1;
// }  

// ************USING INORDER***********
int checkBST(node*root,node*&pre){
   if(root!=NULL){
       if(!checkBST(root->left,pre)){
           return 0;
       }
       if(pre!=NULL && root->data<=pre->data){
           return 0;
       }
       pre=root;
       if(!checkBST(root->right,pre)){
           return 0;
       }
   }
   return 1;
}

int main(){
  node*root=NULL;  //50 30 20 -1 -1 40 -1 -1 70 60 -1 -1 80 -1 -1
  root=make(root);
  node*pre=NULL;
  cout<<"the level order traveersal is as follows:"<<endl;
  level(root);
  if(checkBST(root,pre)){
      cout<<"the tree is BST"<<endl;
  }
  else{
      cout<<"the tree is NOT a BST"<<endl;
  }
    return 0;
}