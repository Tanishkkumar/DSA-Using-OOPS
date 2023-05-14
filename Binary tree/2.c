// C program to implement recursive Binary Search
#include <stdio.h>
#include<time.h>
#include<stdlib.h>

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int main(void)
{ 

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
    int result = binarySearch(ptr, 0, a - 1, b);
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("the time taken is::%f",time_taken);
	//int arr[] = { 2, 3, 4, 10, 40 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//int x = 10;
	
	(result == -1)
		? printf("Element is not present in array")
		: printf("Element is present at index %d", result);
	return 0;
}
