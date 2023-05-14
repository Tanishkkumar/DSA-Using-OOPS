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
node* make(node*root){
    int data;
    cout<<"enter the data val"<<endl;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter the data for inserting at the left of->"<<data<<endl;
    root->left=make(root->left);
    cout<<"enter the data for inserting at the right of->"<<data<<endl;
    root->right=make(root->right);
    return root;
}

void lev(node*root){
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
int main(){
    node*root=NULL;
    root=make(root);
    cout<<"the level order traversal of teh tree is as follows::::"<<endl;
    lev(root);
    
    return 0;
}