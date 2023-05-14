#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int val){
        this->data=val;
        this->next=NULL;
    }
};
void in(node*&tail,int val){
    node*pt=new node(val);
    tail->next=pt;
    tail=pt;
}
void pri(node*&head){
    node*pt=head;
    while(pt!=NULL){
        cout<<pt->data<<" ";
        pt=pt->next;
    }
}

void rev(node*&head,node*&tail){
    node*pre,*cu,*nex;
    nex=head;
    cu=pre=NULL;
    while(nex!=NULL){
        cu=nex;
        nex=nex->next;
        cu->next=pre;
        pre=cu;
    }
    head=pre;

}
int main(){
  node*ptr=new node(10);
  node*head=ptr;
  node*tail=ptr;
  in(tail,12);
  in(tail,13);
  in(tail,14);
  in(tail,15);
  in(tail,16);
  cout<<"the printing of the linked list Before reVarsle:::"<<endl;
  pri(head);
  cout<<"\nthe head data is::"<<head->data<<endl;
  rev(head,tail);
  cout<<"\n********************************\n";
  cout<<"********************************\n";
  cout<<"the printing of the linked list After reVarsle:::"<<endl;
  pri(head);
  cout<<"\nthe head data is::"<<head->data<<endl;

    return 0;
}