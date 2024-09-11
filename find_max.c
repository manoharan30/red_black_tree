/*******************************************************************************************************************************************************************
*Title			: Find Maximum
*Description		: This function finds the maximum data from the given Red Black tree.
*Prototype		: int find_maximum(tree_t **root, data_t *max);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: max – Maximum data present in the tree is collected via this pointer.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

tree_t* find_maximum(tree_t *root)
{
	//checking condition whether the tree is empty or not.
	if(root==NULL) return NULL;
	tree_t *temp=root;
	//traversing untill leaf node of right sub tree in order to find the maximum data in the RBT.
	while(temp->right!=NULL){
		temp=temp->right;
	}
	//returning a node which has the maximum data RBT.
	return temp;
}
