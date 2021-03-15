#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
const int Len=105;
const  int INF =99999;

typedef struct Node {
    int nv;
    int ne;
    int data[Len][Len];
    int visited[Len];
}*graph;

graph makegraph(int n){
    int i ,j;
    graph g=(graph)malloc(sizeof(struct Node));
    g->nv=n;
    g->ne=0;
    for (i=0;i<n;++i){
        g->visited[i]=0;
        for(j=0;j<n;++j){
            g->data[i][j]=INF;
        }
    }
    return g;
}

void Instertedge(graph g,int e,int v,int w){
    g->data[e][v]=w;
}
int djs(graph g,int e,int v){
    int dst[Len];
    int st;
    int mixn;
    for (int i=0;i<g->nv;++i){
        dst[i]=g->data[e][i];
    }
    for (int i=0;i<g->nv;++i){
        mixn=INF;
        for (int j=0;j<g->nv;++j){
            if(g->visited[j]==0&&dst[j]<mixn){
                st=j;
                mixn=dst[j];
            }
        }
        g->visited[st]=1;
        for (int j=0;j<g->nv;++j){
            if(g->visited[j]==0&&dst[j]>dst[st]+g->data[st][j]){
                dst[j]=dst[st]+g->data[st][j];
            }
        }
    }
    return dst[v];
}

int main(){
    int  i , j , k , n, m , e , v , w , ne , nv ;
    char qd ,zd;
    scanf("%d %d ",&nv,&ne);
    graph g=makegraph(nv);
    for (int i=0;i<ne;++i){
        scanf("%c %c %d",&qd,&zd,&w);
        getchar();
        e=(int)(qd-97);
        v=(int)(zd-97);
        Instertedge(g,e,v,w);
    }
    printf("From A to H =%d",djs(g,0,7));
    system("pause");
    return 0;
}
