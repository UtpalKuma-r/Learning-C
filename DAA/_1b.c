#include <stdio.h>

int sorted(int arr[], int n){
	for(int i = 0; i<n-1; i++) if(arr[i]>arr[i+1]) return 0;
	return 1;
}

int binary_search(int arr[], int n, int target){
	int middle, l_limit = 0, u_limit = n;
	while(l_limit<=u_limit){
		middle = (l_limit+u_limit)/2;
		if(arr[middle] == target) return middle;
		else if(arr[middle] < target) l_limit = middle+1;
		else u_limit = middle-1;
	}
	return -1;
}

void main(){
	int n, k;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i<n; i++){
		printf("Enter element: ");
		scanf("%d", &arr[i]);
	}
	
	printf("Enter the target value: ");
	scanf("%d", &k);
	
	if(sorted(arr, n) != 1){
		printf("Array is not sorted\n");
		return;
	}
	printf("Arrray is sorted\n");
	
	int index = binary_search(arr, n, k);
	if(index == -1){
		printf("Element not found\n");
		return;
	}
	printf("%d", index);
	
}
