//insertion at starting ,end and in between the linked list is as follows..

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int a){
        this->data=a;
        this->next=NULL;
    }

    ~node(){
        int val=this->data;
        if(this->next!=NULL){
           delete next;
           //this->next=NULL;
        }
        cout<<"\nmemory isfreed :: at node value:::"<<val<<endl;
    }
};
//insertion form the head..
void in(node*&head,int val){
    node*ptr=new node(val);
    ptr->next=head;
    head=ptr;
}

//insertion form the tail.
void intail(node*&tail,int val){
    node*ptr=new node(val);
   tail->next=ptr;
   tail=ptr;
}

//printing of the linked list.
void pri(node*&head){
    node*p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
void insert(node*&head,node*&tail ,int val,int pos){
    if(pos==1){
        in(head,val);
        return;
    }
    node*ptr=head;
    node*arr=new node(val);
    int i=1;
    while(i<pos-1){
        ptr=ptr->next;
        i++;
    }
    if(ptr->next==NULL){
      intail(tail,val);
      return ;
    }
     arr->next=ptr->next;
     ptr->next=arr;
}


//deletion of a node .
void dele(int po,node*&head,node*&tail){
    if(po==1){
        node*pt=head;
        head=head->next;          //using destructor
        pt->next=NULL;
        delete pt;
    }
    else{
      node*arr=head;
      node*cu=NULL;
      int cnt=1;
      while(cnt<po){
          cu=arr;
          arr=arr->next;
          cnt++;
      }

      if(arr->next==NULL){
          
           cu->next=arr->next;
           tail=cu;
           delete arr;
      }
      else{
      cu->next=arr->next;
      arr->next=NULL;
      delete arr;
      
      }
    }
}
int main(){
    int pos;
    node*ptr=new node(10);
    node*head=ptr;
    node*tail=ptr;
    intail(tail,12);
    intail(tail,13);
    intail(tail,14);
    intail(tail,15);
    cout<<"\nthe linked list is as follows:::"<<endl;
    pri(head);
    int a,b;
    cout<<"\nenter the element u want to insert and also the position of the elemnt"<<endl;
    cin>>a>>b;
    insert(head,tail,a,b);
    cout<<"\nthe linked list after the insertion is as follows:::"<<endl;
    pri(head);
    
  cout<<"enter the position u want to dlete"<<endl;
  cin>>pos;
  dele(pos,head,tail);
//   cout<<"enter the 2  position u want to dlete"<<endl;
//   cin>>pos;
//   dele(pos,head,tail);
    // cout<<"\nthe tail data is as follows::"<<tail->data<<endl;
    // cout<<"the head data is as follows:::"<<head->data<<endl;
    cout<<endl;
     pri(head);
     cout<<"\nthe tail data is as follows::"<<tail->data<<endl;
    cout<<"the head data is as follows:::"<<head->data<<endl;
    
    return 0;
}