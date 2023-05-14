#include<iostream>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        this->data=val;
        node*left=NULL;
        node*right=NULL;
    }
};
node*binary(node*root){
    int val;
    cout<<"enter the value in the field"<<endl;
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left node of the tree"<<endl;
    root->left=binary(root->left);
    cout<<"enter the right node of the tree"<<endl;
    root->right=binary(root->right);
    return root;
}
 void spiral(node*root){
   if(root==NULL){
       return;
   }
   stack<node*>s1;
   stack<node*>s2;
   s1.push(root);
   while(!s1.empty() || !s2.empty()){
       while(!s1.empty()){
       node*temp=s1.top();
       s1.pop();
       cout<<temp->data<<"@ ";
       if(temp->right){
           s2.push(temp->right);
       }
        if(temp->left){
           s2.push(temp->left);
       }
       }
       while(!s2.empty()){
       node*temp=s2.top();
       s2.pop();
       cout<<temp->data<<"% ";
       if(temp->right){
           s1.push(temp->right);
       }
        if(temp->left){
           s1.push(temp->left);
       }
       }
   }   
 }
int main(){
  node*root=NULL;
  root=binary(root); 
  cout<<"the spiral order traversal of the tree isas follows"<<endl;
  spiral(root); 
    return 0;
}