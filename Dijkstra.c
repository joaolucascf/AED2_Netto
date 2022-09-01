#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <limits.h>

#define INFINITY INT_MAX / 2

typedef struct graph
{
  int **M;      // matrix - an vector made of vectors, first * represents the indicator 'i' and 2nd * represents indicator 'j'
  int vertices; // number of elements represented by the graph
  int edges;    // number of edges/connections between the vertices of the graph
} * graph;

typedef enum
{
  BLACK,
  BLUE,
  GREEN,
  CYAN,
  RED,
  MAGENTA,
  BROWN,
  LIGHTGRAY,
  DARKGRAY,
  LIGHTBLUE,
  LIGHTGREEN,
  LIGHTCYAN,
  LIGHTRED,
  LIGHTMAGENTA,
  YELLOW,
  WHITE
} COLORS;

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

void textcolor(int letra, int fundo)
{
  __FOREGROUND = letra;
  __BACKGROUND = fundo;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + (__BACKGROUND << 4));
}

graph graphInitiate() // the integer n represents the size of the matrix n*n
{
  int i, j, n;
  system("cls");
  printf("Informe a dimensao da matrix NxN: ");
  scanf("%d", &n);
  graph mainGraph = malloc(sizeof(*mainGraph)); // allocate for a mainGraph pointer
  mainGraph->vertices = n;
  mainGraph->edges = 0;
  mainGraph->M = malloc(n * sizeof(int *)); // allocate an vector,
  for (i = 0; i < n; i++)
    mainGraph->M[i] = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      mainGraph->M[i][j] = 0;
  return mainGraph;
}

void insertEdge(graph mainGraph)
{
  int i, j, n;
  printf("Informe o primeiro vertice: ");
  scanf("%d", &i);
  printf("Informe o segundo vertice: ");
  scanf("%d", &j);
  printf("Informe o peso do arco: ");
  scanf("%d", &n);
  if (mainGraph->M[i][j] == 0)
  {
    mainGraph->M[i][j] = n;
    mainGraph->edges++;
  }
}

void printGraph(graph mainGraph)
{
  int i, j;
  for (i = 0; i < mainGraph->vertices; i++)
  {
    printf("|%d|", i);
    for (j = 0; j < mainGraph->vertices; j++)
      printf("%d:", mainGraph->M[i][j]);
    printf("\n");
  }
  system("pause");
}

void Dijkstra(graph mainGraph, int iniNode)
{
  int i, j, minor;
  int *isOpen = malloc(sizeof(int) * mainGraph->vertices);
  int *dist = malloc(sizeof(int) * mainGraph->vertices);
  int *pred = malloc(sizeof(int) * mainGraph->vertices);
  iniAuxGraph(mainGraph, dist, pred, isOpen, iniNode);
  for (i = 0; i < mainGraph->vertices; i++)
  {
    minor = openMinor(mainGraph, isOpen, dist);
    isOpen[minor] = 0;
    for (j = 0; j < mainGraph->vertices; j++)
    {
      if (mainGraph->M[minor][j] != 0 && (mainGraph->M[minor][j] + dist[minor]) < dist[j])
      {
        dist[j] = mainGraph->M[minor][j] + dist[minor];
        pred[j] = minor;
      }
    }
  }
  for (i = 0; i < mainGraph->vertices; i++)
  {
    if (i != iniNode)
    {
      printf("distancia ao vertice %d: %d\n", i, dist[i]);
      j = i;
      printf("Caminho: %d", j);
      while (j != iniNode)
      {
        printf("<-%d", pred[j]);
        j = pred[j];
      }
      printf("\n");
    }
  }
  system("pause");
  free(isOpen);
  free(dist);
  free(pred);
}

