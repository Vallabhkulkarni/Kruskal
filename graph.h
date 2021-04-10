#include<limits.h>
#define MAX 10
typedef struct graph{
    int arr[MAX][MAX];
    int size;
}graph;
void init(graph *g,char *filename);
void print(graph g);
void values(graph *g);
void bfs(graph g, int ver);
void dfs(graph g, int ver);


typedef struct edge{
    int s,d,w;
}edge;
edge* insert_edge(graph g ,int* num);
edge * sort_edge(edge* arrays,int sizes);
void swap_edge(edge *s ,edge *d);
edge* kruskal_algo(graph g);

typedef struct queue{
    int rear;
    int front;
    int size;
    int *Q;

}queue;


void initq(queue *q,int len);
int isFull(queue q);
int isEmpty(queue q);
void enqueue(queue *q,int x);
int dequeue(queue *q);

