/*******************************************************************************************************************************************************************
*Title			: Delete Maximum
*Description		: This function deletes the maximum data from the given Red Black tree.
*Prototype		: int delete_maximum(tree_t **root);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"
int delete_maximum(tree_t **root)
{
	//checking wheteher the tree is empty or not.
	if(*root==NULL){
		printf("Tree is empty.\n");
		return 0;
	}
	//calling find minimum function in order to delete the maximum data from the red black tree.
	tree_t* min=find_maximum(*root);
	//calling delete function to delete the maximum data in RBT.
	deleten(root,min->data);
	printf("Minimum element has been deleted successfully.\n");
	return 0;
}
