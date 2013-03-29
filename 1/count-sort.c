#include <stdio.h>

void count_sort(int *s, int len, int *b, int *c, int k);
void print_r(int *s, int len);
int main(int argc, char *argv[]){
	int s[7] = {3,8,2,4,3,7,6};	
	int len = 7;
	int b[7];
	int c[9];
	int k = 9;
	count_sort(s, len, b, c, k);
	print_r(b, 7);
}

void count_sort(int *s, int len, int *b, int *c, int k){
	int i;
	for(i = 0; i < k; i ++){
		c[i] = 0;
	}

	for(i = 0; i < len; i ++){
		c[s[i]] ++;
	}

	for(i = 1; i < k; i ++){
		c[i] = c[i] + c[i - 1];
	}

	for(i = len - 1; i >= 0; i --){
		b[c[s[i]] - 1] = s[i];
		c[s[i]] --;
	}
}

void print_r(int *s, int len){
	int i;
	for(i = 0; i < len; i ++){
		printf("%d,", s[i]);
	}
}
