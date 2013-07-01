#include <stdio.h>

void create_arr(int arr[], int n);
void print_arr(int arr[], int n);
void swap_arr(int arr[], int a, int b);
void quick_sort(int arr[], int start, int last);
int cal_mid(int arr[], int start, int last);

int
main(int argc, char *argv[]){
	int arr[32];
	create_arr(arr, 32);
	
	quick_sort(arr, 0, 31);
	print_arr(arr, 32);
}

void
quick_sort(int arr[], int start, int last){
	if(start >= last) return;
	
	int mid;

	mid = cal_mid(arr, start, last);	
	
	quick_sort(arr, start, mid - 1);
	quick_sort(arr, mid + 1, last);
}

int
cal_mid(int arr[], int start, int last){
	int base = start;
	
	while(start < last){
		while(start < last && arr[last] >= arr[base]) last--;
		while(start < last && arr[start] <= arr[base]) start ++;

		swap_arr(arr, start, last);
	}
	
	swap_arr(arr, start, base);
	return start;
}

void
swap_arr(int arr[], int a, int b){
	if(a < 0 || b < 0) return;

	int tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void
create_arr(int arr[], int n){
	srand(time());
	int i, k;
	for(i = 0; i < n; i ++){
		if(i == 3){
			k = rand();
			arr[i ++] = k;
			arr[i] = k;
		}else{
			arr[i] = rand();
		}
	}
}

void
print_arr(int arr[], int n){
	int i;
	for(i = 0; i < n; i ++){
		printf("%d\n", arr[i]);
	}
}
