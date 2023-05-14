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
node*make(node*root){
    int a;
    if(root==NULL){
        cout<<"enter the node val in the field"<<endl;
        
    }
    cin>>a;
    root=new node(a);
    if(a==-1){
        return NULL;
    }
    else{
        cout<<"enter the left node of-->"<<a<<endl;
        root->left=make(root->left);
        cout<<"enter the right node of-->"<<a<<endl;
        root->right=make(root->right);
    }
    return root;
}
int count(node*root){
    if(root==NULL){
        return 0;
    }
    int l=count(root->left);
    int r=count(root->right);
    return 1+l+r;
}
void inorder(node*root,int *arr,int *a){
    if(root==NULL){
        return ;
    }
    inorder(root->left,arr,a);
    arr[*a]=root->data;
    (*a)++;
    inorder(root->right,arr,a);
}
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void arraytoBST(int *arr,node*root,int *p){
    if(root==NULL){
        return ;
    }
    arraytoBST(arr,root->left,p);
    root->data=arr[*p];
    (*p)++;
    arraytoBST(arr,root->right,p);
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
    int b=0;
  node*root=NULL;  //50 30 20 -1 -1 40 -1 -1 70 60 -1 -1 80 -1 -1
  root=make(root);
  cout<<"\nthe level order traversal of tree before conversion"<<endl;
  level(root);
  int a=count(root);
  int *arr=new int[a];
  inorder(root,arr,&b);
//   cout<<"\nthe array is as follows--->"<<endl;
//   for(int i=0;i<a;i++){
//       cout<<arr[i]<<" ";
//   }
  qsort(arr,a,sizeof(arr[0]),compare);        //sort lib for quick sort==O(n^2).
//   cout<<"\nthe array after sorting is as follows--->"<<endl;
//   for(int i=0;i<a;i++){
//       cout<<arr[i]<<" ";
//   }
  b=0;
  arraytoBST(arr,root,&b);
  cout<<"\nthe level order traversal of tree after conversion"<<endl;
  level(root);
    return 0;
}