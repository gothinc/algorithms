#include <stdio.h>

int select(int *s, int p, int q, int i);
int partion(int *s, int p, int q);
void swap(int *s, int p, int q);

int main(int argc, char *argv[]){
	int s[11] = {7,9,3,2,5,11,8,10,22,35,13};
	int a = select(s, 0, 10, 6);

	printf("%d\n", a);
}

int select(int *s, int p, int q, int i){
	if(p >= q) return p;

	int min = partion(s, p, q);	
	int k = min - p + 1;
	if(k == i)
		return s[min];

	if(k > i){
		return select(s, p, min - 1, i);
	}else if(k < i){
		return select(s, min + 1, q, i - k);
	}
}

int partion(int *s, int p, int q){
	int temp = s[p];
	int base = p;

	while(p < q){
		while(p < q && s[q] >= temp)
			q --;
		while(p < q && s[p] <= temp)
			p ++;

		swap(s, p, q);	
	}

	swap(s, base, p);
	return p;
}

void swap(int *s, int p, int q){
	int tmp = s[p];
	s[p] = s[q];
	s[q] = tmp;
}
