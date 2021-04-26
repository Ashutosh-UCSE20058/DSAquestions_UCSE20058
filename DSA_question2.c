#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;

// Inorder traversal
void inorder(struct node* root){
	if(root==NULL) 
	{
		return ;
	}
	inorder(root->left);
	printf("%d->",root->data);
	inorder(root->right);
}

// Preorder traversal
void preorder(struct node* root){
	if(root==NULL)
	{
		return;
	}
	printf("%d->",root->data);
	preorder(root->left);
	preorder(root->right);
	
}

// Postorder traversal
void postorder(struct node* root){
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d->",root->data);
}

// Create a new Node
struct node* createNode(value) {
  struct node* newest = malloc(sizeof(struct node));
  newest->data = value;
  newest->left = NULL;
  newest->right = NULL;

  return newest;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

//Main of the program
int main() {
  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);
  insertRight(root->right,5);
  insertRight(root->left,6);

	//printing inorder traversal
  printf("Inorder traversal \n");
  inorder(root);
	
	//printing preorder traversal
  printf("\nPreorder traversal \n");
  preorder(root);
	
	//printing postorder traversal
  printf("\nPostorder traversal \n");
  postorder(root);
  
  return 0;
}


#Output
Inorder traversal
4->2->6->1->3->5->
Preorder traversal
1->2->4->6->3->5->
Postorder traversal
4->6->2->5->3->1->
