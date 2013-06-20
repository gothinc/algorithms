#include <stdio.h>
#include <stdlib.h>
#include "rb.h"

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
		printf("%d\n", node->key->key);
		node = node->right;
	}
}

void
queue_append(queue *q, tnode *key){
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
	q->head->key = NULL;
	q->count = 0;
}
