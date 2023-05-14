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
 node*find(node*root,int val){
     if(root==NULL || root->data==val){
         return root;
     }
     if(val>root->data){
         return find(root->right,val);
     }
     return find(root->left,val);
 }
 node*inse(node*root,int val){
     if(root==NULL){
         root=new node(val);
         return root;
     }
     if(val>root->data){
         root->right=inse(root->right,val);
     }
     else{
         root->left=inse(root->left,val);
     }
     return root;  
 }
int main(){
    node*root=NULL;  //8 3 10 1 6 14 4 7 13
    int a;
    make(root);
    cout<<"the level order traversal of the tree before insertion  is as follows"<<endl;
    lev(root);
    cout<<"enter the node u want to  insert in the tree"<<endl;
    cin>>a;
    root=inse(root,a);
    cout<<"******************\n*****************"<<endl;
    cout<<"the level order traversal of the tree after insertion is as follows"<<endl;
    lev(root);
    
    

    return 0;
}