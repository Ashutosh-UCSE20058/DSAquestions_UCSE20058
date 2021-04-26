#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 50

struct queue
{
	int items[size];
	int front;
	int rear;
};

struct queue* createqueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isempty(struct queue* q);

struct node
{
	int vertex;
	struct node* next;
};

struct node* createnode(int);

struct graph
{
	int vertices;
	struct node** adjlists;
	int* visited;
};

void bfs(struct graph* graph1, int initial)
{
	struct queue* q = createqueue();
	
	graph1->visited[initial] = 1;
	enqueue(q, initial)	;
	
	while(!isempty(q))
	{
		
		int currentvertex = dequeue(q);
		printf("Visited %d\n ", currentvertex);
		
		struct node* temp = graph1->adjlists[currentvertex];
		
		while(temp)
		{
			int adjvertex = temp->vertex;
			
			if(graph1->visited[adjvertex]==0)
			{
				graph1->visited[adjvertex]=1;
				enqueue(q,adjvertex);
			}
			temp = temp->next;
		}
	}
}

struct node* createnode(int v)
{
	struct node* newnode = malloc(sizeof(struct node));
	newnode->vertex = v;
	newnode->next = NULL;
	return newnode;
}


struct graph* creategraph(int vertice)
{
	struct graph* graph1 = malloc(sizeof(struct graph));
	graph1->vertices = vertice;
	
	graph1->adjlists = malloc(vertice * sizeof(struct node*));
	graph1->visited = malloc(vertice * sizeof(int));
	
	int i;
	for(i=0;i<vertice;i++)
	{
		graph1->adjlists[i] = NULL;
		graph1->visited[i]=0;
	}
	return graph1;
}

void addedge(struct graph* graph1, int src, int dest)
{
	struct node* newnode = createnode(dest);
	newnode->next = graph1->adjlists[src];
	graph1->adjlists[src] = newnode;
	
	newnode = createnode(src);
	newnode->next = graph1->adjlists[dest];
	graph1->adjlists[dest] = newnode;
}

struct queue* createqueue()
{
	struct queue* q = malloc(sizeof(struct queue));
	q->front=-1;
	q->rear = -1;
	return q;
}


int isempty(struct queue* q)
{
	if(q->rear== -1)
		return 1;
	else
		return 0;
}

void enqueue(struct queue* q, int value)
{
	if(q->rear == size-1)
		printf("\nQueue is full\n");
	else
	{
		if(q->front ==-1)
			q->front=0;
		q->rear++;
		q->items[q->rear] = value;
	}
}

int dequeue(struct queue* q)
{
	int data;
	if(isempty(q))
	{
		printf("Queue is empty");
		data=-1;
	}
	else
	{
		data = q->items[q->front];
		q->front++;
		if(q->front > q->rear)
		{
			printf("Resetting queue ");
			q->front = q->rear = -1;
			
		}
	}
	return data;
}

void printqueue(struct queue* q)
{
	int i=q->front;
	
	if(isempty(q))
	{
		printf("Queue is empty");
	}
	else
	{
		printf("\nQueue contains \n");
		for(i=q->front;i<q->rear + 1; i++)
		{
			printf(" %d ",q->items[i]);
		}
	}
}

int main()
{
	struct graph* graph1 = creategraph(6);
	addedge(graph1,0,1);
	addedge(graph1,0,2);
	addedge(graph1,1,2);
	addedge(graph1,1,4);
	addedge(graph1,1,3);
	addedge(graph1,2,4);
	addedge(graph1,3,4);
	
	bfs(graph1,0);
	
	return 0;
	
}
