/*******************************************************************************************************************************************************************
*Title			: Deleten
*Description		: This function performs deleting of the given data from the given Red Black tree.
*Prototype		: int delete(tree_t **root, data_t item); 
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: item – Data to be deleted from the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int deleten(tree_t **root, data_t data)
{
	if(*root==NULL){
		return 0;
	}
	delete_node(root,data);
	
}

/**
 * @brief function to do deletion of a node.
 * @param root root of the RBT.
 * @param data data to be deleted from the RBT. 
 * @return void function.
 */
void delete_node(tree_t ** root, int data)
{
    //checking condition whether the tree is empty or not.
    if ( *root == NULL )
    {
        printf("Tree is empty cannot delete anything.\n");
        return;
    }

    tree_t *temp = *root; 
    int valid=1;                    //variable to call the fix violations
    
    while (temp){                   //traversing until temp becomes null.
        if ( temp->data < data ){
            temp=temp->right;       //moving temp to right if temp data is lesser than data.
        }
        
        else if ( temp->data >data ){   //moving temp to left if temp data is greater than data.
            temp=temp->left;
        }
        else{
            //node to be deleted has been found and one of the child is null and another one of it's  child is not null so just replace with child which is present and update the temp also..
            if ( ((temp->left == NULL) && (temp->right != NULL)) || ((temp->left != NULL) && (temp->right == NULL)) ) 
            {
				if ( temp->right ) 
				{
					temp->data = temp->right->data;
					temp = temp->right;
				}
				else  
				{
					temp->data = temp->left->data;
					temp = temp->left;
				}
            }
            //case where the node to be deleted has been found and it has both child,here we can replace node with its preorder predessor or postorder successor and delete the node from there.
            else if((temp->left != NULL) && (temp->right != NULL)) 	
            {
                tree_t* min = find_maximum(temp->left); 
                int minimum = min->data;
                delete_node(root,min->data);  //calling the deleten function recurssively. 
                temp->data = minimum;
                valid= 0; 
            }

            if(valid==1)
            {
				fix_deletion(root,temp);                            //calling fix violations function in order to  fix and balance the properties RBT.
				if(temp->parent !=NULL)
				{
					if(temp->parent->left == temp)
					{
						temp->parent->left = NULL;                  //neutralizing the temp node in case of its left child is null because it got deleted.
					}
					else{
						temp->parent->right = NULL;                 //neutralizing the temp node in case of its right child is null because it got deleted.
					}
				}
				else{
					*root = NULL;                                   //incase root got deleted then make root as null and then free temp.
				}
				free(temp);                                         //freeing the temp node.
            }
            return;
        }
    }
    return;
}


/**
 * @brief function to do balancing and fixing the deletion of a node.
 * @param root root of the RBT.
 * @param temp node which has the double blackness and it needs to get fixed. 
 * @return void function.
 */
void fix_deletion(tree_t **root, tree_t *temp)
{
    while (temp!=*root&&temp->color == BLACK)                   //running a loop until the tree comes back to satisfy all properties of RBT.
    {
        if (temp != NULL && temp->parent != NULL)  // Check if temp and its parent are valid
        {
            if (temp == temp->parent->left)                     //checking whether the node is situated to left of its parent.
            {
                tree_t *bro = temp->parent->right;              //creating a bro node which is a brother of node got deleted.
                if (bro != NULL)
                {
                    if (bro->color == BLACK)                    //checking condition whether the sibling's color is black or not.
                    {
                        //checking the case child is black or null
                        if( ( bro->right == NULL || bro->right->color == BLACK ) && ( bro->left == NULL || bro->left->color == BLACK))
                        {
                            //case where parent color is red
                            if(temp->parent->color == RED)
                            {
                            //swapping colors.
                            temp->parent->color = BLACK;
                            bro->color = RED;
                            break;
                            }
                            else{
                            //swapping colors.
                                bro->color=RED;
                                temp=temp->parent;
                            }
                        }
                        //checking case where sibling's near child is red and sibling's far child is black.
                        else if (bro->left != NULL && bro->left->color == RED &&
                                 (bro->right == NULL || bro->right->color == BLACK))
                        {
                            bro->color = RED;
                            bro->left->color = BLACK;
                            //right rotation operation to bring the nephew closer.
                            rightRotate(root, bro);
                        }
                        //checking case where sibling's near child is black and sibling's far child is red.
                        else if ((bro->right != NULL && bro->right->color == RED) && (bro->left == NULL || bro->left->color == BLACK))
                        {
                            int tc = bro->color;
                            bro->color = temp->parent->color;
                            temp->parent->color = tc;
                            //doing the left rotate operation in order to bring the nephew closer.
                            leftRotate(root, temp->parent);
                            bro->right->color = BLACK;
                            break;
                        }
                       
                    }
                    //checking case where the sibling is red.
                    else if (bro->color == RED)
                    {
                        //just swap color and rotate left.
                        temp->parent->color = RED;
                        bro->color = BLACK;
                        //left rotate operation to balance the tree.
                        leftRotate(root, temp->parent);
                    }
                }
                else{
                    break;
                }
            }
            //checking condition where the temp is a right child.
            else if (temp == temp->parent->right)
            {
                //creating a new bro node which is containing the sibling of the node which is going to get deleted.
                tree_t *bro = temp->parent->left;
                if (bro != NULL)
                {
                    if (bro->color == BLACK)                    //checking condition whether the sibling's color is black or not.
                    {
                        //checking the case child is black or null
                        if( ( bro->left == NULL || bro->left->color == BLACK ) && ( bro->right == NULL || bro->right->color == BLACK))
                        {
                            //case where parent color is red
                            if(temp->parent->color == RED)
                            {
                            //swap colors.
                            temp->parent->color = BLACK;
                            bro->color = RED;
                            break;
                            }
                            else{
                                //swap colors.
                                bro->color=RED;
                                temp=temp->parent;
                            }
                        }
                        //checking case where sibling's far child is red and sibling's near child is black.
                        else if (bro->right != NULL && bro->right->color == RED &&
                                 (bro->left == NULL || bro->left->color == BLACK))
                        {
                            bro->color = RED;
                            bro->right->color = BLACK;
                            //left rotation operation to bring the nephew closer.
                            leftRotate(root, bro);
                        }
                        //checking case where sibling's far child is black and sibling's near child is red.
                        else if ((bro->left != NULL && bro->left->color == RED) && (bro->right == NULL || bro->right->color == BLACK))
                        {
                            int tc = bro->color;
                            bro->color = temp->parent->color;
                            temp->parent->color = tc;
                            //doing the right rotate operation in order to bring the nephew closer.
                            rightRotate(root, temp->parent);
                            bro->left->color = BLACK;
                            break;
                        }
                    }
                    else if (bro->color == RED)
                    {
                        //just swap color and rotate left.
                        temp->parent->color = RED;
                        bro->color = BLACK;
                        //right rotate operation to balance the tree.
                        rightRotate(root, temp->parent);
                    }
                }
                else{
                    break;
                }
            }
        }
    }
    if (*root != NULL)
    {
        (*root)->color = BLACK;  // Ensure the root is always black
    }
}
