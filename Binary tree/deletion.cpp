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

void delpost(node*root,node*ptr){
    queue<node*>q;
    q.push(root);
    //q.push(NULL);
    node*temp;
    while(!q.empty()){
         temp=q.front();
         q.pop();
         if(temp==ptr){
             temp=NULL;
             delete(ptr);
             return ;
         }
         if(temp->right){
             if(temp->right==ptr){
                 temp->right=NULL;
                 delete(ptr);
                 return ;
             }
             else{
                 q.push(temp->right);
             }
         }

          if(temp->left){
             if(temp->left==ptr){
                 temp->left=NULL;
                 delete(ptr);
                 return ;
             }
             else{
                 q.push(temp->left);
             }
         }
    }
}


node* del(node*root,int a){
    queue<node*>q;
    q.push(root);
    node*key=NULL;
    node*temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp==NULL){
            //cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
           // cout<<temp->data<<" ";
           if(temp->data==a){
               key=temp;
           }
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            } 
        }
    }
    if(key!=NULL){
        int t=temp->data;
        delpost(root,temp);
        key->data=t;
    }
    return root;
}
int main(){
  node*root=NULL;
  root=insert(root); 
  //4 5 7 -1 -1 8 -1 -1 10 3 -1 -1 2 -1 -1 
  cout<<"the level ordr traversal is as follows:::"<<endl;
  level(root);
  int tr;
  cout<<"\nenter the node u want to  delelete in the tree"<<endl;
  cin>>tr;
  root=del(root,tr);
  cout<<"\nthe level ordr traversal after the deletion  is as follows:::"<<endl;
  level(root);
 
    return 0;
}






