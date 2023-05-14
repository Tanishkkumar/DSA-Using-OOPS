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
  void diapri(node*root,int a,map<int,vector<int>>&dia){
      if(root==NULL){
          return ;
      }
      dia[a].push_back(root->data);
      diapri(root->left,a+1,dia);
      diapri(root->right,a,dia);
  }
void diag(node*root){
    map<int,vector<int>> diagonal;
    diapri(root,0,diagonal);
    cout<<"printing of tree is as follows\n";
    for(auto &pr:diagonal){
        vector<int>v=pr.second;
        for(auto &pr:v){
            cout<<pr<<" ";
        }
        cout<<endl;
    }
}
int main(){
    node*root=NULL;
    //  4 5 7 -1 -1 8 -1 -1 10 -1 2 -1 -1
    root=make(root);
    cout<<"the diagonal traversal of map is as follows"<<endl;
    diag(root);
    printf("enter the vlaue in he feld\n");


    return 0;
}