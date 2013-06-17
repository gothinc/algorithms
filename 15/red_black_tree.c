#include <stdio.h>
#include <stdlib.h>

#define BLACK 1
#define RED   0

typedef struct tree_node{
	struct tree_node *left;
	struct tree_node *right;
	struct tree_node *p;
	int    color; //0:红　1:黑
	int    key;
} tnode;

#define NIL (tnode){NULL, NULL, NULL, BLACK, 0}

typedef	struct read_black_tree{
	tnode *head;
	int   black_count;
	int   red_count;
} rbtree;

void print_tree(tnode *node);
void init_tree(rbtree *tree);

int
main(int argc, char *argv[]){
	rbtree tree;
	init_tree(&tree);
	insert_plenty(&tree);
	print_tree(tree.head);
}

int
insert_plenty(rbtree *tree){
	int i;

	for(i = 0; i <= 10; i ++){
		insert(tree, i);
	}
}

int
insert(rbtree *tree, int key){
	tnode **head = &tree->head;
	tnode *pre = NULL;

	while(*head){
		pre = *head;
		head = ((*head)->key >= key) ? &(*head)->left : &(*head)->right;
	}

	(*head) = malloc(sizeof(tnode));
	(*head)->left = NULL;
	(*head)->right = NULL;
	(*head)->key = key;
	(*head)->color = RED;
	(*head)->p = pre;
}

void
print_tree(tnode *node){
	if(node){
		printf("%d\n", node->key);
		print_tree(node->left);
		print_tree(node->right);
	}
}

void
init_tree(rbtree *tree){
	tree->head = NULL;
	tree->black_count = 0;
	tree->red_count = 0;
}

void
init_node(tnode *node){
	node->left = node;
	node->right = node;
	node->p = node;
	node->color = BLACK;
	node->key = 0;
}
