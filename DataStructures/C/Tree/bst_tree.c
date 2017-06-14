#include "bst_tree.h"

#include <stdio.h>
#include <stdlib.h>

BSTNode *bst_insert(BSTNode *node, const int value) {
	if (NULL == node) {
		BSTNode *new_node = (BSTNode *)malloc(sizeof(BSTNode));
		bst_check_address(new_node);
		new_node->data = value;
		new_node->left = NULL;
		new_node->right = NULL;
		node = new_node;
	}

	if (value < node->data) {
		node->left = bst_insert(node->left, value);
	} else if (value > node->data) {
		node->right = bst_insert(node->right, value);
	} else { 
		// equal don`t thing.
	}

	return node;
}

void bst_check_address(BSTNode *node) {
	if (NULL == node) {
		printf("Malloc memory fail.\n");
		exit(-1);
	}
}

void bst_pre_print(BSTNode *node) {
	if (NULL == node) {
		return;
	}

	printf("%d\n", node->data);
	bst_pre_print(node->left);
	bst_pre_print(node->right);
}


void bst_in_print(BSTNode *node) {
	if (NULL == node) {
		return;
	}

	bst_in_print(node->left);
	printf("%d\n", node->data);
	bst_in_print(node->right);
}



void bst_post_print(BSTNode *node) {
	if (NULL == node) {
		return;
	}

	bst_post_print(node->left);
	printf("%d\n", node->data);
	bst_post_print(node->right);
}



int bst_get_node_count(BSTNode *node) {
	if (NULL == node) 
		return 0;
	return 1 + bst_get_node_count(node->left) + bst_get_node_count(node->right);
}


void bst_delete(BSTNode *node) {
	if (NULL == node) 
		return ;
	bst_delete(node->left);
	bst_delete(node->right);
	free(node);
}

int bst_is_in(BSTNode *node, const int value) {
	if (NULL == node)
		return 0;
	if (value < node->data)
		return bst_is_in(node->left, value);
	else if (value > node->data) 
		return bst_is_in(node->right, value);
	else
		return 1;
}



int bst_get_height(BSTNode *node) {
	if (NULL == node)
		return 0;
	return 1 + max_num(bst_get_height(node->left), bst_get_height(node->right));
}


int max_num(const int a, const int b) {
	return a >= b ? a : b;
}


int bst_get_min(BSTNode *node) {
	if (NULL == node)
		return 0;
	BSTNode *current = node;
	while (current->left != NULL)
		current = current->left;
	return current->data;
}

int bst_get_max(BSTNode *node) {
	if (NULL == node)
		return 0;
	BSTNode *current = node;
	while (current->right != NULL)
		current = current->right;
	return current->data;
}
