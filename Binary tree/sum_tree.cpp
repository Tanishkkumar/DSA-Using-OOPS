#include<iostream>
#include<queue>
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
node*in(node*root){
    int da;
    cout<<"enter the node val"<<endl;
    cin>>da;
    root=new node(da);
    //node*temp=root;
    if(da==-1){
        return NULL;
    }
     cout<<"enter the left node of->"<<da<<endl;
    root->left=in(root->left);

    cout<<"enter the right node of->"<<da<<endl;
    root->right=in(root->right);
    return root;

}
int sum(node*root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left)+root->data+sum(root->right);

} 
int sumto(node*root){
    if(root==NULL || root->left==NULL && root->right==NULL){
       return 1;
    }
    int l=sum(root->left);
    int r=sum(root->right);
    cout<<"the sum is-->"<<l+r<<endl;
    if(root->data==l+r){
        return 1;
    }
    return 0;
}



int main(){
    node*root=NULL;
    root=in(root);
    cout<<"the sumtree is as follows"<<endl;
    int t=sumto(root);
    if(t==1){
        cout<<"the tree is a sum tree"<<endl;
    }
    else{
        cout<<"the tree is  not a sum tree"<<endl;
    }
    return 0;
}