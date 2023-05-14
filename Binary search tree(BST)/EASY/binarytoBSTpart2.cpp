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
node*intoBST(node*root,int a){
    if(root==NULL){
        root=new node(a);
        return root;
    }
    if(a>root->data){
        root->right=intoBST(root->right,a);
    }
    else{
        root->left=intoBST(root->left,a);
    }
    return root;
}
static int p=1;
node* make(node*root){
    int a;
     if(p<=1){
        cout<<"enter the node val in the field"<<endl;
        p++;   
    }
    cin>>a;
    root=new node(a);
    if(a==-1){
        return NULL;
    }
    else{
        cout<<"enter the left node of--> "<<a<<"--> ";
        root->left=make(root->left);
        cout<<"enter the right node of--> "<<a<<"--> ";
        root->right=make(root->right);
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
void inorder(node*root,int arr[],int *a){
    if(root==NULL){
        return ;
    }
    inorder(root->left,arr,a);
    arr[*a]=root->data;
    (*a)++;
   // cout<<root->data<<" ";
    inorder(root->right,arr,a);
}
void intrav(node*root){
    if(root==NULL){
        return ;
    }
    intrav(root->left);
   cout<<root->data<<" ";
    intrav(root->right);
}
int count(node*root){
    if(root==NULL){
        return 0;
    }
    int l=count(root->left);
    int r=count(root->right);
    return l+r+1;
}
int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}
int main(){
    node*root=NULL;
    node*ptr=NULL;            //1 5 7 -1 -1 8 -1 -1 20 9 -1 -1 10 -1 -1
    root=make(root);
    int a=count(root);
    int *arr=new int[a];
    int b=0;
    // cout<<"the level order traversal of the tree is as follows"<<endl;
    // level(root);
     cout<<"\nthe inorder traversal ofthe tree is as follows"<<endl;
     intrav(root);
    inorder(root,arr,&b);
    qsort(arr,a,sizeof(arr[0]),compare);
    //cout<<"\nthe total number of node present in the tree is--> "<<a;
    cout<<endl;
    for(int i=0;i<a;i++){
        ptr=intoBST(ptr,arr[i]);
    }
    root=ptr;
    cout<<"\nthe level order traversal of the tree is as follows"<<endl;
    level(root);

    return 0;
}