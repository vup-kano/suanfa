#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn = 1e4 + 10;

struct Edge {
    int u,v,w;
    Edge(){}
    Edge(int u1,int v1,int w1){
        u=u1;v=v1;w=w1;
    }
    bool operator<(Edge tmp)//重载小于号
    {
        return w<tmp.w;
    }
}e[maxn];

int n,m,parent[maxn];
void init()//初始化
{
    for (int i=0;i<m;++i)parent[i]=i;
}
int find(int x)//查找父亲节点
{
    return x==parent[x]?x:find(parent[x]);
}
void Union(int x,int y)//合并
{
    int fx=find(x);
    int fy=find(y);
    parent[fx]=fy;
}
int kruskal(){
  sort(e,e+m);
  init();
  int cnt =0,res=0;
  for (int i=0;i<m;++i){
      if(find(e[i].u)!=find(e[i].v)){
          Union(e[i].u,e[i].v);
          res+=e[i].w;
          cnt++;
      }
      if(cnt>n-1)break;
  }
  return res;
}

int main (){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e[i]=Edge(u,v,w);
    }
    printf("%d\n",kruskal());
    system("pause");
    return 0;
}
