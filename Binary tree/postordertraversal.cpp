#include<iostream>
#include<stack>
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
node*make(node*root){
    int val;
    cout<<"enter the value in the field"<<endl;            
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left child of->>"<<val<<endl;
    root->left=make(root->left);
     cout<<"enter the right child of->>"<<val<<endl;
    root->right=make(root->right);
    return root;
}
void post(node*root){
  if(root==NULL){
      return ;
  }
  post(root->left);
  post(root->right);
  cout<<root->data<<" ";
}
void level(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    node*temp;
    while(!q.empty()){
        temp=q.front();
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



int main(){
    node*root=NULL;
    root=make(root); 
    cout<<"the level order traversal of the tree is as follows "<<endl;
    level(root);
    cout<<"\nthe post order  traversal of the tree is as follows"<<endl;
    post(root); 
    return 0;
}