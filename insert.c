/*******************************************************************************************************************************************************************
*Title			: Insertion
*Description		: This function performs inserting the new data into the given Red Black tree.
*Prototype		: int insert(tree_t **root, data_t item);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: item – New data to be inserted into the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"
int insert(tree_t **root, data_t item)
{
	tree_t *new=malloc(sizeof(tree_t));					//creation of new node with given data;
	new->data=item;										//adding the data into the new node.
	new->color=RED;										//making the new node color as red(it is default color).
	new->left=NULL;										//making the left pointer null.
	new->right=NULL;									//making the right pointer as null.
	new->parent=NULL;									//making the parent pointer as null.

	if(insert_node(root,new)){							//calling the insert node function
		violations(root,new);							//checking violations after normal insertion of the new node.
		//Ancestor=* root;
		return 0;
	}
	else{
		printf("INFO:Duplicate elements cannot be inserted into RBT.\n");		//testcase if new node consists the duplicate element which is already present in the RBT.
		free(new);																//freeing the memory allocated for new node.
		return 0;
	}
}

/**
 * @brief function to add nodes into the RBT.
 * @param root root of the RBT.
 * @param node new node which is going to get inserted into the RBT. 
 * @return return zero on failures and non zero values on success.
 */
int insert_node(tree_t **root,tree_t *node){
	//checking wheather the tree is empty or not.
	if(*root==NULL){
		node->color=BLACK;				//changing the root's color to black based on first property of RBT.
		*root=node;						//updating the root.
		return 1;
	}
	tree_t *temp=*root;
	tree_t *parentd=NULL;

	while(temp!=NULL){					//traversing through the leaf of the tree.
		parentd=temp;					//parent node to have the reference of previous node.
		if(node->data<temp->data){		//comparing for left path.
			temp=temp->left;
		}
		else if(node->data>temp->data){	//comparing for right path.
			temp=temp->right;
		}
		else if(node->data==temp->data){	//if duplicate found returning 0.
			return 0;
		}
	}
	//conditional check for new data to store.
	if(node->data>parentd->data){
		parentd->right=node;
	}
	else{
		parentd->left=node;
	}
	//updating new node's parent with previous node.
	node->parent=parentd;
	return 1;
}

/**
 * @brief function to check and fix the violations in red black tree insertion.
 * @param root root of the RBT.
 * @param node new node which is inserted into the RBT. 
 * @return void function.
 */

void violations(tree_t **root,tree_t *node){
	while(node!=*root && node->parent->color==RED){					//base condition for the fix violations function.
		if(node->parent->parent->right==node->parent){				//checking whether the new node parent is right child of its parent 
			tree_t *uncle=node->parent->parent->left;				//storing the new node's parent's sibling node into uncle pointer.
			if(uncle!=NULL&&uncle->color==RED){						//case1:uncle is present and it is red just shifting blackness and no rotations.
				uncle->color=BLACK;						
				node->parent->color=BLACK;
				node->parent->parent->color=RED;
				node=node->parent->parent;
			}
			else{									
				if(node->parent->left==node){						//node is a left child for its parent.
					node=node->parent;								
					rightRotate(root,node);							//right rotation of parent one time.
					//node->color=BLACK;
				}
					node->parent->color=BLACK;						//if parent is right child and node is also right child one left rotation is enough.
					node->parent->parent->color=RED;
					leftRotate(root,node->parent->parent);			//left rotate operation.
			}
		}
		else if (node->parent->parent->left==node->parent){			//mirror case as node parent is left child.
			tree_t *uncle=node->parent->parent->right;				//storing node parent's sibling into uncle node.
			if(uncle!=NULL&&uncle->color==RED){						//case where uncle color is red can fix violation with just shifting the colors.
				uncle->color=BLACK;
				node->parent->color=BLACK;
				node->parent->parent->color=RED;
				node=node->parent->parent;
			}
			else{
				if(node->parent->right==node){						//case where parent is left child and node is right child.
					node=node->parent;
					leftRotate(root,node);							//can fix violation with one left rotate for node parent.
					//node->color=BLACK;
				}
					node->parent->color=BLACK;						//case where parent is left child and node is also left child.
					node->parent->parent->color=RED;
					rightRotate(root,node->parent->parent);			//can fix with one right rotate operation on grand parent of node.
			}
		}
	}

	(*root)->color=BLACK;											//ensuring the root stays always as black colored node.
	return;
}

/**
 * @brief function to do the left rotate operation in between nodes.
 * @param root root of the RBT.
 * @param temp node which is going to be rotated towards left side. 
 * @return void function.
 */
void leftRotate(tree_t **root, tree_t *temp) {
	tree_t *temp1=temp->right;					//stores the node right in temp.
	temp->right=temp1->left;					//update temp left to node's right.

	if(temp1->left!=NULL){
		temp1->left->parent=temp;				//update node's left parent with temp;
	}
	temp1->parent=temp->parent;					//updating the node which is going upward with its grandparent's reference.
	if(temp->parent==NULL){
		*root=temp1;							//checking edge case where temp is a root.
	}
	else if(temp->parent->left==temp){			//updating left pointer of parent if temp is a left child. 
		temp->parent->left=temp1;
	}
	else{
		temp->parent->right=temp1;				//updating right pointer of parent if temp is right child.
	}
	temp1->left=temp;							//attaching the temp node to temp1's left.
	temp->parent=temp1;							//updating the temps's parent with temp1.
}

/**
 * @brief function to do the right rotate operation in between nodes.
 * @param root root of the RBT.
 * @param temp node which is going to be rotated towards right side. 
 * @return void function.
 */
void rightRotate(tree_t **root, tree_t *temp) {
    tree_t *temp1 = temp->left;							//stores the node right in temp.
    temp->left = temp1->right;							//update temp right to node's left.

    if (temp1->right != NULL) {
        temp1->right->parent = temp;					//update node's right parent with temp;
    }

    temp1->parent=temp->parent;							//updating the node which is going upward with its grandparent's reference.

    if (temp->parent==NULL) {
        *root=temp1;        							//checking edge case where temp is a root.
    } 
	else if(temp==temp->parent->right) {
        temp->parent->right=temp1;						//updating right pointer of parent if temp is right child.
    } 
	else{
        temp->parent->left=temp1; 						//updating left pointer of parent if temp is left child.
    }

    temp1->right=temp;									//attaching the temp node to temp1's right.
    temp->parent=temp1;									//updating the temps's parent with temp1.
}