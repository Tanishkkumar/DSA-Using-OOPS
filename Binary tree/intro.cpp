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
node*make(node*root){
    int val;
    cout<<"enter the value in the field"<<endl;
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left node of->"<<val<<endl;
    root->left=make(root->left);
    cout<<"enter the right node of->"<<val<<endl;
    root->right=make(root->right);
    return root;
}

void level(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    node*temp;
    while(!q.empty()){
        temp=q.front();
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

void dep(node*root,node*key){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==key){
            temp=NULL;
            delete(key);
            return;
        }
        if(temp->left){
             if(temp==key){
            temp=NULL;
            delete(key);
            return;
        }
        else{
             q.push(temp->left);
        }
        }

        if(temp->right){
             if(temp==key){
            temp=NULL;
            delete(key);
            return;
             }
             else{
             q.push(temp->right);
             }
        }
        
     }
}
node*del(node*root,int val){
    queue<node*>q;
    q.push(root);
    node*key=NULL;
    node*temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp==val){
            key=temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
         if(temp->right){
            q.push(temp->right);
        }
    }
    if(key!=NULL){
        int a=temp->data;
        dep(root,temp);
        key->data=a;
    }
    return root;
}
int main(){
    int e;
    node*root=NULL;
    root=make(root);
    cout<<"the level order traversal of tree is as follows"<<endl;
    level(root);
    cout<<"enter the element u want to delete from the tree"<<endl;
    cin>>e;
    root=del(root,e);
    cout<<"\nthe tree after delettion is as follows"<<endl;
    level(root);

    
    return 0;
}