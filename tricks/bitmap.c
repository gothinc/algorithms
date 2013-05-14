#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 8972654 //随便设定的数
#define SHIFT 5
int bitmap[1 + MAX/32];

int setbit(unsigned int x);
int clearbit(unsigned int x);
void print_map();
void print_bit(int offset, int i);

int 
main(int argc, char *argv[]){
	if(argc < 2){
		printf("argc must greater than 1\n");
		return 1;
	}
	
	unsigned x = (unsigned)atoi(argv[1]);
	memset(bitmap, 0, sizeof(bitmap));

	if(setbit(x)){
		print_map();

		if(clearbit(x))
			print_map();
	}
	
	return 0;
}

int
setbit(unsigned int x){
	if(x > MAX || x == 0){
		printf("input should greater than 0\n");
		return 0;
	}else{
		bitmap[(x - 1) >> SHIFT] |= (1 << ((x - 1) & 31));
		return 1;
	}
}

int
clearbit(unsigned int x){
	if(x > MAX || x == 0){
		printf("input should greater than 0\n");
		return 0;
	}else{
		bitmap[(x - 1) >> SHIFT] &= ~(1 << ((x - 1) & 31));
		return 1;
	}
}

void
print_map(){
	int i;
	for(i = 0; i < (1 + MAX/32); i ++){
		print_bit(bitmap[i], i);	
	}
}

void
print_bit(int offset, int i){
	int j;
	for(j = 0; j < 32; j ++){
		if(offset & (1 << j)){
			printf("%d\n", i * 32 + j + 1);				
		}
	}
}
