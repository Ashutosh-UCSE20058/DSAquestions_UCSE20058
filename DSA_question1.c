#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
  int data;		// declaring the data the the node will carry
  struct node* left;	
  struct node* right;
};



// Displaying the binary tree
void Displaying(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->data);
  Displaying(root->left);
  Displaying(root->right);
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
struct node* insertleftnode(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertrightnode(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

//Main of the program
int main() {
  struct node* root = createNode(1);
  
  //creating the tree
  insertleftnode(root, 2);
  insertrightnode(root, 3);
  insertleftnode(root->left, 4);

  //displaying the binary tree

  printf("\nDisplaying the binary tree created \n");
  Displaying(root);

  return 0;
}
