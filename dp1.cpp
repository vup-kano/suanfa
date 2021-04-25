#include<iostream>
#include<math.h>  
#include<time.h> 
#include<fstream> 
#include<algorithm>
#include<cstdlib>
using namespace std;

const int Max=1e2 +10 ;
const int Maxn=1e4 +10 ;

int n,m,date[Max][Maxn],dp[Max][Maxn],mark[Max][Maxn],ind;

int i , j , k;

int dp1(){
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            for(k=0;k<=j;++k){
                if(dp[i][j]<dp[i-1][j-k]+date[i][k]){
                    dp[i][j]=dp[i-1][j-k]+date[i][k];
                    mark[i][j]=k;
                }
            }
        }
    }

}


int main(){
    scanf("%d %d",&n,&m);//n=投资 m=项目 
    for(i=0;i<=n;++i){
        for (j=1;j<=m;++j){
            scanf("%d",&ind);
            date[j][i]=ind;
        }
    }
    dp1();
    printf("the most : %d\n",dp[m][n]);
    int t=n;
    for(i=m;i>=1;--i){
        printf("p%d = %d \n",i,mark[i][t]);
        t=t-mark[i][t];
    }
    system("pause");
    return 0;
}
