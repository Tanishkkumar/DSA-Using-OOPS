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
    cout<<"enter the val in the field\n";
    cin>>val;
    root=new node(val);
    if(val==-1){
        return NULL;
    }
    cout<<"enter the left child of----"<<val<<endl;
    root->left=make(root->left);
    cout<<"enter the right child of----"<<val<<endl;
    root->right=make(root->right);
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

//*******************insertion function start**********************
node*pa(node*root,int val){
    root=new node(val);
    return root;
}
node*in(node*root,int val){
    if(root==NULL){
        root=pa(root,val);
        return root;
    }
    queue<node*>q;
    q.push(root);
     while(!q.empty()){
        node*ptr=q.front();
        q.pop();
        if(ptr->left){
            q.push(ptr->left);
        }
        else{
            ptr->left=pa(ptr->left,val);
            return root;
        }
        if(ptr->right){
            q.push(ptr->right);
        }
        else{
            ptr->right=pa(ptr->right,val);
            return root;
        }
    }

}

//*******************insertion function end**********************


//*******************deletion function start**********************
void delpost(node*root,node*ptr){
    queue<node*>q;
    q.push(root);
    node*temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp==ptr){
            temp=NULL;
            delete(ptr);
            return ;
        }
        if(temp->left){
            if(temp->left==ptr){
                temp->left=NULL;
                delete(ptr);
                return;
            }
            else{
                q.push(temp->left);
            }
        }
        if(temp->right){
            if(temp->right==ptr){
                temp->right=NULL;
                delete(ptr);
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
        if(temp==NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(temp->data==val){
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
int  ht(node*root){
    if(root==NULL){
        return 0;
    }
    int l=ht(root->left);
    int r=ht(root->right);
    if(l>r){
        return l+1;
    }
    return r+1;
}

void prispi(node*root,int i,int itr){
    if(root==NULL){
        return;
    }
    if(i==1){
        cout<<root->data<<" ";
    }
    else if(i>1){
        if(itr){
            prispi(root->left,i-1,itr);
             prispi(root->right,i-1,itr);
        }
        else{
             prispi(root->right,i-1,itr);
             prispi(root->left,i-1,itr);

        }
    }
}

void spiral(node*root,int ht){
    bool itr=false;
    for(int i=1;i<=ht;i++){
        prispi(root,i,itr);
        itr=!itr;
    }
}

int main(){
    int a,b;
    node*root=NULL;
    root=make(root);
    cout<<"thelevel order traversal of tree is as follows"<<endl;
    level(root);
    // cout<<"enter the element u want to  insert in the tree"<<endl;
    // cin>>a;
    // root=in(root,a);
    // cout<<"thelevel order traversal of tree afterinsertion  is as follows"<<endl;
    // level(root);
    // cout<<"enter the element u want to delete from the tree\n";
    // cin>>b;
    // root=del(root,b);
    // cout<<"thelevel order traversal of tree is as follows"<<endl;
    // level(root);
    
   int height= ht(root);
   //cout<<"the height of binary tree is as follows::::"<<height;
   cout<<"\nthe spiral printing is as follows"<<endl;
   spiral(root,height);
    
    return 0;
}