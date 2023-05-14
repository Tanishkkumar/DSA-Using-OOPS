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
node*insert(node*root){
    int val;
    cout<<"enter the data in the field"<<endl;
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left node of->"<<val<<endl;
    root->left=insert(root->left);

    cout<<"enter the right node of->"<<val<<endl;
    root->right=insert(root->right);
    return root;
}

void level(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void in(node*root){
    if(root==NULL){
        return;
    }
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}

void pre(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

void post(node*root){
    if(root==NULL){
        return;
    }
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}
int main(){
  node*root=NULL;
  root=insert(root);  
  cout<<"the level ordr traversal is as follows:::"<<endl;
  level(root);
  cout<<"the inorder traversal is as follows:::"<<endl;
  in(root);
   cout<<"\nthe pre traversal is as follows:::"<<endl;
  pre(root);
   cout<<"\nthe post traversal is as follows:::"<<endl;
  post(root);
    return 0;
}