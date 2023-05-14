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
node*insert(node*root){
    int val;
    cout<<"enter the data in the field"<<endl;
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left node of->"<<val<<endl;
    root->left=insert(root->left);

    cout<<"enter the right node of->"<<val<<endl;
    root->right=insert(root->right);
    return root;
}

void level(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void in(node*root){
    if(root==NULL){
        return;
    }
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}

void pre(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

void post(node*root){
    if(root==NULL){
        return;
    }
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}
node*pa(node*root,int a){
     root=new node(a);
     return root;
 }
node* add(node*root,int a){
    if(root==NULL){
        root=pa(root,a);
        return root;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            //cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
           // cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
             else {
                temp->left = pa(temp->left,a);
               return root;
        }
            if(temp->right){
                q.push(temp->right);
            }
            else {
                temp->right = pa(temp->left,a);
               return root;
        }
        }
    }
}
int main(){
  node*root=NULL;
  root=insert(root); 
  //4 5 7 -1 -1 8 -1 -1 10 3 -1 -1 2 -1 -1 
  cout<<"the level ordr traversal is as follows:::"<<endl;
  level(root);
  cout<<"the inorder traversal is as follows:::"<<endl;
  in(root);
   cout<<"\nthe pre traversal is as follows:::"<<endl;
  pre(root);
   cout<<"\nthe post traversal is as follows:::"<<endl;
  post(root);
  int tr;
  cout<<"\nenter the node u want to  insert in the tree"<<endl;
  cin>>tr;
  root=add(root,tr);
  cout<<"\nthe level ordr traversal is as follows:::"<<endl;
  level(root);
  cout<<"\nthe inorder traversal is as follows:::"<<endl;
  in(root);
    return 0;
}