#include<iostream>
#include<vector>
#include<queue>

/*
* Create an array arr[] of size N, where N is the number of nodes in the given BST.
* Perform the inorder traversal of the BST and copy the node values in the arr[] in sorted order.
* Now perform the preorder traversal of the tree.
* While traversing the root during the preorder traversal, one by one copy the values from the array arr[] to the nodes of the BST.
*/
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
node*intoBST(node*root,int a){
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
node*make(node*root){
    int a;
    cout<<"enter the value of the main root node in the field"<<endl;
    cin>>a;
    while(a!=-1){
        root=intoBST(root,a);
        cout<<"enter the value of the main root node in the field--> ";
        cin>>a;
    }
    return root;
}

 //For calculating number of nodes present in the tree.
int count(node*root){    
    if(root==NULL){
        return 0;
    }
    int l=count(root->left);
    int r=count(root->right);
    return 1+l+r;
}


void inorder(node*root,vector<int>&arr){
    if(root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
void minheapUsingPREORDER(node*&root,vector<int>&arr,int *a){
    if(root==NULL){
        return ;
    }
    root->data=arr[++*a];
    minheapUsingPREORDER(root->left,arr,a);
    minheapUsingPREORDER(root->right,arr,a);
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
    int a;
    int l=-1;
    node*root=NULL;       //4 2 6 1 3 5 7 -1
    root=make(root);
    cout<<endl;
    level(root);
    vector<int>arr;
    inorder(root,arr);
    minheapUsingPREORDER(root,arr,&l);
    cout<<endl;
    level(root);
    //cout<<"the total number of node in the tree is---> "<<a;
    return 0;
}