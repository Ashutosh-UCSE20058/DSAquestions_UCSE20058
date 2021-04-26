#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//structure of the node
struct node
{
	int vertex;
	struct node* next;
};

struct node* createnode(int v);

//structure of the graph
struct graph
{
	int vertices;
	int* visited;
	
	struct node** adjlists;
};

//function for depth-first-search
void DFS(struct graph* graph1, int vertex)
{
	struct node* adjlists = graph1->adjlists[vertex];
	struct node* temp = adjlists;
	
	graph1->visited[vertex] = 1;
	
	printf("Visited %d  \n\n",vertex);
	
	while(temp!=NULL)
	{
		int connectedvertex;
		connectedvertex = temp->vertex;
		if(graph1->visited[connectedvertex]==0)
		{
			DFS(graph1, connectedvertex);
		}
		temp = temp->next;
	}
}

//function to create node for graph
struct node* createnode(int v)
{
	struct node* newnode = malloc(sizeof(struct node));
	newnode->vertex = v;
	newnode->next = NULL;
	return newnode;
}

//function to create the graph for dfs
struct graph* creategraph(int vertice)
{
	struct graph* graph1 = malloc(sizeof(struct graph));
	graph1->vertices = vertice;
	graph1->adjlists = malloc(vertice * sizeof(struct node*));
	graph1->visited = malloc(vertice * sizeof(int));
	
	int i;
	for(i=0;i<vertice;i++)
	{
		graph1->adjlists[i]=NULL;
		graph1->visited[i] = 0;
	}
	return graph1;
}

//function to add edges 
void addedge(struct graph* graph1, int src, int dest)
{
	struct node* newnode = createnode(dest);
	newnode->next = graph1->adjlists[src];
	graph1->adjlists[src] = newnode;
	
	newnode = createnode(src);
	newnode->next = graph1->adjlists[dest];
	graph1->adjlists[dest] = newnode;
}

//function to print the graph
void printgraph(struct graph* graph1)
{
	int v;
	for(v=0;v<graph1->vertices;v++)
	{
		struct node* temp = graph1->adjlists[v];
		printf("\n Adjacency list of vertices \n");
		while(temp)
		{
			printf("%d->  ",temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}

//main of the program
int main()
{
	struct graph* graph1 = creategraph(4);
	//the graph
	addedge(graph1,0,1);
	addedge(graph1,0,2);
	addedge(graph1,1,2);
	addedge(graph1,2,3);
	printgraph(graph1);
	
	//printing the shortest path through all the node in graph
	DFS(graph1,2);
	return 0;
}


//Output
 Adjacency list of vertices
2->  1->

 Adjacency list of vertices
2->  0->

 Adjacency list of vertices
3->  1->  0->

 Adjacency list of vertices
2->
Visited 2

Visited 3

Visited 1

Visited 0
