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
node*intoBST(node*root,int val){
    if(root==NULL){
        root=new node(val);
        return root;
    }
    if(val>root->data){
        root->right=intoBST(root->right,val);
    }
    else{
        root->left=intoBST(root->left,val);
    }
    return root;
}
 void make(node* &root){
     int a;
     cout<<"enter the node in the field"<<endl;
     cin>>a;

     while(a!=-1){
         root=intoBST(root,a);
         cout<<"enter the node in the field"<<endl;
         cin>>a;
     }
 }
 void lev(node*root){
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
 node*min(node*root){
     node*ptr=root;
     while(ptr->left!=NULL){
         ptr=ptr->left;
     }
     return ptr;
 }
 node*max(node*root){
     node*ptr=root;
     while(ptr->right!=NULL){
         ptr=ptr->right;
     }
     return ptr;
 }

 node*del(node*root,int val){
     if(root==NULL){
         return root;
     }
     if(root->data==val){

         //0 child
         if(root->left==NULL && root->right==NULL){
             delete root;
             return NULL;
         }
         //1 child
          if(root->left!=NULL && root->right==NULL){
             node*ptr=root->left;
             delete root;
             return ptr;
         }
          if(root->right!=NULL && root->left==NULL){
             node*ptr=root->right;
             delete root;
             return ptr;
         }
         
         //2 child
          if(root->left!=NULL && root->right!=NULL){
             int minval=min(root->right)->data;
             //cout<<"the min value is"<<minval<<endl;
             root->data=minval;
             root->right=del(root->right,minval);
             return root;
         }
     }
     else if(root->data>val){
         //go left
         root->left=del(root->left,val);
         return root;
     }
     else{
         //go right
         root->right=del(root->right,val);
         return root;
     }

 }
int main(){
    int val;
    node*root=NULL;       //50 30 70 20 40 60 80 -1
    make(root);
    cout<<"the level order traversal of the tree before deletion  is as follows"<<endl;
    lev(root);
    cout<<"enter the node u want to  delete from the tree"<<endl;
    cin>>val;
    root=del(root,val);
    cout<<"***********************\n***********************"<<endl;
    cout<<"the level order traversal of the tree after deletion is as follows"<<endl;
    lev(root);
    return 0;
}