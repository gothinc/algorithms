#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINES 15
#define COLUMES 15
int matrix[LINES][COLUMES];
int apples[LINES][COLUMES];

void collect_apples();

int
main(int argc, char *argv[]){
	int i, j;
	for(i = 0; i < LINES; i ++){
		for(j = 0; j < COLUMES; j ++){
			if(i % 2 == 0){
				if(j % 2 == 0){
					matrix[i][j] = 1;
				}else{
					matrix[i][j] = 0;
				}
			}else{
				if(j % 2 == 0){
					matrix[i][j] = 0;
				}else{
					matrix[i][j] = 1;
				}
			}
		}
	}

	memset(apples, 0, sizeof(apples));

	collect_apples();
}

void
collect_apples(){
	int i, j;
	for(i = 0; i < LINES; i ++){
		for(j = 0; j < COLUMES; j ++){
			if(i == 0){
				apples[i][j] = j == 0 ? 0 :  apples[i][j - 1];
			}else if(j == 0){
				apples[i][j] = apples[i - 1][j];
			}else{
				apples[i][j] = apples[i - 1][j] > apples[i][j - 1] ? apples[i - 1][j] : apples[i][j - 1];
			}

			if(matrix[i][j]) apples[i][j] += matrix[i][j];
		}
	}

	printf("%d\n", apples[LINES - 1][COLUMES - 1]);
}
