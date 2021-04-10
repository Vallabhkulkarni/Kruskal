#include <stdio.h>
#include <stdlib.h>
#include"graph.h"
int main()
{
    graph g;
    init(&g,"am.txt");
    print(g);
    printf("\n");
    bfs(g,0);
    printf("\n");
    dfs(g,0);
     printf("\n");
     edge *ar_algo = kruskal_algo(g);
     for(int i=0 ;i< g.size -1 ;i++){
        printf("%d -> %d  (%d)\n",ar_algo[i].s,ar_algo[i].d,ar_algo[i].w);
     }
    return 0;
}
