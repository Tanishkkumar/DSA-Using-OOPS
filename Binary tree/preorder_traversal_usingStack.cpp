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
void preorderusingStack(node*root){                 //time complexity--->>O(n)..
    stack<node*>s;
   s.push(root);
   node*temp;
   while(!s.empty()){
       temp=s.top();
       s.pop();
       cout<<temp->data<<" ";
       if(temp->right){
           s.push(temp->right);
       }
        if(temp->left){
           s.push(temp->left);
       }
   }
    
}

int main(){
    node*root=NULL;
    root=make(root); 
    cout<<"the reverse traversal of the tree is as follows"<<endl;
    preorderusingStack(root); 
    return 0;
}