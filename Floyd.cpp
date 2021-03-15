#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
const int Len=105;
const  int INF =99999;

int g[Len][Len];
int n,m;
void Floyd(){
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            for(int k =1;k<=n;++k){
                if(g[j][k]>g[j][i]+g[i][k]){
                    g[j][k]=g[j][i]+g[i][k];
                }
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    int u,v,w;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=INF;
        }
    }
    for (int i=1;i<=m;++i){
        scanf("%d %d %d",&u,&v,&w);
        g[u][v]=w;
    }
    Floyd();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)printf("g[%d][%d]=%d\n",i,j,g[i][j]);
        }
    }
    system("pause");
    return 0;
}
