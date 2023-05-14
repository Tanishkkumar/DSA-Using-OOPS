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
void in(node*root,vector<int>&a){
    if(root==NULL){
        return ;
    }
    in(root->left,a);
    a.push_back(root->data);
    in(root->right,a);
}
node*toBST(int s,int e,vector<int>&a){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node*root=new node(a[mid]);
    root->left=toBST(s,mid-1,a);
    root->right=toBST(mid+1,e,a);
    return root;
}
node*bal(node*root){
    vector<int>vec;
    in(root,vec);
    return toBST(0,vec.size()-1,vec);
}
void intraversal(node*root){
    if(root==NULL){
        return ;
    }
    intraversal(root->left);
    cout<<root->data<<" ";
    intraversal(root->right);
}
int main(){
    int val;
    node*root=NULL;
    root=make(root);
    cout<<"the level order traversal of the tree is as follows"<<endl;
    level(root);
    root=bal(root);
    cout<<"the level order traversal  after balancing of the tree is as follows"<<endl;
    level(root);
    cout<<"the inorder traversal is as follows"<<endl;
    intraversal(root);

    
    return 0;
}