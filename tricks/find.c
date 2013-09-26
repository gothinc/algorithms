#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	size_t v;
	struct node *next;
} node;

typedef struct list{
	node *head;
	node *tail;
	size_t num;
} list;

void print_list(list *link);
void create_list(list *link, int num);
node *append_node(list *link, int v);
void init_list(list *link);
node *create_node();
int find_spe(list *link, int p);
int atoi_my(char *s);

int
main(int argc, char *argv[]){
	list l;	
	create_list(&l, 10);

	print_list(&l);
	int i;
	char *pos;
	pos = argv[1];
	i = find_spe(&l, atoi_my(pos));
	printf("number:%d\n", i);
}

int
atoi_my(char *s){
	int i = 0;
	
	while(*s != 0){
		i = i * 10 + (*s ++ - '0');
	}

	return i;
}

int
find_spe(list *link, int p){
	node *pre, *n;
	int i = 1;
	n = link->head->next;
	
	while(n != link->tail){
		if(i == p){
			pre = link->head->next;
		}

		if(i > p){
			pre = pre->next;
		}

		n = n->next;
		i ++;
	}

	return pre ? pre->v : 0;	
}

void
print_list(list *link){
	node *n = link->head->next;

	while(n != link->tail){
		printf("%d\n", n->v);
		n = n->next;
	}
}

void
create_list(list *link, int num){
	init_list(link);

	int i;
	for(i = 0; i < num; i ++){
		append_node(link, i);	
	}
}

node *
append_node(list *link, int v){
	node *n = link->head;
	while(n->next != link->tail){
		n = n->next;
	}

	node *new = create_node();
	new->v = v;
	new->next = link->tail;
	n->next = new;

	return new;
}

void
init_list(list *link){
	link->head = create_node();
	link->tail = create_node();

	link->head->next = link->tail;
}

node *
create_node(){
	node *t = malloc(sizeof(node));
	t->v = 0;
	t->next = NULL;

	return t;
}