int openMinor(graph mainGraph, int *isOpen, int *dist)
{
  int i, minor = 0;
  for (i = 0; i < mainGraph->vertices; i++)
  {
    if (isOpen[i])
    {
      minor = i;
      break;
    }
  }
  for (i = minor + 1; i < mainGraph->vertices; i++)
    if (isOpen[i] && dist[i] < dist[minor])
      minor = i;
  return minor;
}

void iniAuxGraph(graph mainGraph, int *d, int *p, int *isOpen, int iniNode)
{
  int i;
  for (i = 0; i < mainGraph->vertices; i++)
  {
    isOpen[i] = 1;
    d[i] = INFINITY;
    p[i] = -1;
  }
  d[iniNode] = 0;
}

int main()
{
  int li = 1, tecla, choice = 0, iniNode;

  graph mainGraph = NULL;
  for (;;)
  {
    for (;;)
    {
      switch (li)
      {
      case 1:
        system("cls");
        printf("\t\tMENU\n");
        textcolor(0, 15);
        printf("\tInicializar Grafo\n");
        textcolor(15, 0);
        printf("\tEncontrar Menor Caminho\n");
        printf("\tMostrar Matriz\n");
        printf("\tSair\n");
        break;
      case 2:
        system("cls");
        printf("\t\tMENU\n");
        printf("\tInicializar Grafo\n");
        textcolor(0, 15);
        printf("\tEncontrar Menor Caminho\n");
        textcolor(15, 0);
        printf("\tMostrar Matriz\n");
        printf("\tSair\n");
        break;
      case 3:
        system("cls");
        printf("\t\tMENU\n");
        printf("\tInicializar Grafo\n");
        printf("\tEncontrar Menor Caminho\n");
        textcolor(0, 15);
        printf("\tMostrar Matriz\n");
        textcolor(15, 0);
        printf("\tSair\n");
        break;
      case 4:
        system("cls");
        printf("\t\tMENU\n");
        printf("\tInicializar Grafo\n");
        printf("\tEncontrar Menor Caminho\n");
        printf("\tRemover Series\n");
        textcolor(0, 15);
        printf("\tSair\n");
        textcolor(15, 0);
        break;
      }
      tecla = 0;
      tecla = getch();
      if (tecla == 224)
        tecla = getch();
      if (tecla == 72)
        li--;
      else if (tecla == 80)
        li++;
      else if (tecla == 13)
        break;
      if (li > 6)
        li = 1;
      else if (li < 1)
        li = 6;
    }
    system("cls");
    switch (li)
    {
    case 1:
      mainGraph = graphInitiate();
      for (;;)
      {
        system("cls");
        printf("Inserir arco? 1-Sim 2-Nao\n");
        printf("Escolha: ");
        scanf("%d", &choice);
        if (choice == 1)
          insertEdge(mainGraph);
        if (choice == 2)
          break;
      }
      system("pause");
      break;
    case 2:
      system("cls");
      if (mainGraph == NULL)
      {
        printf("\nEi! Voce esta pulando etapas, primeiro inicialize o grafo.\n");
        system("pause");
        break;
      }
      for (;;)
      {
        printf("Informe o vertice inicial: ");
        scanf("%d", &iniNode);
        if (iniNode >= 0 && iniNode <= mainGraph->vertices)
          break;
        else
        {
          printf("\nVertice invalido, favor informar novamente.\n");
          system("pause");
        }
      }
      Dijkstra(mainGraph, iniNode);
      break;
    case 3:
      printGraph(mainGraph);
      break;
    case 4:
      free(mainGraph);
      return 0;
      break;
    }
  }
  return 0;
}
/*int **cost = malloc(mainGraph->vertices * sizeof(int *));
  for (i = 0; i < mainGraph->vertices; i++)
    for (j = 0; j < mainGraph->vertices; j++)
      cost[i] = malloc(mainGraph->vertices * sizeof(int *));
  for (i = 0; i < mainGraph->vertices; i++)
    for (j = 0; j < mainGraph->vertices; j++)
    {
      if (mainGraph->M[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = mainGraph->M[i][j];
    }
    */