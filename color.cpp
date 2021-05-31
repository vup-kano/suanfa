#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+10;
int sc(){
    int n;
    scanf("%d",&n);
    return n;
}

int nv;//顶点
int ne;//边
int color;//颜色数
int a;//起点
int b;//终点
int num[maxn][maxn]={0};//邻接矩阵
int colori[maxn]={0};//颜色
int cou=0;//方案总数

bool blean(int n){
    for (int i = 1 ; i <= nv ; ++i){
        if(num[n][i] && colori[n]==colori[i])
            return false;
    }
    return true;
}

void backtrack(int pv){
    if(pv>nv){
        for(int i = 1 ; i <= nv ; ++i){
            printf("%d ",colori[i]);
        }
        cou++;
        printf("\n");
    }
    else {
        for(int i = 1 ; i <= color ; ++i){
            colori[pv]=i;
            if(blean(pv))
                backtrack(pv+1);
            colori[pv]=0;
        }

    }
}

int main(){
    printf("nv:");
    nv=sc();//输入顶点
    printf("color:");
    color=sc();//输入颜色数
    while(scanf("%d %d",&a,&b)!=EOF){
		if(a==0&&b==0){
			break;
		}
        num[a][b]=1;
		num[b][a]=1;
	}
    backtrack(1);
    if(cou==0)
        printf("NO");
    else
        printf("total=%d\n",cou);
    system("pause");
    return 0;

}
/*
5
4
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5
0 0
*/
