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
    cout<<"enter the value in the field"<<endl;              //TIME COMPLEXITY---->O(n^2).  ->>>recursive approch.
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
void inorderusingStack(node*root){              //time complexity--->>O(n)..
    stack<node*>s;
    node*temp=root;
    while(temp!=NULL || !s.empty()){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}

int main(){
    node*root=NULL;
    root=make(root); 
    cout<<"the reverse traversal of the tree is as follows"<<endl;
    inorderusingStack(root); 
    return 0;
}