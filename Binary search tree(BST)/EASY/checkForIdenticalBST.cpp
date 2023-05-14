#include<bits/stdc++.h>
using namespace std;
bool isSameBSTUtil(int a[], int b[], int n, int i1, int i2,
                   int min, int max)
{
    int i, j;

    for (i = i1; i < n; i++)
        if (a[i] > min && a[i] < max)
            break;
    for (j = i2; j < n; j++)
        if (b[j] > min && b[j] < max)
            break;
 
    /* If the parent element is leaf in both arrays */
    if (i == n && j == n)
        return true;
 
    /* Return false if any of the following is true
        a) If the parent element is leaf in one array,
            but non-leaf in other.
        b) The elements satisfying constraints are
            not same. We either search for left
            child or right child of the parent
            element (decided by min and max values).
            The child found must be same in both arrays */
    if (((i == n) || (j == n)) || a[i] != b[j])   //8 3 6 1 4 7 10 14 13
        return false;                             //8 10 14 3 6 4 1 7 13
 
    /* Make the current child as parent and
    recursively checj for left and right
    subtrees of it. Note that we can also
    pass a[j] in place of a[i] as they
    are both are same */
    return isSameBSTUtil(a, b, n, i + 1, j + 1, a[i], max)
           && // Right Subtree
           isSameBSTUtil(a, b, n, i + 1, j + 1, min,
                         a[i]); // Left Subtree
}
 
// A wrapper over isSameBSTUtil()
bool isSameBST(int a[], int b[], int n)
{
    
    return isSameBSTUtil(a, b, n, 0, 0, INT_MIN, INT_MAX);
}
int main(){
    int a,b;
  cout<<"enter the value in the field"<<endl;
  cin>>a;
  int *arr=new int[a];
  int *ptr=new int[a];
  cout<<"enter the value of the first array in the field"<<endl;
  for(int i=0;i<a;i++){
      cout<<i<<"::";
      cin>>arr[i];
  }
  cout<<"enter the value of the second  array in the field"<<endl;
  for(int i=0;i<a;i++){
      cout<<i<<"::";
      cin>>ptr[i];
  }
 if(isSameBST(arr,ptr,a)){
     cout<<"Both the array forms the same BST"<<endl;

 }
 else{
     cout<<"the are not same "<<endl;
 }


    return 0;
}