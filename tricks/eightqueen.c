#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printl();

int
main(int argc, char *argv[]){
	char *s[8][8];
	memset(s, 0, sizeof(s));
	s[1][2] = "x";
	s[3][4] = "*";

	printl(s, 8, 8);
}

void
place(char *s[][8], int x, int y){

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
