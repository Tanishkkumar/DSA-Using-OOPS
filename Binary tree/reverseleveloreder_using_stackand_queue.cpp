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
node*make(node*root){
    int val;
    cout<<"enter the value in the field"<<endl;              //TIME COMPLEXITY---->O(n).  ->>>recursive approch.
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
void reverse(node*root){                //Time complexity->>>>O(n)..
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        s.push(root);
        if(root->right){
            q.push(root->right);
        }
        if(root->left){
            q.push(root->left);
        }
    }
    while(!s.empty()){
        root=s.top();
        cout<<root->data<<" ";
        s.pop();
    }

}
int main(){
    node*root=NULL;
    root=make(root); 
    cout<<"the reverse traversal of the tree is as follows"<<endl;
    reverse(root); 
    return 0;
}