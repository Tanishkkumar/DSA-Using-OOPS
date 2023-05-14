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
node*in(node*root){
    int da;
    cout<<"enter the node val"<<endl;
    cin>>da;
    root=new node(da);
    //node*temp=root;
    if(da==-1){
        return NULL;
    }
     cout<<"enter the left node of->"<<da<<endl;
    root->left=in(root->left);

    cout<<"enter the right node of->"<<da<<endl;
    root->right=in(root->right);
    return root;

}


//                  using recursion
int ht(node*root){
    if(root==NULL){
        return 0;
    }
    
    int left=ht(root->left);
    int right=ht(root->right);
    if(left>right){
        return left+1;
    }                              //yhs if else ki place pe 
                                   //return max(left,right)+1; bhe likh sakte hai...
    else{                     
        return right+1;
    }
}

//              height using queue is as follows:::

int heightUsingQueue(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int ht=0;

    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            ht++;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return ht;
}
int main(){
    node*root=NULL;
    root=in(root);
    int y=ht(root);
    cout<<"the height of the tree is ->"<<y<<endl;
    int r=heightUsingQueue(root);
    cout<<"the height using level order traversal is as follows:::"<<r<<endl;
    
    return 0;
}