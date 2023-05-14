// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int>a;
//     cout<<a.capacity()<<endl;
//     a.push_back(1);
//      a.push_back(1);
//     cout<<a.capacity()<<endl;
//     return 0;
// }

// #include<iostream>
// #include<stack>
// using namespace std;
// int main(){
//     stack<string>s;
//     s.push("tanishk");
//     s.push("kumar");
//     s.push("oraab");
//     //9-cout<<s.top()<<endl;
//     s.pop();
//     s.pop();
//     s.pop();
//     cout<<s.top()<<endl;

//     return 0;
// }



#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string>s;
    s.push("tanishk");
    s.push("kumar");
    s.push("oraab");
    //9-cout<<s.top()<<endl;
    // s.pop();
    // s.pop();
    // s.pop();
    cout<<s.front()<<endl;

    return 0;
}