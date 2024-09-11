/*******************************************************************************************************************************************************************
*Title			: Delete Minimum
*Description		: This function deletes the minimum data from the given Red Black tree.
*Prototype		: int delete_minimum(tree_t **root);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"
int delete_minimum(tree_t **root)
{
	//checking condition whether the tree is empty or not.
	if(*root==NULL){
		printf("Tree is empty.\n");
		return 0;
	}
	//calling find minimum function in order to delete the minimum data from RBT.
	tree_t* min=find_minimum(*root);
	//calling the delete function to delete the minimum data from the RBT.
	deleten(root,min->data);
	printf("Minimum element has been deleted successfully.\n");
	return 0;
}
