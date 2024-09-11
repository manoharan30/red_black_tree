#include "rbt.h"
char str[6];
/**
 * @brief function to print the RBT in pre-order.
 * @param root root of the RBT. 
 * @return void function.
 */
void print_tree(tree_t *root)
{
     if (root != NULL) {
        if(root->color==0){
            strcpy(str,"RED");
        }
        else{
            strcpy(str,"BLACK");
         }
        printf("%d(%s) ", root->data,str);
        //calling print function for printing in preorder.
        print_tree(root->left);
        print_tree(root->right);
    }
}