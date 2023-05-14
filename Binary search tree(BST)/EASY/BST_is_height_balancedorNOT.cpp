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
node *intoBST(node*root,int a){
    if(root==NULL){
        root=new node(a);
        return root;
    }
    else{
        if(a>root->data){
            root->right=intoBST(root->right,a);

        }
        if(a<root->data){
            root->left=intoBST(root->left,a);
        }
    }
    return root;
}
node *make(node*root){
    int a;
    cout<<"enter the main node val in the field"<<endl;
    cin>>a;
    while(a!=-1){
        root=intoBST(root,a);
        cout<<"enter the node val in the field->> ";
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
int max(int a,int b){
    return  (a>=b)?a:b;
}
int height(node*root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int check(node*root){
    int l,r;
    if(root==NULL){
        return 1;
    }
    l=height(root->left);
    r=height(root->right);
if(abs(l-r)<=1 && check(root->left) && check(root->right)){
    return 1;
}
return 0;
}
int main(){
    node*root=NULL;
    root=make(root);
    cout<<"the level order traversal of the tree is as follows"<<endl;
    level(root);
    if(check(root)){
        cout<<"it is a height balanced tree "<<endl;
    }
    else{
        cout<<"it is not a height balced binary tree "<<endl;
    }
    return 0;
}
 