#include <stdio.h>

struct heap{
	int val;
	struct heap *left;
	struct heap *right;
};

int len, heap_size;
void create_heap(int *s);
void exchange_heap(int *s, int i, int j);
void max_heapify(int *s, int i);
void heap_sort(int *s);

void main(int argc, char *argv[]){
	int s[14] = {3,412,5,1,2,13,12,351,23,41,31,432,321,45};		
	heap_size = len = sizeof(s) / sizeof(int);
	create_heap(s);
	heap_sort(s);

	int i;
	for(i = 0; i < len; i ++){
		printf("%d,", s[i]);
	}
	printf("\n");
}

void heap_sort(int *s){
	int i;
	for(i = len - 1; i > 0; i --){
		exchange_heap(s, 0, i);	
		heap_size --;
		max_heapify(s, 0);
	}
}

void max_heapify(int *s, int i){
	int left = i * 2;
	int right = i * 2  + 1;
	int large;

	if(left >= heap_size) return;

	if(s[i] < s[left]) large = left;
		else large = i;
	if((right < heap_size) && (s[large] < s[right])) large = right;

	if(large != i){
		exchange_heap(s, i, large);
		max_heapify(s, large);
	}
}

void exchange_heap(int *s, int i, int j){
	int tmp;
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

void create_heap(int *s){
	int i;
	for(i = len / 2; i >= 0; i --){
		max_heapify(s, i);	
	}
}
