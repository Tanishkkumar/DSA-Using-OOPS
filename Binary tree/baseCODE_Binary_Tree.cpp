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
int main(){
    node*root=NULL;
    root=makeNODE(root);
    return 0;
}