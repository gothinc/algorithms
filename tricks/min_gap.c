#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_r(int a[], int c);
void union_arr(int a[], int x, int b[], int y, int c[]);
int min_del(int c[], int z);

int
main(int argc, char *argv[]){
	int a[6] = {3, 5, 7, 1, 2 ,4};
	int b[6] = {11, 13, 9, 8, 15, 14};

	int c[12];
	union_arr(a, 6, b, 6, c);
	printf("min gap is: %d\n", min_del(c, 12));
}

int
min_del(int c[], int z){
	int a[z];
	int b[z];
	int sum_a, sum_b;

	memset(a, 0, z);
	memset(b, 0, z);

	int i, m, n;
	for(i = 0, m = 0, n = 0; i < z; i ++){
		if(sum_arr(a, m) < sum_arr(b, n)){
			a[m ++] = c[i];
		}else{
			b[n ++] = c[i];
		}
	}

	sum_a = sum_arr(a, m);	
	sum_b = sum_arr(b, n);
	return sum_a > sum_b ? sum_a - sum_b : sum_b - sum_a;
}

int
sum_arr(int a[], int x){
	if(x <= 0) return 0;

	int i, sum;
	for(i = 0, sum = 0; i < x; i ++){
		sum += a[i];
	}

	return sum;
}

void
union_arr(int a[], int x, int b[], int y, int c[]){
	int i, j;
	for(i = 0; i < x; i ++){
		c[i] = a[i];
	}

	for(j = 0; j < y; j ++){
		c[i ++] = b[j];
	}
}

void
print_r(int a[], int c){
	int i;
	for(i = 0; i < c; i ++){
		printf("%d ", a[i]);
	}
}
