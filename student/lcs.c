#include <stdio.h>

void lcs(int *x, int *y, int a, int b, int (*c)[7]);
void init_array(int *s, int a, int b);
void print_array(int *s, int a, int b);
int main(int argc, char *argv[]){
	int x[5] = {1,3,7,5,2};
	int y[6] = {3,5,2,4,9,6};
	int c[6][7];

	init_array((int *)c, 6, 7);
	lcs(x, y, 5, 6, c);
	print_array((int *)c, 6, 7);
}

void lcs(int *x, int *y, int a, int b, int (*c)[7]){
	int i, j;
	for(i = 0; i < a; i ++){
		for(j = 0; j < b; j ++){
			if(x[i] == y[j]){
				c[i + 1][j + 1] = c[i][j] + 1;
			}else{
				if(c[i][j + 1] > c[i + 1][j]){
					c[i + 1][j + 1] = c[i][j + 1];	
				}else{
					c[i + 1][j + 1] = c[i + 1][j];	
				}
			}
		}
	}
}

void print_array(int *s, int a, int b){
	int i, j;
	for(i = 1; i < a; i ++){
		for(j = 1; j < b; j ++){
			printf("x[%d]y[%d]%d\n", i, j, s[i * b + j]);
		}
	}
}

void init_array(int *s, int a, int b){
	int i, j;
	for(i = 0; i < a; i ++){
		for(j = 0; j < b; j ++){
			s[i * b + j] = 0;
		}
	}
}
