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
node*make(node*root){
    int a;
    cout<<"enter the node val"<<endl;
    cin>>a;
    while(a!=-1){
        root=intoBST(root,a);
        cout<<"enter the node val"<<endl;
        cin>>a;
    }
    return root;
}
void inorder(node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int find(node*root,int val){
    while(root!=NULL){
        if(val>root->data){
            root=root->right;
        }
        else if(val<root->data){
            root=root->left;
        }
        else{
            return 1;
        }
    }
    return 0;
}
node*max(node*root){
    node*ptr=root;
    while(ptr->right!=NULL){
        ptr=ptr->right;
    }
    return ptr;
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
int main(){
  node*root=NULL;
  root=make(root);        //50 30 70 20 40 60 80 -1
  int b;  
  cout<<"the inorder traversal of the tree is as follows"<<endl;
  inorder(root);
  cout<<"\nthe level order traversal of the tree is as follows"<<endl;
  lev(root);
  cout<<"\nenter the value u want to search in the tree"<<endl;
  cin>>b;
  int r=find(root,b);
  cout<<"the value of r is::"<<r<<endl;
  if(r==1){
      cout<<"founded"<<endl;
  }
  else{
      cout<<"not founded"<<endl;
  }
  cout<<"the max value is"<<max(root)->data;
    return 0;
}