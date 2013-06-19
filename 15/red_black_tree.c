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

void
leftRotate(rbtree *tree, tnode *node){
	if(memcmp(*node, NIL) == 0 || memcmp(*node->right, NIL)) return;

	node->right->p = node->p;
	if(node->p->right == node){
		node->p->right = node->right;
	}else{
		node->p->left = node->right;
	}

	node->p = node->right;
	node->right->left = node;
	node->right = node->right->left;
}

void
rightRotate(rbtree *tree, tnode *node){
	if(memcmp(*node, NIL) == 0 || memcmp(*node->left, NIL)) return;

	node->left->p = node->p;
	if(node->p->right == node){
		node->p->right = node->left;
	}else{
		node->p->left = node->left;
	}

	node->p = node->left;
	node->left->right = node;
	node->left = node->left->right;
}

void
fixup_tree(rbtree *tree, tnode *node){
	if(tree->head->color == RED){
		tree->head->color = BLACK;
		return;
	}

	if(node->p->color == BLACK) return;

	if(node->p->p->left == node->p){
		if(node->p->p->right->color == BLACK){
			if(node->p->left == node){
				node->p->color = BLACK;
				node->p->p->color = RED;
				rightRotate(tree, node->p);
			}else{
				leftRotate(tree, node->p);
				rightRotate(tree, node);
			}
		}else{
			node->p->color = BLACK;
			node->p->p->right->color = BLACK;
			node->p->p->color = RED;
			fixup_tree(tree, node->p->p);
		}
	}else{
		if(node->p->p->left->color == BLACK){
			if(node->p->right == node){
				node->p->color = BLACK;
				node->p->p->color = RED;
				leftRotate(tree, node->p);
			}else{
				rightRotate(tree, node->p);
				leftRotate(tree, node);
			}
		}else{
			node->p->color = BLACK;
			node->p->p->left->color = BLACK;
			node->p->p->color = RED;
			fixup_tree(tree, node->p->p);
		}
	}
}

int
insert(rbtree *tree, int key){
	tnode **head = &tree->head;
	tnode *pre = &NIL;

	while(*head){
		pre = *head;
		head = ((*head)->key >= key) ? &(*head)->left : &(*head)->right;
	}

	(*head) = malloc(sizeof(tnode));
	(*head)->left = &NIL;
	(*head)->right = &NIL;
	(*head)->key = key;
	(*head)->color = RED;
	(*head)->p = pre;

	fixup_tree(tree, *head);
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
