/***************************************************************************************************************************************************************
*Title		: This the header file for the Red Black Tree
****************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef RBT_H
#define RBT_H
#define SUCCESS 0
#define FAILURE -1

typedef int data_t;        		//typedef integer into data_t for more convenience.

//enums for color of the node.
typedef enum {
	RED,
	BLACK
} CLR;

//structure of the node in red black tree.
typedef struct node
{
	struct node *left;						//pointer to store the left sub tree address.
	data_t data;							//data member.
	struct node *right;						//pointer to store the right sub tree.
	CLR color;								//color member.
	struct node *parent;					//pointer to keep the reference of previous node.
}tree_t;

//function prototype for insertion with clearing violations.
int insert(tree_t **root, data_t item);
//function prototype for deleting a node in red black tree.
int deleten(tree_t **root, data_t item);
//function prototype for finding a maximum node in RBT.
tree_t* find_maximum(tree_t *root);
//function prototype for finding maximum element in RBT.
tree_t* find_minimum(tree_t *root);
//function prototype for deleting a minimum node in RBT.
int delete_minimum(tree_t **root);
//function prototype for deleting a maximum node in RBT.
int delete_maximum(tree_t **root);
//function prototype for inserting a node into tree.
int insert_node(tree_t **root,tree_t *node);
//function prototype to fix violations in RBT.
void violations(tree_t **root,tree_t *node);
//function prototype to do rotate right operation.
void rotate_right(tree_t **root,tree_t *node);
//function prototype to do rotate left operation.
void rotate_left(tree_t **root,tree_t *node);
//function prototype to print the RBT.
void print_tree(tree_t *root);
//function prototype for the left rotation operation.
void leftRotate(tree_t **root, tree_t *x);
//function prototype for the right rotate operation.
void rightRotate(tree_t **root, tree_t *x);
//function prototype for searching a node from the tree.
tree_t* search(tree_t **root,int data);
//function prototype for deleting a node from the tree.
void delete_node(tree_t **root, int data);
//function to fix the double black violations in RBT.
void fix_deletion(tree_t**,tree_t*);
#endif
