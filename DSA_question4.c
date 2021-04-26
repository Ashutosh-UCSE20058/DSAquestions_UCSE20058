#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


//structure of the node
struct node
{
int data;
struct node* left;
struct node* right;
}*root;

// Function to create a new node
struct node *newest(int item)
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->data = item;
temp->left = temp->right = NULL;
return temp;
}

//function for minimum value node
struct node * minvaluenode(struct node* node)
{
struct node* current = node;
/* loop down to find the leftmost leaf */
while (current->left != NULL)
current = current->left;
return current;
}

//function to delete the node
struct node* delete_node(struct node* root, int data)
{
if (root == NULL)
return root;
// Key deleted , if key < root key
if (data < root->data)
root->left = delete_node(root->left, data);
//key deleted, if key> root key
else if (data > root->data)
root->right = delete_node(root->right, data);
else
{
// node with only one child or no child
if (root->left == NULL)
{
struct node *temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL)
{
struct node *temp = root->left;
free(root);
return temp;
}
// node with two children:
struct node* temp = minvaluenode(root->right);
// Copy the inorder successor's content to this node
root->data = temp->data;
// Delete the inorder successor
root->right = delete_node(root->right, temp->data);
}
return root;
}

// inorder traversal of BST
void inorder(struct node *root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

//insert a newnode with given value in BST
struct node* insert(struct node* node, int data)
{
//If the tree is empty return a new node
if (node == NULL)
return newest(data);

if (data < node->data)
node->left = insert(node->left, data);
else if (data > node->data)
node->right = insert(node->right, data);
return node;
}

// Main Function
int main()
{
int n;
root = NULL;
printf("\nEnter the number of nodes : ");
scanf("%d", &n);
int i;
int data;
printf("\nInput the nodes of the binary search tree : ");
if(n > 0)
{
scanf("%d", &data);
root = insert(root, data);
}
for(i = 1; i < n; i++)
{
scanf("%d", &data);
insert(root, data);
}
printf("\nInorder traversal of the BST : ");
inorder(root);
printf("\n");
int del_ele;
printf("\nEnter the node to be deleted : ");
scanf("%d", &del_ele);
delete_node(root, del_ele);
printf("\nInorder traversal after deletion : ");
inorder(root);
printf("\n");
return 0;
}

//Output
Enter the number of nodes : 5

Input the nodes of the binary search tree : 1
2
3
4
5

Inorder traversal of the BST : 1 2 3 4 5

Enter the node to be deleted : 3

Inorder traversal after deletion : 1 2 4 5
