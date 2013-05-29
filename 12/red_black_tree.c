#include <stdio.h>

#define BLACK 1
#define RED   0
#define NIL   0

typedef struct tree_node{
	struct tree_node *left;
	struct tree_node *right;
	struct tree_node *p;
	int    color; //0:红　1:黑
	int    key;
} tnode;

typedef	struct read_black_tree{
	tnode head;
	int   black_count;
	int   red_count;
} rbtree;

int
main(int argc, char *argv[]){
	rbtree tree;	
	init_tree(&tree);
}

void init_tree(rbtree *tree){
	init_node(&tree->head);
}

void init_node(tnode *node){
	node->left = NULL;
	node->right = NULL;
	node->p = NULL;
	node->color = BLACK;
	node->key = NIL;
}
