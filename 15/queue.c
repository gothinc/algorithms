#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node{
	struct queue_node *left;	
	struct queue_node *right;
	int key;
} queue_node;

typedef struct queue{
	queue_node *head;
	int count;
} queue;

void print_queue(queue_node *head);
void queue_append(queue *q, int key);
void init_queue(queue *q);

/*int
main(int argc, char *argv[]){
	queue q;	
	init_queue(&q);
	int i;
	for(i = 1; i < 15; i ++){
		queue_append(&q, i);
	}

	print_queue(q.head);
}*/

void
print_queue(queue_node *head){
	if(head == NULL) return;

	queue_node *node = head->right;
	while(node){
		printf("%d\n", node->key);
		node = node->right;
	}
}

void
queue_append(queue *q, int key){
	queue_node *node;
	node = q->head;
	if(node == NULL) return;

	while(node->right != NULL){
		node = node->right;
	}

	node->right = malloc(sizeof(queue_node));
	node->right->left = node;
	node->right->right = NULL;
	node->right->key = key;
	q->count ++;
}

void
init_queue(queue *q){
	q->head = malloc(sizeof(queue_node));
	q->head->left = NULL;
	q->head->right = NULL;
	q->head->key = -1;
	q->count = 0;
}
