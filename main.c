/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "rbt.h"
int main()
{
	/* Declare the pointers */
	tree_t *root = NULL;					//pointer to store the root of the tree.
	data_t data;
	data_t minimum;
	data_t maximum;
	char option;

	do
	{
		/* Display the menu */
		printf("\n1. Insert\n2. Delete\n3. Find Minimum\n4. Delete Minimum\n5. Find Maximum\n6. Delete Maximum\n");
		int operation;
		//reading user's choice from the menu.
		scanf("%d",&operation);
		getchar();
		switch (operation)
		{
			case 1:
				printf("Enter the data to be inserted into the RB Tree: ");
				//reading the data which is going to be inserted from  the user.
				scanf("%d", &data);
				//calling the insert function with the new data.
				insert(&root, data);
				//calling print tree function with the root address.
				print_tree(root);
				break;
			case 2:
				printf("Enter the data to be deleted from the RB Tree: ");
				//reading the user's input for deleting the node.
				scanf("%d", &data);
				//calling the delete function inorder to delete the node.
				deleten(&root, data);
				//calling the print function to print the tree.
				print_tree(root);
				break;
			case 3:
				//storing the node which having the minimum data in the rbt.
				tree_t* minimum=find_minimum(root);
				//checking condition incase tree is empty.
				if(minimum==NULL){
					printf("tree is empty.");
					break;
				}
				//printing the minimum data.
				printf("Minimum data: %d\n", minimum->data);
				//printing the tree.
				print_tree(root);
				break;
			case 4:
				//function call to delete the node which contains the minimum element in the RBT.
				delete_minimum(&root);
				//function call to print the tree.
				print_tree(root);
				break;
			case 5:
				//function call to find the minimum node.
				tree_t* maximum=find_maximum(root);
				//checking condition when the tree is empty.
				if(maximum==NULL){
					printf("tree is empty.");
					break;
				}
				//printing the minimum data from the tree.
				printf("Maximum data: %d\n", maximum->data);
				//function to print the RBT.
				print_tree(root);
				break;				
			case 6:
				//function call to delete the node which has the maximum data in the tree.
				delete_maximum(&root);
				//function call to print the tree.
				print_tree(root);
				break;				
		}
		printf("\nWant to continue? Press [yY | nN]: ");
		scanf("\n%c", &option);
	}while (option == 'y' || option == 'Y');
	return 0;
}
