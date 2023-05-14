
#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
   vector<vector<int>>arr={{1,2,3},{4,5,7}};
     int sum=0;
       for(auto i:arr){
        //   cout<<i.begin()<<" ";
          sum=accumulate(i.begin(),i.end(),0);
       }
       cout<<sum;
    return 0;
}
