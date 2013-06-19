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

void
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

void
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
			fixup_tree(tree, node->p->p);
		}
	}

	tree->head->color = BLACK;
}

int
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

	fixup_tree(tree, *head);
}

void
print_tree(tnode *node){
	if(node && memcmp(*node, *NIL()) != 0){
		printf("%d:%d\n", node->key, node->color);
		print_tree(node->left);
		print_tree(node->right);
	}
}

void
init_tree(rbtree *tree){
	tree->head = NIL();
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
