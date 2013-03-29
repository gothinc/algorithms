#include <stdio.h>

typedef struct key{
	int val;
	struct key *a;
	struct key *b;
} kobe;
void main(){
	kobe a = {4, NULL, NULL};
	kobe b = {5, NULL, NULL};
	kobe md = {3, &a, &b};
	//md->val = 3;

	printf("%d\n", md.a->val);
}
