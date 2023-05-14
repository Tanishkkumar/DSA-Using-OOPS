#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*pre;
    node(int a){
        this->data=a;
        this->pre=NULL;
        this->next=NULL;
    }
    ~node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            //this->next=NULL;
        }
        cout<<"the dleted node is::"<<val<<endl;
    }
};
void intail(node*&tail,node*&head,int val){
    node*ptr=new node(val);
    tail->next=ptr;
    ptr->pre=tail;
    tail=ptr;
    tail->next=head;
}
void inhead(node*&head,node*&tail,int val){
    node*ptr=new node(val);
    ptr->next=head;
    head->pre=ptr;
    head=ptr;
    head->pre=tail;
}
void pri(node*&head,node*&tail){
    node*pt=head;
    node*ptr=tail;
    
    cout<<"In forward direction::";
    while(pt!=tail){
        cout<<pt->data<<" ";
        pt=pt->next;
    }
    cout<<pt->data;

 
    cout<<"\nIn reverse direction::";
    while(ptr!=head){
        cout<<ptr->data<<" ";
        ptr=ptr->pre;
    }
    cout<<ptr->data;
}
void insert(node*&head,node*&tail,int val,int pos){
    if(pos==1){
       inhead(head,tail,val);
       return ;
    }
    if(pos==6){
        intail(tail,head,val);
        return ;
    }
    node*ptr=new node(val);
    node*pt=head;
    int cnt=1;
    while(cnt<pos-1){
        pt=pt->next;
        cnt++;
    }
    ptr->next=pt->next;
    ptr->pre=pt;
    pt->next->pre=ptr;
    pt->next=ptr;
}
int si(node*&head){
    node*pt=head;
    int c=0;
    while(pt!=NULL){
        pt=pt->next;
        c++;
    }
    return c-1;
}
void del(node*&head,node*tail,int pos){
    if(pos==1){
        node*pt=head;
        head=head->next;
        head->pre=tail;
        delete pt;
    }
    if(pos==7){
        node*p=tail;
        tail=tail->pre;
        tail->next=head;
        delete p;
    }
    node*arr=head;
    node*ctr=NULL; 
    int i=1;
    while(i<pos){
        ctr=arr;
        arr=arr->next;
        i++;
    }
    ctr->next=arr->next;
    arr->next->pre=ctr;
    arr->next=NULL;
    delete arr;
}
int main(){
    node*ptr=new node(12);
    int a,b;
    node*head=ptr;
    node*tail=ptr;
    intail(tail,head,14);
    intail(tail,head,15);
    intail(tail,head,16);
    intail(tail,head,17);
    intail(tail,head,18);
    cout<<"\nthe doubly linked list is as follows::\n";
    pri(head,tail);

    cout<<endl;
    cout<<"head::"<<head->data<<endl;
    cout<<"tail::"<<tail->data<<endl;
    cout<<"enter the node and the position of the node"<<endl;
    cin>>a>>b;
    insert(head,tail,a,b);
    cout<<"*************************************";
    cout<<"\nthe doubly linked list after insertion is as follows::\n";
    pri(head,tail);
    cout<<"\nhead::"<<head->data<<endl;
    cout<<"tail::"<<tail->data<<endl;
    a=b=0;
    cout<<"************************************\n";
    cout<<"enter the position u want to  delete form the doubly linked list ::\n";
    cin>>a;
    del(head,tail,a);
    cout<<"************************************";
     cout<<"\nthe doubly linked list after deletion is as follows::\n";
    pri(head,tail);
     cout<<"\nhead::"<<head->data<<endl;
    cout<<"\ntail::"<<tail->data<<endl;

    return 0;
}