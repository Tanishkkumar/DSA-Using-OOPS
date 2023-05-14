#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        this->next=NULL;

    }
};
void insert(node*&head,int val){
    node*temp=new node(val);  //it call constructor to allocate the val;
    temp->next=head;
    head=temp;

}

void insertat(node*&tail,int val){
    node*temp=new node(val);  //it call constructor to allocate the val;
    tail->next=temp;
    tail=tail->next;

}

void print(node*&head){
    node*ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main(){
    node*ptr=new node(10);
    // cout<<ptr->data<<endl;
    // cout<<ptr->next<<endl;
    node*head=ptr;
    node*tail=ptr;
    insertat(tail,12);
    insertat(tail,13);
    cout<<"printing of linked list is as follows::"<<endl;
    print(head);
    return 0;
}