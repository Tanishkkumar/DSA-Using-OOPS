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
 
int main(){
    node*root=NULL;
    int a;
    make(root);
    cout<<"the level order traversal of the tree is as follows"<<endl;
    lev(root);
    cout<<"enter the node u want to  search in the tree"<<endl;
    cin>>a;
    if(find(root,a)){
        cout<<"element founded"<<endl;
    }
    else{
        cout<<"not founded";
    }
    

    return 0;
}