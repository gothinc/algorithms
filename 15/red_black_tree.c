#include "rb.h"

queue *q;

int
main(int argc, char *argv[]){
	rbtree tree;
	q = malloc(sizeof(queue));
	init_queue(q);
	init_tree(&tree);
	insert_plenty(&tree);
	//print_tree(tree.head);
	layer_traversal(tree.head);
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
	if(node->p->right == node){
		node->p->right = node->right;
	}else{
		node->p->left = node->right;
	}

	node->right->p = node->p;
	node->p = node->right;
	node->right->left = node;
	node->right = t;
	if(t && memcmp(*t, *NIL()) != 0) t->p = node;

	if(memcmp(*node->p->p, *NIL()) == 0){
		tree->head = node->p;
	}
}

static void
rightRotate(rbtree *tree, tnode *node){
	if(memcmp(*node, *NIL()) == 0 || memcmp(*node->left, *NIL()) == 0) return;

	tnode *t = node->left->right;
	if(node->p->right == node){
		node->p->right = node->left;
	}else{
		node->p->left = node->left;
	}

	node->left->p = node->p;
	node->p = node->left;
	node->left->right = node;
	node->left = t;
	if(t && memcmp(*t, *NIL()) != 0) t->p = node;

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
layer_traversal(tnode *head){
	if(head == NULL || memcmp(*head, *NIL()) == 0) return;
	int lh, rh, i;

	queue_append(q, head);
	queue_node *t = q->head->right;
	while(t && memcmp(*t->key, *NIL()) != 0){
        lh = rh = i = 0;
        lh = get_seq(head, t->key, &i, rh);
        if(t->left && t->left->key){
            if(get_relative_height(head, t->left->key) == get_relative_height(head, t->key)){
                i = 0;
                lh -= get_seq(head, t->left->key, &i, rh);
            }
        }

        for(rh = 0; rh < lh; rh ++){
            printf("\t");
        }
		printf("%d", t->key->key);

		if(t->right == NULL || get_relative_height(head, t->key) != get_relative_height(head, t->right->key)) printf("\n\n");

		queue_append(q, t->key->left);	
		queue_append(q, t->key->right);
		t = t->right;
	}
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
	i = get_height(node->left);
	j = get_height(node->right);

	return i > j ? i + 1 : j + 1;
}

static int
get_relative_height(tnode *head, tnode *base){
	if(base == NULL || memcmp(*base, *NIL()) == 0) return 0;	

	int i = 0;
	tnode *t = base;	

	while(t && memcmp(*t, *NIL()) != 0){
		i ++;
		t = t->p;
	}

	return i;
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

static int
get_seq(tnode *node, tnode *bas, int *i, int x){
	if(node && memcmp(*node, *NIL()) != 0){
		x = get_seq(node->left, bas, i, x);
        if(node == bas) *i = 1;
        if(*i == 1) return x;
        x ++;
		x = get_seq(node->right, bas, i, x);
	}
    
    return x;
}

static void
init_tree(rbtree *tree){
	tree->head = NIL();
	tree->black_count = 0;
	tree->red_count = 0;
}
