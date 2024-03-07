#include <stdio.h>

int shorted(int arr[], int n){
	int num = arr[0];
	for(int i = 1; i<n; i++){
		if(arr[i]<num) return 0;
		num = arr[i];
	}
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
	
	if(shorted(arr, n) != 1){
		printf("Array is not shorted\n");
		return;
	}
	printf("Arrray is shorted\n");
	
	int index = binary_search(arr, n, k);
	if(index == -1){
		printf("Element not found\n");
		return;
	}
	printf("%d", index);
	
}
