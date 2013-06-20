#include <stdio.h>
#include <stdlib.h>
#include "rb.h"

queue q;

int
main(int argc, char *argv[]){
	rbtree tree;
	init_queue(&q);
	init_tree(&tree);
	insert_plenty(&tree);
	print_tree_graph(tree.head);
	printf("height:%d\n", get_height(tree.head));
}

tnode *
NIL(){
	tnode *t = malloc(sizeof(tnode));
	*t = (tnode){NULL, NULL, NULL, BLACK, -1};
	return t;
}

int
insert_plenty(rbtree *tree){
	int i;

	for(i = 0; i <= 20; i ++){
		insert(tree, i);
	}
}

static void
leftRotate(rbtree *tree, tnode *node){
	if(memcmp(*node, *NIL()) == 0 || memcmp(*node->right, *NIL()) == 0) return;

	tnode *t = node->right->left;

	if(node == tree->head){
		node->p->right = node->p->left = node->right;
	}else{
		if(node->p->right == node){
			node->p->right = node->right;
		}else{
			node->p->left = node->right;
		}
	}

	node->right->p = node->p;
	node->p = node->right;
	node->right->left = node;
	node->right = t;

	if(memcmp(*node->p->p, *NIL()) == 0){
		tree->head = node->p;
	}
}

static void
rightRotate(rbtree *tree, tnode *node){
	if(memcmp(*node, *NIL()) == 0 || memcmp(*node->left, *NIL()) == 0) return;

	tnode *t = node->left->right;
	if(node == tree->head){
		node->p->right = node->p->left = node->left;
	}else{
		if(node->p->right == node){
			node->p->right = node->left;
		}else{
			node->p->left = node->left;
		}
	}

	node->left->p = node->p;
	node->p = node->left;
	node->left->right = node;
	node->left = t;

	if(memcmp(*node->p->p, *NIL()) == 0){
		tree->head = node->p;
	}
}

static void
fixup_tree(rbtree *tree, tnode *node){
	if(tree->head->color == RED){
		tree->head->color = BLACK;
		tree->black_count ++;
		tree->red_count --;
		return;
	}

	if(node->p->color == BLACK) return;

	if(node->p->p->left == node->p){
		if(node->p->p->right->color == BLACK){
			if(node->p->left == node){
				node->p->color = BLACK;
				node->p->p->color = RED;
				rightRotate(tree, node->p->p);
			}else{
				leftRotate(tree, node->p);
				node->p->color = BLACK;
				node->p->p->color = RED;
				rightRotate(tree, node->p->p);
			}
		}else{
			node->p->color = BLACK;
			node->p->p->right->color = BLACK;
			node->p->p->color = RED;
			tree->black_count ++;
			tree->red_count --;
			fixup_tree(tree, node->p->p);
		}
	}else{
		if(node->p->p->left->color == BLACK){
			if(node->p->right == node){
				node->p->color = BLACK;
				node->p->p->color = RED;
				leftRotate(tree, node->p->p);
			}else{
				rightRotate(tree, node->p);
				node->p->color = BLACK;
				node->p->p->color = RED;
				leftRotate(tree, node->p->p);
			}
		}else{
			node->p->color = BLACK;
			node->p->p->left->color = BLACK;
			node->p->p->color = RED;
			tree->black_count ++;
			tree->red_count --;
			fixup_tree(tree, node->p->p);
		}
	}

	tree->head->color = BLACK;
}

static int
insert(rbtree *tree, int key){
	tnode **head = &tree->head;
	tnode *pre = NIL();

	while(memcmp(**head, NIL()) != 0){
		pre = *head;
		head = ((*head)->key >= key) ? &(*head)->left : &(*head)->right;
	}

	(*head)->left = NIL();
	(*head)->right = NIL();
	(*head)->key = key;
	(*head)->color = RED;
	(*head)->p = pre;
	tree->red_count ++;

	fixup_tree(tree, *head);
}

static void
print_tree_graph(tnode *node){
	if(memcmp(*node, *NIL()) == 0) return;	
	int lh, rh, i;
	lh = rh = i = 0;

	lh = get_height(node->left);
	rh = get_height(node->right);

	for(i = 0; i <= lh; i ++){
		printf(" ");
	}
	printf("%d", node->key);
	for(i = 0; i <= rh; i ++){
		printf(" ");
	}
	printf("\n");

	print_tree_graph(node->left);
	print_tree_graph(node->right);
}

static void
print_tree_graph_test(tnode *node){
	if(memcmp(*node, *NIL()) == 0) return;
	int lh, rh, i;
	lh = rh = i = 0;

	lh = get_height(node->left);
	rh = get_height(node->right);

	for(i = 0; i <= lh; i ++){
		printf(" ");
	}
	printf("%d", node->key);
	for(i = 0; i <= rh; i ++){
		printf(" ");
	}
	printf("\n");

	print_tree_graph(node->left);
	print_tree_graph(node->right);
}

static void
print_tree(tnode *node){
	if(node && memcmp(*node, *NIL()) != 0){
		printf("%d\n", node->key);
		print_tree(node->left);
		print_tree(node->right);
	}
}

static int
get_height(tnode *node){
	if(node->key == -1)
		return 0;

	int i, j;
	i = j = 0;
	i = get_height(node->left);
	j = get_height(node->right);

	return i > j ? i + 1 : j + 1;
}

static int
get_balck_height(rbtree *tree){
	tnode *node = tree->head;
	int n = 0;
	while(memcmp(*node, *NIL()) != 0){
		node = node->left;
		n ++;	
	}

	return n + 1;
}

static void
init_tree(rbtree *tree){
	tree->head = NIL();
	tree->black_count = 0;
	tree->red_count = 0;
}
