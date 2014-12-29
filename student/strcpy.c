#include <stdio.h>
#include <stdlib.h>

char * strcpy_my(char *a, char *b);

int
main(int argc, char *argv[]){
	char *a, b[10];
	a = "kobe";

	strcpy_my(a, b);
	printf("%s\n", b);
}

char *
strcpy_my(char *a, char *b){
	char *tmp = b;

	while((*b ++ = *a ++) != 0);
	return tmp;
}
