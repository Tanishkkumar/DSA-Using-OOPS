#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void linear(int *arr,int a,int b){
  for(int i=0;i<a;i++){
      if(arr[i]==b){
          printf("founded\n");
      }
  }
}
int main(){
    int a;
    int b;
    printf("enter the size of the array\n");
    scanf("%d",&a);
    int *ptr=(int *)malloc(a*sizeof(int));
    printf("enter the array element\n");
    // for(int i=0;i<a;i++){
    //     scanf("%d",&ptr[i]);
    // }
    ptr[0]=1;
    printf("enter the element u want to search\n");
    scanf("%d",&b);
    clock_t t;
    t=clock();
    linear(ptr,a,b);
    
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("the time taken is::%f",time_taken);
    
    return 0;
}