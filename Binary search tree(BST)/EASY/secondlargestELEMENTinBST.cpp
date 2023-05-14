#include<iostream>
#include<queue>
#include<vector>
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
       if(a<root->data){
           root->left=intoBST(root->left,a);
       }
       else{
           root->right=intoBST(root->right,a);
       }
    }
}
node*make(node*root){
    int a;
    cout<<"enter the root node val in the field"<<endl;
    cin>>a;
    while(a!=-1){
        root=intoBST(root,a);
        cout<<"enter the node val in the field--->";
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
 void secondlow(node*root,vector<int>&arr){
    if(root==NULL){
        return ;
    }
    secondlow(root->left,arr);
    arr.push_back(root->data);
    secondlow(root->right,arr);
}
int count(node*root){
    vector<int>arr;
    secondlow(root,arr);
    cout<<"the size of arr is---> "<<arr.size()<<endl;
    return arr[arr.size()-2];
}
int main(){
    node*root=NULL;
    int c=0;
    root=make(root);
    cout<<"the level order traversal of the tree is as follows"<<endl;
    level(root);
    cout<<"the second lowest element in the bst is-->>"<<count(root)<<endl;
   
    return 0;
}