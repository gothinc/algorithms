#ifndef RB_HEAD
#define RB_HEAD 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLACK 1
#define RED   0

typedef struct tree_node{
	struct tree_node *left;
	struct tree_node *right;
	struct tree_node *p;
	int    color; //0:红　1:黑
	int    key;
} tnode;

typedef	struct red_black_tree{
	tnode *head;
	int   black_count;
	int   red_count;
} rbtree;

tnode *NIL();
static int get_balck_height(rbtree *tree);
static int get_height(tnode *node);
static int insert(rbtree *tree, int key);
static void print_tree(tnode *node);
static void init_tree(rbtree *tree);
static void leftRotate(rbtree *tree, tnode *node);
static void rightRotate(rbtree *tree, tnode *node);
static void fixup_tree(rbtree *tree, tnode *node);
static void print_tree_graph(tnode *node);
static void layer_traversal(tnode *node);
static int get_relative_height(tnode *head, tnode *base);
static int get_seq(tnode *node, tnode *bas, int *i, int x);

typedef struct queue_node{
	struct queue_node *left;	
	struct queue_node *right;
	tnode *key;
} queue_node;

typedef struct queue{
	queue_node *head;
	int count;
} queue;

void print_queue(queue_node *head);
void queue_append(queue *q, tnode *key);
void init_queue(queue *q);
tnode * unshift(queue *q);

#endif
