#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printl();
void place(char *s[][8], int x, int y);
int is_conflic(char *s[][8], int x, int y);
int my_abs(int x);

int
main(int argc, char *argv[]){
	char *s[8][8];
	memset(s, 0, sizeof(s));

	place(s, 8, 8);
	printl(s, 8, 8);
}

void
place(char *s[][8], int x, int y){
	int i, j, reverse;
	for(i = 0, reverse = 0; i < x; i ++){
		for(j = 0; j < y; j ++){
			if(reverse){
				if(s[i][j]){
					s[i][j] = 0;
					reverse = 0;
				}
			}else{
				if(!is_conflic(s, i, j)){
					s[i][j] = "*";
					break;
				}
			}
		}

		if(j >= y || !s[i][j]){
			if(i == 0){
				printf("cannot find\n");
				break;
			}

			i -= 2;
			reverse = 1;
		}
	}
}

int
is_conflic(char *s[][8], int x, int y){
	if(x == 0) return 0;

	int i, j;
	for(i = 0; i < x; i ++){
		for(j = 0; j < 8; j ++){
			if(s[i][j]){
				if(j == y || (x - i) == (my_abs(y - j))) return 1;
				break;
			}
		}
	}

	return 0;
}

int
my_abs(int x){
	if(x >= 0) return x;
	return ~x + 1;
}

void
printl(char *s[][8], int x, int y){
	int i, j;

	for(i = 0; i < x; i ++){
		printf("|");

		for(j = 0; j < y; j ++){
			if(s[i][j]){
				printf("%s", s[i][j]);
			}else{
				printf(" ");
			}

			printf("|");	
		}

		printf("\n");
	}
}
