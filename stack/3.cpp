//stack using linked list 
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
class stack{
    node*top;
    public:
    stack(){
        top=NULL;
    }
    void push(int val){
        node*temp=new node(val);
        if(!temp){
            cout<<"stack overflow"<<endl;
            exit(1);
        }
        // temp->data=val;
        temp->next=top;
        top=temp;
    }

    bool isEmpty(){
        return top==NULL;
    }
    
     void display()
    {
        node* temp;
  
        // Check for stack underflow
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {
  
                // Print node data
                cout << temp->data;
  
                // Assign temp link to temp
                temp = temp->next;
                if (temp != NULL)
                    cout << " -> ";
            }x
        }
    }
};
int main(){
    stack s;
    s.push(11);
    s.push(12);
    s.push(13);
    s.display();



    
    return 0;
}