#include <stdio.h>
#define str_lenlen(s, b) sizeof(s) / sizeof(b)

int heapsize;
int maximum(int *s);
void insert(int *s, int x);
int extract_max(int *s);
void increase_key(int *s, int x, int k);
void print_queue(int *s, int len);
void build_queue(int *s, int len);
void heapify(int *s, int i, int len);
void exchange_heap(int *s, int i, int j);

int main(int argc, char *argv[]){
	int s[9] = {12,2,33,14, 5, 3, 21, 152, 123};
	int len = str_lenlen(s, int);
	heapsize = len;
	build_queue(s, len);

	print_queue(s, len);
	printf("---------------------------------------\n");
	
	increase_key(s, 7, 352);
	print_queue(s, len);
}

void print_queue(int *s, int len){
	int i;

	for(i = 0; i < len; i ++){
		printf("%d\n", s[i]);
	}
}

void build_queue(int *s, int len){
	int mid;	
	for(mid = len / 2 - 1; mid >= 0; mid --){
		heapify(s, mid, len);		
	}
}

void heapify(int *s, int i, int len){
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int large = i;

	if(left < len && s[left] > s[i]) large = left;
	if(right < len && s[large] < s[right]) large = right;
	if(large != i){
		exchange_heap(s, i, large);
		heapify(s, large, len);	
	}
}

void exchange_heap(int *s, int i, int j){
	int temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

int maximum(int *s){
	return s[0];
}

void insert(int *s, int x){

}

int extract_max(int *s){
	if(heapsize < 1) return 0;

	int ret = s[0];
	s[0] = s[heapsize - 1];
	s[heapsize - 1] = 0;
	heapsize --;

	heapify(s, 0, heapsize);
	return ret;
}

void increase_key(int *s, int x, int k){
	s[x] = k;
	if(x > 0){
		int p;
		p = (x - 1) / 2;
		while(x > 0 && s[p] < k){
			exchange_heap(s, x, p);
			x = p;
			p = (p - 1) / 2;
		}

		/*int i, tmp = x;
		  for(i = (x - 1) / 2; i >= 0; i = (i - 1) / 2){
		  if(s[i] >= k) break;
		  exchange_heap(s, i, tmp);
		  tmp = i;	
		  }*/
	}
}



