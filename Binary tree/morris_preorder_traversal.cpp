#include<iostream>
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
    int val;
    cout<<"\nenter the value in the field"<<endl;
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left node of--->"<<val;
    root->left=make(root->left);
    cout<<"enter the right node of--->"<<val;
    root->right=make(root->right);
    return root;
}

void inOrder(node*root){
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void morris(node*root){
    node*cu,*pre;
    while(root==NULL){
        return ;
    }
    cu=root;
    while(cu!=NULL){
        if(cu->left==NULL){
            cout<<cu->data<<" ";
            cu=cu->right;
        }
        else{
            pre=cu->left;
            while(pre->left!=NULL && pre->right!=cu){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=cu;
                cu=cu->left;
            }
            else{
                pre=pre->right;
                cout<<cu->data<<" ";
                cu=cu->right;
            }
        }
    }
}
void pre(node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
int main(){
    node*root=NULL;
    root=make(root);
    // cout<<"the inorder traversal using recursion is as follows\n";
    // inOrder(root);
    // cout<<"\nThe Morris traversal is as follows"<<endl;
    // morris(root);
    cout<<"the preorder treversal of the tree is as follows"<<endl;
    pre(root);
    
    return 0;
}