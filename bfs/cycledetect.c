#include <stdio.h>
#define TRUE    1
#define FALSE   0
#define	MAXV		100		/* maximum number of vertices */
#define MAXDEGREE	100		/* maximum outdegree of a vertex */
typedef int bool;
typedef struct {
	int edges[MAXV][MAXDEGREE];	/* adjacency info */
	int degree[MAXV];		/* outdegree of each vertex */
	int nvertices;			/* number of vertices in the graph */
	int nedges;			/* number of edges in the graph */
} graph;

int processed[MAXV];	/* which vertices have been processed */
int discovered[MAXV];	/* which vertices have been found */
int parent[MAXV];		/* discovery relation */

bool finished = FALSE;		/* flag for early search cutoff */

void main()
{
	graph g;
	int i;

	read_graph(&g,FALSE);
	print_graph(&g);

	init_search(&g);
	dfs(&g,1);
	
}
init_graph(graph *g)
{
	int i;				

	g -> nvertices = 0;
	g -> nedges = 0;

	for (i=1; i<=MAXV; i++) g->degree[i] = 0;
}

read_graph(graph *g, bool directed)
{
	int i;				
	int m;				
	int x, y;			

	init_graph(g);
    printf("Enter number of Vertices and number of edges : ");
	scanf("%d,%d",&(g->nvertices),&m);
    
	for (i=1; i<=m; i++) {
	    printf("\nEnter vertices to connect an edge : ");
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}
}

insert_edge(graph *g, int x, int y, bool directed)
{
	if (g->degree[x] > MAXDEGREE)
	    printf("Warning: insertion(%d,%d) exceeds max degree\n",x,y);

	g->edges[x][g->degree[x]] = y;
	printf("%d",y);
	g->degree[x] ++;

	if (directed == FALSE)
		insert_edge(g,y,x,TRUE);
	else
		g->nedges ++;
}
init_search(graph *g)
{
        int i;                         

        for (i=1; i<=g->nvertices; i++) {
                processed[i] = discovered[i] = FALSE;
                parent[i] = -1;
        }
}

dfs(graph *g, int v)
{
	int i;				
	int y;				/* successor vertex */

	if (finished) return;		/* allow for search termination */

	discovered[v] = TRUE;
	p_vertex(v);

	for (i=0; i<g->degree[v]; i++) {
		y = g->edges[v][i];
		if (valid_edge(g->edges[v][i]) == TRUE) {
			if (discovered[y] == FALSE) {
				parent[y] = v;
				dfs(g,y);
			} else 
				if (processed[y] == FALSE)
					p_edge(v,y);
		}
		if (finished) return;
	}

	processed[v] = TRUE;
}
p_vertex(int v)
{
}
find_path(int start, int end, int parents[])
{
	if ((start == end) || (end == -1))
		printf("\n%d",start);
	else {
		find_path(start,parents[end],parents);
		printf(" %d",end);
	}
} 

p_edge(int x, int y)
{
	if (parent[x] != y)
	 {   
	    printf("The graph is cyclic\n");
		printf("Cycle from %d to %d:",y,x);
		find_path(y,x,parent);
		printf("\n\n");
		finished = TRUE;
	}
	
}

bool valid_edge(int e)
{
        return (TRUE);
} 
print_graph(graph *g)   /* print adjacent indices of the graph */
{
	int i,j;			

	for (i=1; i<=g->nvertices; i++) {
		printf("\n %d: ",i);
		for (j=0; j<g->degree[i]; j++)
			printf(" %d",g->edges[i][j]);
		printf("\n");
	}
}