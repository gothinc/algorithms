#include <stdio.h>

void merge_sort(int *a, int low, int high);
void merge_me(int *a, int low, int mid, int high);
void main(int argc, char *argv[]){
	int a[16] = {3,3333,5,321,2,4,31,4,52,54,32,17,18,13,40,39};
	merge_sort(a, 0, 15);

	int i;
	int len;
	len = sizeof(a) / sizeof(int);
	for(i = 0; i < len; i ++){
		printf("%d,", a[i]);	
	}
}

void merge_sort(int *a, int low, int high){
	if(low >= high) return;

	int mid;
	mid = (low + high) / 2;
	merge_sort(a, low, mid);
	merge_sort(a, mid + 1, high);
	merge_me(a, low, mid, high);
}

void merge_me(int *a, int low, int mid, int high){
	int low_bench = low;
	int high_bench = mid + 1;
	int len = high - low + 1;
	int tmp[len];	
	int i = 0;

	while(low_bench <= mid && high >= high_bench){
		if(a[low_bench] <= a[high_bench]){
			tmp[i ++] = a[low_bench ++];	
		}else{
			tmp[i ++] = a[high_bench ++];
		}
	}

	while(low_bench <= mid){
		tmp[i ++] = a[low_bench ++];
	}

	while(high_bench <= high){
		tmp[i ++] = a[high_bench ++];
	}

	for(i = 0; i < len; i ++){
		a[low ++] = tmp[i];
	}
}
