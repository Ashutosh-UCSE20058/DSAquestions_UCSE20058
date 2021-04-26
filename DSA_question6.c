#include<stdio.h>
#include<stdbool.h>
#include<conio.h>
#include<stdlib.h>

#define INF 9999999

//number of vertices in graph
#define V 5

//adjancency matrix for the graph
int G[V][V]={

{0,9,75,0,0},
{9,0,95,19,42},
{75,95,0,51,66},
{0,19,51,0,31},
{0,42,66,31,0}
};

//main of the program
int main()
{
	int noedge;  //number of edges
	int selected[V]; //selected track through out the graph
	
	noedge=0;
	
	selected[0]=true;
	int x;
	int y;
	printf("Edge:Weight\n");
	while(noedge<V-1)  //find all the vertices
	{
		int min=INF;
		x=0;
		y=0;
		int i;
		for(i=0;i<V;i++)
		{
			if(selected[i])
			{
				int j;
				for(j=0;j<V;j++)
				{
					if(!selected[j]&&G[i][j])
					{
						if(min>G[i][j])
						{
							min=G[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
		printf("%d-%d:%d\n",x,y,G[x][y]);
		selected[y]=true;
		noedge++;
	}
	return 0;
}

//Output
Edge:Weight
0-1:9
1-3:19
3-4:31
0-0:0
