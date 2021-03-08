#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
const int Len=105;
const  int INF =99999;
char zd[6]={'A','B','C','D','E','F'};
typedef struct Node{
    int nv ;//点
    int ne ;//边
    int data[Len][Len];
    int visited[Len];
}*graph;

graph creatgraph(int n)//建图
{
    int i,j;
    graph g=(graph)malloc(sizeof(struct Node));
    g->nv=n;
    g->ne=0;
    for (i=0;i<g->nv;++i){
        g->visited[i]=0;
        for (j=0;j<g->nv;++j){
            g->data[i][j]=INF;
        }
    }
    return g;
}

void add(graph g,int s,int e,int pow)//插入边
{
    g->data[s][e]=pow;
    g->data[e][s]=pow;
}

void prime(graph g,int s)//最小生成树
{
    int dst[Len];
    int st;
    int minx;

    for (int i=0;i<g->nv;++i){
        dst[i]=g->data[s][i];
    }
    printf("V%c ",zd[s]);
    g->visited[s]=1;

    for (int i=1 ;i<g->nv;++i){
        minx=INF;
        for (int j=0;j<g->nv;++j){
            if(minx>dst[j]&&g->visited[j]==0){
                st=j;
                minx=dst[j];
            }
        }
        g->visited[st]=1;
        printf("V%c ",zd[st]);
        for (int j=0;j<g->nv;++j){
            if(g->visited[j]==0&&dst[j]>g->data[st][j]){
                dst[j]=g->data[st][j];
            }

        }
    }
    printf("\n");
}
int main (){
    int a,b,s,e,pow,n,m;
    scanf("%d %d",&a,&b);
    graph g=creatgraph(a);
    for (int i=0;i<b;++i){
        scanf("%d %d %d",&s,&e,&pow);
        add(g,s,e,pow);
    }
    scanf ("%d",&n);
    prime(g,n);
    system("pause");
    return 0;
}
