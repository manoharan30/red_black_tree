/*******************************************************************************************************************************************************************
*Title			: Find Minimum
*Description		: This function finds the minimum data from the given Red Black tree.
*Prototype		: int find_minimum(tree_t **root, data_t *min);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: min – Minimum data present in the tree is collected via this pointer.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

tree_t* find_minimum(tree_t *root)
{
    //checking condition whether the tree is empty or not.
	if(root==NULL) return NULL;
    tree_t *temp=root;
    //traversing untill leaf node of left sub tree in order to find the minimum data in the RBT.
    while(temp->left!=NULL){
        temp=temp->left;
    }
	//returning a node which has the minimum data RBT.
    return temp;
}


