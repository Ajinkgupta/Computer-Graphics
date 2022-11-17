#include<stdio.h>
int adjMat[10][10],size,visited[10];
void creategraph(int nodes)
{
	int scr,dest;
	size=nodes;
	for(scr=0;scr<size;scr++)
	{
		for(dest=0;dest<size;dest++)
		{
			printf("\n%d to %d :",scr,dest);
			scanf("%d",&adjMat[scr][dest]);
		}
	}
}

void resetvisited()
{
	int i;
	for(i=0;i<size;i++)
	 visited[i]=0;
}
void DFS(int start)
{
	int i=0;
	visited[start]=1;
	printf("V%d ",start);
	for(i=0;i<size;i++)
	{
		if(adjMat[start][i]=1 && visited[i]==0)
		{
			DFS(i);
		}
	}
	
}
void BFS(int start)
{
	int q[10],front=0,rear=-1;
	int i,element;
	visited[start]=1;
	q[++rear]=start;
	while(front<=rear)
	{
		element=q[front++];
		printf("V%d  ",element);
		for(i=0;i<size;i++)
		{
			if(adjMat[start][i]=1 && visited[i]==0)
			{
				visited[i]=1;
				q[++rear]=i;
				
			}
		}
	}
}

int main()
{
	creategraph(3);
	resetvisited();
	DFS(0);
	resetvisited();
	BFS(0);
}