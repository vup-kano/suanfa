#include <bits/stdc++.h>
using namespace std;
const int maxn= 105;
int sc(){
    int x;
    scanf("%d",&x);
    return x;
}
int main(){
    int m,middle,time=0;
    printf("Please enter the total number of tasks m:\n");
    m=sc();
    int t[maxn],dp[maxn],tmp[maxn][maxn],v[maxn];
    memset(v,0,sizeof(v));
    memset(dp,0,sizeof(dp));
    memset(tmp,0,sizeof(tmp));
    printf("Please input the processing time of each task:\n");
    for(int i = 1 ; i <= m ; ++i){
        t[i]=sc();
        time+=t[i];
    }
    middle=time/2;
    for(int i = 1; i <= m; i++){
			for(int j = middle; j >=t[i] ; j--){
                if(dp[j]<=dp[j-t[i]]+t[i]){
                   dp[j]=dp[j-t[i]]+t[i];
                   tmp[i][j]=1;
                }
			}
	}
    printf("The final total processing time T is:\n");
	printf("%d\n",time-dp[middle]);

    printf("The tasks that A machine needs to perform are:\n");
    int ax=dp[middle];
    for(int i = m ; i > 0; i--){
        if(tmp[i][ax]==1){
            printf("%d ",i);
            ax-=t[i];
            v[i]=1;
        }
        if(ax<0)break;
    }
    printf("\n");
    printf("The tasks that B machine needs to perform are:\n");
    int bx=middle;
    for(int i = 1 ; i <= m; i++){
        if(v[i]==0){
            printf("%d ",i);
        }
        if(bx<0)break;
    }
    printf("\n");
    system("pause");
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int maxn= 1e2+10;
// int sc(){
//     int x;
//     scanf("%d",&x);
//     return x;
// }
// int main(){
//     int m,middle,time=0;
//     m=sc();
//     int t[maxn],dp[maxn][maxn];
//     memset(dp,0,sizeof(dp));
//     for(int i = 1 ; i <= m ; ++i){
//         t[i]=sc();
//         time+=t[i];
//     }
//     middle=time/2;
//     for(int i = 1; i <= m; i++){
// 			for(int j = middle; j >=0 ; j--){
//                 if(j>=t[i])
// 				    dp[i][j] = max(dp[i-1][j-t[i]]+t[i], dp[i-1][j]);
//                 else 
//                     dp[i][j]=dp[i-1][j];
// 			}
// 	}
//     for(int i = 1 ; i <= m ; ++i){
//         for(int j = 1 ; j <= middle ; ++j ){
//             printf("%d ",dp[i][j]);
//         }
//         printf("\n");
//     }
// 	printf("%d",time-dp[m][middle]);
//     system("pause");
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
// const int maxn= 1e4+10;
// int sc(){
//     int x;
//     scanf("%d",&x);
//     return x;
// }
// int main(){
//     int m,middle,time=0;
//     m=sc();
//     int t[maxn],dp[maxn];
//     memset(dp,0,sizeof(dp));
//     for(int i = 1 ; i <= m ; ++i){
//         t[i]=sc();
//         time+=t[i];
//     }
//     middle=time/2;
//     for(int i = 1; i <= m; i++){
//             for(int j = middle; j >=t[i] ; j--){
//                 dp[j] = max(dp[j], dp[j-t[i]]+t[i]);
//             }
//     }
//     printf("%d",time-dp[middle]);
//     system("pause");
//     return 0;
// }
