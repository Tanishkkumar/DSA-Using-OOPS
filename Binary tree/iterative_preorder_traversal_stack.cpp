#include<iostream>
#include<stack>
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
    cout<<"enter the value in the field\n";
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left node of->>"<<val;
    root->left=make(root->left);
    cout<<"enter the right node of->>"<<val;
    root->right=make(root->right);
    return root;
}
void itr(node*root){
    if(root==NULL){
        return ;
    }
    stack<node*>s;
    s.push(root);
    while(s.empty()==false){
        node*ptr=s.top();
        cout<<ptr->data<<" ";
        s.pop();
        if(ptr->left){
            s.push(ptr->left);    //last in first out...
        }
        if(ptr->right){
            s.push(ptr->right);
        }
    }
}
void que(node*root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*ptr=q.front();
        cout<<ptr->data<<" ";
        q.pop();
        if(ptr->left){
            q.push(ptr->left);    //First in first out.....
        }
        if(ptr->right){
            q.push(ptr->right);
        }
        
    }

}
int main(){
    node*root=NULL;
    //  4 5 7 -1 -1 8 -1 -1 10 -1 2 -1 -1
    root=make(root);
    cout<<"the iterative traversal of the root is as foolws"<<endl;
    itr(root);
    cout<<"\nthe iterative  level order traversal using queue is as follows\n";
    que(root);


    return 0;
}