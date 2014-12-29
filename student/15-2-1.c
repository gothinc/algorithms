#include <stdio.h>
#define MAX_MY 0x6fffffff
void matrix_chain_order(int *p, int (*m)[6], int (*s)[6]);
void init_array(int (*s)[6], int len);
void print_matrix(int (*s)[6], int a, int b);
int main(int argc, char *argv[]){
	int p[7] = {5,10,3,12,5,50,6};
	int m[6][6];
	int s[6][6];

	init_array(m, 6);
	init_array(s, 6);
	matrix_chain_order(p, m, s);
	print_matrix(s, 0, 5);
}

void matrix_chain_order(int *p, int (*m)[6], int (*s)[6]){
	int n = 6;				
	int l, i, j, k, q;
	for(l = 2; l <= n; l ++){
		for(i = 0; i < (n - l + 1); i ++){
			j = i + l - 1;	
			m[i][j] = MAX_MY;

			for(k = i; k < j; k ++){
				q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;	
				}
			}
		}
	}
}

void print_matrix(int (*s)[6], int a, int b){
	if(a == b){
		printf("A%d", a);
	}else{
		printf("(");
		print_matrix(s, a, s[a][b]);
		print_matrix(s, s[a][b] + 1, b);
		printf(")");
	}
}

void init_array(int (*s)[6], int len){
	int i, j;
	for(i = 0; i < len; i ++){
		for(j = 0; j < len; j ++){
			s[i][j] = 0;
		}
	}
}
