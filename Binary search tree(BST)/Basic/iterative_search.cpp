#include<bits/stdc++.h>
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
node*insert(node*root,int val){
    if(root==NULL){
        root=new node(val);
        return root;
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    else{
        root->left=insert(root->left,val);
    }
    return root;
}
node *make(node*root){
    int a;
    cout<<"enter the value in the field"<<endl;
    cin>>a;
    while(a!=-1){
        root=insert(root,a);
        cout<<"enter the value in the field"<<endl;
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
int main(){
    int val,a;
    node*root=NULL;
    root=make(root);
    cout<<"the level order traversal of the tree is as follows"<<endl;
    level(root);
    cout<<"enter the node u want to search in the list"<<endl;
    cin>>a;
    int u=find(root,a);
    if(u){
        cout<<"founded"<<endl;
    }
    else{
        cout<<"not founded"<<endl;
    }
    

    
    return 0;
}