/**
 * 构建二叉查找树翻译英文
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree2{
	char *wd;
	char *cn;
	struct tree2 *left;
	struct tree2 *right;
} tree_base;

void print_tree(tree_base *tree);
void build_tree(tree_base *tree, tree_base *node);
void swap(tree_base *a, tree_base *b);
void translate_my(char *s, char *r);
void copy_str_my(char *a, char *b);
void init_arr_my(char *a, int pre_len, int last_len);
void exe_trans(char *a);
void format_ret(char *a, int pre_len, int last_len, char *b);

tree_base *tree;
int main(int argc, char *argv[]){
	int i;
	tree_base list[] = {{"kobe", "科比", NULL, NULL}, {"mx", "麦迪", NULL, NULL}, {"jordan", "乔丹", NULL, NULL}, {"lian", "李安", NULL, NULL}, {"shen", "神", NULL, NULL}, {"god", "上帝", NULL, NULL}};		
	tree = (tree_base *)malloc(sizeof(tree_base));
	for(i = 0; i < 6; i ++){
		build_tree(tree, &list[i]);
	}

	char s[100] = "kobe god shen lian jordan mx\0";
	char r[100];
	translate_my(s, r);
	printf("%s\n", s);
	printf("%s\n", r);
}

void translate_my(char *s, char *r){
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	char a[6][10];
	char tmp[10];

	init_arr_my((char *)a, 6, 10);
	while(s[i] != '\0'){
		if(s[i] == ' '){
			tmp[k] = '\0';	
			exe_trans(tmp);
			copy_str_my(tmp, a[j ++]);
			k = 0;
		}else{
			tmp[k ++] = s[i];
		}

		i ++;
	}

	tmp[k] = '\0';
	exe_trans(tmp);
	copy_str_my(tmp, a[j]);

	format_ret((char *)a, 6, 10, r);
}

void format_ret(char *a, int pre_len, int last_len, char *b){
	int i, j, k;
	i = 0;j = 0;k = 0;
	for(i = 0; i < pre_len; i ++){
		for(j = 0; j < last_len; j ++){
			if(a[i * last_len + j] == '\0'){
				b[k ++] = ' ';	
				break;
			}else{
				b[k ++] = a[i * last_len + j];
			}
		}
	}

	b[k] = '\0';
}

void exe_trans(char *a){
	if(tree->wd == NULL) return;
	tree_base *tmp;
	tmp = tree;
	while(tmp){
		if(strcmp(tmp->wd, a) == 0){
			strcpy(a, tmp->cn);
		}else if(strcmp(tmp->wd, a) > 0){
			tmp = tmp->left;
		}else{
			tmp = tmp->right;
		}
	}
}

void init_arr_my(char *a, int pre_len, int last_len){
	int i, j;

	for(i = 0; i < pre_len; i ++){
		for(j = 0; j < last_len; j ++){
			a[i * last_len + j] = '\0';
		}
	}
}

void copy_str_my(char *a, char *b){
	int i ,j;
	i = 0;
	j = 0;
	
	while(a[i] != '\0'){
		b[j ++] = a[i ++];
	}
	b[j] = '\0';
}

void print_tree(tree_base *tree){
	if(tree == NULL) return;

	print_tree(tree->left);
	printf("%s:%s\n", tree->wd, tree->cn);
	print_tree(tree->right);
	free(tree);
}

void build_tree(tree_base *tree, tree_base *node){
	if(tree->wd == NULL){
		tree->left = node->left;
		tree->right = node->right;
		tree->cn = node->cn;
		tree->wd = node->wd;
		return;
	}

	tree_base *tmp = tree;
	
	while(tmp){
		if((*tmp->wd) == (*node->wd)) break;
		if((*tmp->wd) > (*node->wd)){
			if(tmp->left == NULL){
				tmp->left = (tree_base *) malloc(sizeof(tree_base));
				swap(tmp->left, node);
				break;
			}else{
				tmp = tmp->left;
			}
		}else{
			if(tmp->right == NULL){
				tmp->right = (tree_base *) malloc(sizeof(tree_base));
				swap(tmp->right, node);
				break;
			}else{
				tmp = tmp->right;
			}
		}
	}
}

void swap(tree_base *a, tree_base *b){
	a->wd = b->wd;
	a->cn = b->cn;
	a->left = NULL;
	a->right = NULL;
}
