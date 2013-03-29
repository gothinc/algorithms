#include <stdio.h>

void insert_sort(int *s, int len);
void main(int argc, char *argv[]){
	int len;
	int s[13] = {3,5,1,2,13,12,351,23,41,31,432,321,45};		

	len = sizeof(s) / sizeof(int);
	insert_sort(s, len);
	int i;

	for(i = 0; i < len; i ++){
		printf("%d,", s[i]);
	}
}

void insert_sort(int *s, int len){
	if(len < 2) return;
	int i, j;
	int tmp;

	for(i = 1; i < len; i ++){
		tmp = s[i];	
		j = i - 1;
		while(j >= 0 && s[j] > tmp){
			s[j + 1] = s[j];
			j --;
		}

		s[j + 1] = tmp;
	}
}
