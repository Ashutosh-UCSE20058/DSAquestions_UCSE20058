#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node* leftchild;
	struct node* rightchild;
};

struct node* root = NULL;


//Inserting the data into binary tree
void insert(int data)
{
	struct node* tempnode = (struct node* )malloc(sizeof(struct node));
	struct node* current;
	struct node* parent;
	
	tempnode->data = data;
	tempnode->leftchild = NULL;
	tempnode->rightchild = NULL;
	if(root==NULL){
		root=tempnode;
	}
	else{
		current=root;
		parent=NULL;
		while(1){
			parent=current;
			if(data<parent->data){
				current=current->leftchild;
			if(current==NULL){
				parent->leftchild=tempnode;
				return;
			}
		}
		else{
			current = current->rightchild;
			if(current==NULL){
				parent->rightchild=tempnode;
				return;
			}
		}	
		}
	}
}


//searching the binary tree
struct node* search(int data){
	struct node* current= root;
	while(current!=NULL)
	{
		printf("%d",current->data);
		if(current->data>data){
			current=current->leftchild;
		}
		else
		{
			current=current->rightchild;
		}
		if(current==NULL)
		{
			return NULL;
		}
	}
	return current;
}

//Preorder traversal
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d->",root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}

//Inorder traversal
void inorder(struct node* root)
{
	inorder(root->leftchild);
	printf("%d->",root->data);
	inorder(root->rightchild);
}

//Postorder traversal
void postorder(struct node* root)
{
	if(root!=NULL)
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("%d->",root->data);
	}
}

//Main of the program
int main()
{
	int i;
	//Array of the program
	int array[7]={27,14,35,10,19,31,42};
	for(i=0;i<7;i++)
	{
		insert(array[i]);
		
	}
	i=31;
	struct node* temp = search(i);
	if(temp!=NULL)
	{
		printf("[%d]-> ",temp->data);
		printf("\n");
	}
	else
	{
		printf("\n");
		
		printf("[x] element not found %d ",i);
		
	}
	//printing preorder traversal
	printf("\n Preorder traversal\n");
	preorder(root);
	
	//printing postorder traversal
	printf("\n Postorder traversal\n");
	postorder(root);
	
	//printing inorder traversal
	printf("\n Inorder traversal\n");
	inorder(root);
	
	
	return 0;
}

#Output
273531
[x] element not found 31
 Preorder traversal
27->14->10->19->35->31->42->
 Postorder traversal
10->19->14->31->42->35->27->
 Inorder traversal
