#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
  int **M;      // matrix - an vector made of vectors, first * represents the indicator 'i' and 2nd * represents indicator 'j'
  int vertices; // number of elements represented by the graph
  int edges;    // number of edges/connections between the vertices of the graph
} * graph;

graph graphInitiate(int n) // the integer n represents the size of the matrix n*n
{
  int i, j;
  graph friendGraph = malloc(sizeof(*friendGraph)); // allocate for a friendgraph pointer
  friendGraph->vertices = n;
  friendGraph->edges = 0;
  friendGraph->M = malloc(n * sizeof(int *)); // allocate an vector,
  for (i = 0; i < n; i++)
    friendGraph->M[i] = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      friendGraph->M[i][j] = 0;
  return friendGraph;
}

void insertEdge(graph friendGraph, int i, int j)
{
  if (friendGraph->M[i][j] == 0)
  {
    friendGraph->M[i][j] = 1;
    friendGraph->edges++;
  }
}

void removeEdge(graph friendGraph, int i, int j)
{
  if (friendGraph->M[i][j] == 1)
  {
    friendGraph->M[i][j] = 0;
    friendGraph->edges--;
  }
}

void printGraph(graph friendGraph)
{
  int i, j;
  for (i = 0; i < friendGraph->vertices; i++)
  {
    printf("%d:", i);
    for (j = 0; j < friendGraph->vertices; j++)
      printf("%d", friendGraph->M[i][j]);
    printf("\n");
  }
}

int main()
{
  int n = 0, i = 0, j = 0;
  graph friendGraph;
  printf("Informe a dimensão da matrix NxN: ");
  scanf("%d", &n);
  friendGraph = graphInitiate(n);
  while (1)
  {
    printf("Informe o arco a ser inserido, para interromper digite -1:");
    scanf("%d", &i);
    if (i == -1)
      break;
    scanf("%d", &j);
    insertEdge(friendGraph, i, j);
  }
  printGraph(friendGraph);
  return 0;
}