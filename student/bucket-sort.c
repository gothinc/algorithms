#include <stdio.h>
#include <stdlib.h>

struct tnode{
	int i;
	struct tnode *next;
};

void bucket_sort(int *s, int len);
void print_r(struct tnode *b[], int len);
void add_tnode(struct tnode *a, struct tnode *b);
int main(int argc, char *argv[]){
	int s[5] = {1234,4251,2314,2423,2342};
	bucket_sort(s, 5);
}

void bucket_sort(int *s, int len){
	struct tnode *b[len];
	int i;
	int tmp;

	for(i = 0; i < len; i ++){
		b[i] = NULL;
	}

	for(i = 0; i < len; i ++){
		tmp = (s[i] / 1000) - 1;
		if(b[tmp] == NULL){
			b[tmp] = (struct tnode *) malloc(sizeof(struct tnode));
			b[tmp]->i = s[i];
			b[tmp]->next = NULL;
		}else{
			struct tnode *t = (struct tnode *) malloc(sizeof(struct tnode));
			t->i = s[i];
			t->next = NULL;
			add_tnode(b[tmp], t);
		}
	}

	print_r(b, 5);
}

void print_r(struct tnode *b[], int len){
	int i;
	for(i = 0; i < len; i ++){
		if(b[i] != NULL){
			printf("%d\n", b[i]->i);
			struct tnode *tmp = b[i]->next;
			struct tnode *q = NULL;

			while(tmp){
				printf("%d\n", tmp->i);
				q = tmp->next;
				free(tmp);
				tmp = q;
			}
			
			free(b[i]);
		}
	}
}

void add_tnode(struct tnode *a, struct tnode *b){
	struct tnode *x,*pre;
	if(a->next == NULL){
		a->next = b;
		return;
	}


	x = a->next;
	while(x->next != NULL){
		x = x->next;
	}
	
	x->next = b;
}
