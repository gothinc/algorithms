#include <stdio.h>

int
main(int argc, char *argv[]){
	if(argc != 3){
		printf("argc should == 3\n");
		return 1;
	}

	char *a, *b;
	char c;
	int i = 0;
	
	a = argv[1];
	b = argv[2];

	if((i = strcmp(a, b)) == 0){
		printf("a == b\n");
	}else if(i < 0){
		printf("a < b\n");
	}else{
		printf("a > b\n");
	}

	return 0;
}

int
strcmp(char *a, char *b){
	if(a == NULL || b == NULL) return 0;

	while(*a != 0 && *a == *b){
		a ++;
		b ++;
	}

	if(*a == 0 && *b == 0) return 0;
	return *a > *b ? 1 : -1;
}
