#include <stdio.h>
#define str_len(s,b) sizeof(s) / sizeof(b)

void quick_sort(int *s, int i, int j);
int partion(int *s, int i, int j);
void print_r(int *s, int len);
void change(int *s, int i, int j);

int main(int argc, char *argv[]){
	int s[15] = {21,3,1,43,3,142,5,31,45,23,3,561,87,42,52};
	int len;
	len = str_len(s, int);
	quick_sort(s, 0, 14);

	print_r(s, len);
}

void print_r(int *s, int len){
	int i;
	for(i = 0; i < len; i ++){
		printf("%d\n", s[i]);
	}
}

void quick_sort(int *s, int i, int j){
	if(i >= j) return;
	int mid;
	mid = partion(s, i, j);
	quick_sort(s, i, mid - 1);
	quick_sort(s, mid + 1, j);
}

int partion(int *s, int i, int j){
	int b = j + 1;
	int tmp = s[i];
	for(; j > i; j --){ 
		if(s[j] > tmp){
			b --;
			change(s, j, b);
		}
	}

	change(s, i, b - 1);
	return b - 1;
}

int partion2(int *s, int i, int j){
	int tmp = s[i];
	int base = i;
	while(i < j){
		while(i < j && s[j] >= tmp)
			j --;
		while(i < j && s[i] <= tmp)
			i ++;
		change(s, i, j);
	}

	change(s, i, base);
	return i;
}

int partion1(int *s, int i, int j){
	int tmp = s[i];
	while(i < j){
		while(i < j && s[j] >= tmp)
			j --;
		change(s, i, j);		

		while(i < j && s[i] <= tmp)
			i ++;
		change(s, i, j);
	}
	
	return i;
}

void change(int *s, int i, int j){
	int tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}
