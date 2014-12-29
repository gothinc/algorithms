#include <stdio.h>

int tail_recursion(int n, int acc);
int common_recursion(int n);

int
main(int argc, char *argv[]){
	int n = tail_recursion(6, 1);
	printf("%d\n", n);
}

int
tail_recursion(int n, int acc){
	if(n == 1) return acc;
	return tail_recursion(n - 1, n * acc);
}

int
common_recursion(int n){
	if(n == 1) return n;
	return n * common_recursion(n - 1);
}
