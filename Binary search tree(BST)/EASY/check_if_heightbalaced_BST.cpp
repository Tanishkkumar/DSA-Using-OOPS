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
node* make(node*root){
    int a;
    if(root==NULL){
        cout<<"enter the root value in the field"<<endl;
        cin>>a;
    }
    root=new node(a);
    if(a==-1){
        return NULL ;
    }
    else{
    cout<<"enter the left node of "<<a<<endl;
    root->left=make(root->left);
    cout<<"enter the right node of "<<a<<endl;
    root->right=make(root->right);
    }
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
int maxht(node*root,int pt){
    if(root==NULL){
        return 0;
    }
    int lh=maxht(root->left,pt++);
    int rh=maxht(root->right,pt++);
    if(lh>rh){
        return 1+lh;
    }
    else{
        return 1+rh;
    }
}
bool bal(node*root){
    int lh,rh;
    if(root==NULL){
        return 1;
    }
    lh=maxht(root->left,0);
    rh=maxht(root->right,0);
    if(abs(lh-rh)<=1 && bal(root->left) && bal(root->right)){
        return 1;
    }
    return 0;
}
int main(){
  node*root=NULL;  //50 30 20 -1 -1 40 -1 -1 70 60 -1 -1 80 -1 -1
  root=make(root); 
  cout<<"the level order traversal of the tree is"<<endl;
  level(root); 
  cout<<"the max height of the tree is--> "<<maxht(root,0)<<endl; 
  if(bal(root)){
      cout<<"the tree height balanced"<<endl;
  }
  else{
      cout<<"Not";
  }
    return 0;
}