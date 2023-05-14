#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq;  //by defualt it make MAX heap..
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"Max HEAP OUTPUT "<<endl;
    cout<<"element at top--> "<<pq.top()<<endl;
    pq.pop();
    cout<<"element at top--> "<<pq.top()<<endl;


    //MIN HEAP..

    priority_queue<int,vector<int>,greater<int>>mh;
    mh.push(4);
    mh.push(2);
    mh.push(5);
    mh.push(3);
    cout<<"\nMin HEAP OUTPUT "<<endl;
    cout<<"element at top--> "<<mh.top()<<endl;
    mh.pop();
    cout<<"element at top--> "<<mh.top()<<endl;

    
    return 0;
}