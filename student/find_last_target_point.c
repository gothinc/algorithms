#include <stdio.h>

typedef struct tnode{
	int key;
	struct tnode *next;
} node;

void gen_list(node *s, int k);
void print_node(node *s, int k);
int main(int argc, char *argv[]){
	node s[10];
	gen_list(s, 10);		

	int ret;
	ret = find(s, 3);
	printf("%d\n%d\n", ret, s[ret].key);
}

int find(node *s, int k){
	int i, j;
	i = j = 0;
	node *a = &s[0];

	while(a->next != NULL){
		if((j - i) >= (k - 1)) i ++;
		j ++;
		a = a->next;
	}

	return i;
}

void gen_list(node *s, int k){
	int i;
	for(i = 0; i < k; i ++){
		s[i].key = i;
		if(i > 0) s[i - 1].next = &s[i];
	}

	s[i - 1].next = NULL;
}

void print_node(node *s, int k){
	int i;
	for(i = 0; i <= k; i ++){
		printf("%d\n", s[i].key);
	}
}
