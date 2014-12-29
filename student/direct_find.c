#include <stdio.h>

void main(){
	char *s[] = {"kobe", "md", "jordan", "beckham", "jams", "wd"};
	/*int i;
	for(i = 0; i < 6; i ++){

	}*/
	
	char *e = "a";
	int m = (int)e;
	int a = m % 6;
	printf("%d\n", a);
}

/*int gen_index(char *s){
	int ret;
	return s % 6;
}*/
