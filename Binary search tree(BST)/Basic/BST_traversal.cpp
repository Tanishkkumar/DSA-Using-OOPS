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
node*insert(node*root,int val){
    if(root==NULL){
        root=new node(val);
        return root;
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    else{
        root->left=insert(root->left,val);
    }
    return root;
}
node *make(node*root){
    int a;
    cout<<"enter the value in the field"<<endl;
    cin>>a;
    while(a!=-1){
        root=insert(root,a);
        cout<<"enter the value in the field"<<endl;
        cin>>a;
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
void in(node*root){
    if(root==NULL){
        return ;
    }
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}
void pre(node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
void post(node*root){
    if(root==NULL){
        return ;
    }
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}
int main(){
    int val;
    node*root=NULL;
    root=make(root);
    cout<<"the level order traversal of the tree is as follows"<<endl;
    level(root);
    cout<<"\nthe inorder traversal of the tree is as follows"<<endl;
    in(root);
    cout<<"\nthe preorder traversal of the tree is as follows"<<endl;
    pre(root);
    cout<<"\nthe postorder traversal of the tree is as follows"<<endl;
    post(root);
    return 0;
}