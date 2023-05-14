#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void bub(int *ptr,int a){
    int i=0;
    int y=-1;
    while(y!=0){
        int min=0;
        i=0;
    while(i<a-1){
        if(ptr[i]>ptr[i+1]){
             min=1;
             int temp=ptr[i];
             ptr[i]=ptr[i+1];
             ptr[i+1]=temp;
             i++;
        }
        else{
           i++;
        }
    }
    if(min==0){
      y=0;
    }
    }
}
int main(){
    int a;
    printf("enter the size of the array in the field\n");
    scanf("%d",&a);
    int *ptr=(int*)malloc(a*sizeof(int));
    for(int i=0;i<a;i++){
        printf("%d::",i);
        scanf("%d",&ptr[i]);
    }
    clock_t t;
    t=clock();
    bub(ptr,a);
    t=clock()-t;
    printf("the array is as follows\n");
   double time_taken=((double)t)/CLOCKS_PER_SEC;
    for(int i=0;i<a;i++){
        printf("%d ",ptr[i]);
    }
    printf("\nthe time taken is:::%f",time_taken);


    
    return 0;
}