#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char name[10];
    int key;
    struct node *left, *right;
};
struct node* newNode(char name[10],int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->name,name);
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%s %d \n",root->name, root->key);
        inorder(root->right);
    }
}
struct node* insert(struct node* node,char name[10],int position, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(name,key);
 
    /* Otherwise, recur down the tree */
    if (position==-1)
        node->left = insert(node->left, name,position,key);
    else if (position==1)
        node->right = insert(node->right, name,position,key);
 
    /* return the (unchanged) node pointer */
    return node;
}
int findValue(struct node*root,char str[50])
{
	printf("hi");
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=root;
	char *token=strtok(str,"-");
	while(token!=NULL)
	{printf("%s\n", token);
//		while(temp!=NULL)
//		{printf("hi");
//			if(!strcmp(temp->name,token))
//			{
//				temp=temp->left;
//				break;
//			}
//			temp=temp->left;
//		}
		token = strtok(NULL, "-");
	}
	return temp->key;
}
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node* root = NULL;
    root = insert(root, "root",0,0);
    insert(root,"N1",-1,1);
    insert(root,"N2",1,2);
    insert(root,"N3",-1,3);
    insert(root,"N4",1,4);
    insert(root,"N5",1,5);
    inorder(root);
    //int temp=findValue(root,"root-N1");
   // printf("\n\n\n%d",temp);
 	return 0;   
}