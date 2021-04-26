#include <bits/stdc++.h>
using namespace std;

const int inf =1e4 +10;
int p[inf];
int dp[inf][inf],m[inf][inf],s[inf][inf];//m 最小运算次数  s最后一次运算位置
int n;//问题长度

void matrixchain(){
    memset(m,0,sizeof(m));
    int i,j,k,r,t;
    for (r=2;r<=n;++r)//处理长度
    {
        for(i=1;i<=n-r+1;++i)//起点位置
        {
            j=i+r-1;//终点位置
            m[i][j]=p[i-1]*p[i]*p[i+1]+m[i+1][j];
            s[i][j]=i;
            for(k=i+1 ;k<=j-1;++k){
                t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (t < m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
            }
        }
    }
}

void print(int s[][inf],int i,int j) {//括号化方案
	if (i == j){
		printf("A%d",i);
	}
	else{
		printf("(");
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		printf(")");
	}
}

int main()
{
    int d;
	scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&d);
        p[i]=d;
    }
    matrixchain();
    printf("%d\n",m[1][n-1]);
    print(s,1,n-1);
    system("pause");
	return 0;
}
// 4
// 10 100 5 50
