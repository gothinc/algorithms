#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST 2 
#define SECOND 3 
#define THIRD 5
#define COIN_NUM 3
#define RET 3251
#define MAX 32876

//greedy algorithm
int greedy();

//dynamic algorithm
void dynamic_pro();
void dynamic_simple();
int get_min(int a, int b, int c);

int
main(int argc, char *argv[]){
	/*int time;
	time = greedy();
	printf("times:%d\n" ,time);
	*/

	dynamic_pro();
	printf("---------------\n");
	dynamic_simple();
}

void
dynamic_simple(){
	int d[RET + 1], v[COIN_NUM], i, j;

	for(i = 0; i <= RET; i ++){
		d[i] = MAX;
	}

	d[0] = 0;
	v[0] = FIRST;
	v[1] = SECOND;
	v[2] = THIRD;


	for(i = 0; i <= RET; i ++){
		for(j = 0; j < COIN_NUM; j ++){
			if(i >= v[j] && (d[i - v[j]] + 1) < d[i]) d[i] = d[i - v[j]] + 1;	
		}
	}

	if(d[RET] >= MAX){
		printf("cannot fix up\n");
	}else{
		printf("%d\n", d[RET]);
	}
}

void
dynamic_pro(){
	int time, d[RET + 1], i, x, y, z;
	time = x = y = z = 0;
	memset(d, 0, sizeof(d));

	for(i = 0; i <= RET; i ++){
		if(i >= THIRD){
			x = d[i - THIRD] + 1;
			y = d[i - SECOND] + 1;
			z = d[i - FIRST] + 1;

			d[i] = get_min(x, y , z);	
		}else if(i >= SECOND){
			x = d[i - SECOND] + 1;
			y = d[i - FIRST] + 1;
			d[i] = x < y ? x : y;
		}else if(i >= FIRST){
			d[i] = d[i - FIRST] + 1;
		}else{
			d[i] =  i == 0 ? 0 : MAX;
		}
	}

	if(d[RET] >= MAX){
		printf("cannot fix up\n");
	}else{
		printf("%d\n", d[RET]);
	}
}

int
get_min(int a, int b, int c){
	a = a < b ? a : b;
	return a < c ? a : c;
}

int
greedy(){
	int r, diff, time;
	r = time = 0;

	while(r < RET){
		diff = RET - r;	
		if(diff >= THIRD){
			r += THIRD;
			printf("%d\n", THIRD);
		}else if(diff >= SECOND){
			r += SECOND;
			printf("%d\n", SECOND);
		}else if(diff >= FIRST){
			r += FIRST;
			printf("%d\n", FIRST);
		}else{
			break;
		}

		time ++;
	}

	return time;
}
