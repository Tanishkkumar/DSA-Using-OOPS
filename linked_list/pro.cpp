#include<iostream>
#include<vector>
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
void make(node*&head){
    int a;
    node*ptr;
    node*p;
    cout<<"enter the node val"<<endl;
    cin>>a;
    head=new node(a);
    p=head;
    cout<<"enter the node val"<<endl;
    cin>>a;
    while(a!=-1){
        ptr=new node(a);
        p->next=ptr;
        p=ptr;
        cout<<"enter the node val"<<endl;
        cin>>a;
    }
}
void pri(node*head){
    node*ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
node*check(node*headA,node*headB){
        node *temp1 = headA;
		node *temp2 = headB;
		while(temp1 != temp2){
			if(temp1 == NULL){
				temp1 = headB;
			}
			else{
				temp1 = temp1 -> next;
			}
			if(temp2 == NULL){
				temp2 = headA;
			}
			else{
				temp2 = temp2 -> next;
			}
		}
		return temp1;
	}

int main(){
    node*head1=NULL;   //5 6 1 8 4 5 -1
    node*head2=NULL;  //4 1 8 4 5 -1
    cout<<"enter the first linked list"<<endl;
    make(head1);
    cout<<"enter the second linked list"<<endl;
    make(head2);
    cout<<"the 1st linked list is as follows"<<endl;
    pri(head1);
    cout<<"\nthe 2nd linked list is as follows"<<endl;
    pri(head2);
    node*ctr=check(head1,head2);
    cout<<"\nthe node coinciding is --> "<<ctr;
    
    return 0;
}