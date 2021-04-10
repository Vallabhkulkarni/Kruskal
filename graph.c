#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"stack.h"
void init(graph *g,char *filename){
    int size;
    FILE *fp=fopen(filename,"r");
    if(!fp){
            printf("cannot open the file");
            return;
    }
    fscanf(fp,"%d",&size);
   // printf("size of array is %d",size);
    g->size=size;
    for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                fscanf(fp,"%d",&g->arr[i][j]);
            }

    }
    return;
}
void print(graph g){
    for(int i=0;i<g.size;i++){
            for(int j=0;j<g.size;j++){
                printf("%d ",g.arr[i][j]);
            }
            printf("\n");
    }

}


void initq(queue *q,int len){
    q->size=len;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(sizeof(int)*len);
}

int isFull(queue q){
    if(q.rear==q.size-1){
        //printf("Queue is Full");
        return 1;
    }
    else
        return 0;
}

int isEmpty(queue q){
    if(q.front==q.rear){
        //printf("Queue is Empty\n");
        return 1;
    }
    else
        return 0;

}
void enqueue(queue *q,int x)
{
    if(!isFull(*q)){
        q->rear++;
        q->Q[q->rear]=x;
        return;
    }
}

int dequeue(queue *q)
{
    int x = INT_MIN;
    if(!isEmpty(*q)){
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void bfs(graph g, int ver) {
    queue Q;
    initq(&Q, g.size);
    int *v = (int *)calloc(g.size, sizeof(int));
    int k, i;
    enqueue(&Q, ver);
    while(!isEmpty(Q)) {
        k = dequeue(&Q);
        printf("%d ", k);
        v[k] = 1;
        for(i = 0; i < g.size; i++) {
            if(g.arr[k][i] != 0 && v[i] == 0) {
                //v[i] = 1;
                enqueue(&Q, i);
            }
        }
    }
    return;
}
void dfs(graph g, int ver) {
    stack s;
    inits(&s, MAX);
    int k, i=0;
    int *visited = (int *)calloc(g.size, sizeof(int));
    push(&s, ver);
    visited[ver]=1;
    while(!isemptys(s)) {
        k = pop(&s);
        printf("%d ", k);
        for(i = 0; i < g.size; i++) {
            if(g.arr[k][i] != 0 && visited[i] == 0){
                push(&s, i);
                visited[i]=1;
            }
        }
    }
}

edge* kruskal_algo(graph g){
    int d=g.size;
    int* set=(int *)malloc(sizeof(int)*d);
    for(int i=0;i<d;i++){
        set[i]=i;
    }
    int num=0;
    edge* array=(edge *)malloc(sizeof(edge)*(d-1));
    edge* temp = insert_edge(g,&num);
    // edarr will have all edges in sorted order
    // we want only those edges which won't form any cycles
    // we are using array for selecting a few of all
    edge* all_arr = sort_edge(temp,num);
    edge test;
    int i=0,j=0;
    while(i < d-1){
        test = all_arr[j];
        // set of source and destination are different
        if(set[test.s] != set[test.d]){
            array[i] = test;
            // combine set of source and destination
            // if source index is less than destn
            if(set[test.s] < set[test.d]){
                for(int t=0; t < d;t++){
                    if(set[t] == set[test.d]){
                        set[t] = set[test.s];
                    }
                }
            }
            else if(set[test.s] > set[test.d]){
                 for(int t=0; t < d;t++){
                    if(set[t] == set[test.s]){
                        set[t] = set[test.d];
                    }
                 }
            }
            i++;
        }
        j++;
    }
    return array;
}

// inserting the data into edge as source destination and weight from s to d.
edge* insert_edge(graph g ,int* num){
    int d=g.size;
    edge* edge_arr = (edge *)malloc(sizeof(edge)*d*d);
    int count=0;
    for(int i = 0 ;i < d;i++){
        for(int j = 0;j < d;j++){
            edge e;
            if(g.arr[i][j] != 0){
                e.s = i;
                e.d = j;
                e.w = g.arr[i][j];
                edge_arr[count] = e;
                count++;
            }
        }
    }
    /*
    for(int i=0 ; i < count;i++){
        printf("%d -> %d  (%d)\n",edge_arr[i].s,edge_arr[i].d,edge_arr[i].w);
    }
    */
    *num = count;
    return edge_arr;
}

// sort array of edges in increasing order of the weights
edge * sort_edge(edge* arrays,int sizes){
    int index;
    for(int i=0;i < sizes-1 ;i++){
        index = i;
        for(int j=i+1;j < sizes ;j++){
            if(arrays[j].w < arrays[index].w){
                index = j;
            }
        }
        swap_edge(&arrays[index],&arrays[i]);
    }
  //  for(int i=0 ; i < sizes;i++){
    //    printf("%d -> %d  (%d)\n",arrays[i].s,arrays[i].d,arrays[i].w);
    //}

    return arrays;
}

void swap_edge(edge *s ,edge *d){
    edge temp = *s;
    *s = *d;
    *d = temp;
    return ;
}
