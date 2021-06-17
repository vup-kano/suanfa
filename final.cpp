#include <bits/stdc++.h>
using namespace std;
const int maxn= 1e4+10;
int sc(){
    int x;
    scanf("%d",&x);
    return x;
}
int main(){
    int m,middle,time=0;
    m=sc();
    int t[maxn],dp[maxn];
    memset(dp,0,sizeof(dp));
    for(int i = 1 ; i <= m ; ++i){
        t[i]=sc();
        time+=t[i];
    }
    middle=time/2;
    for(int i = 1; i <= m; i++){
			for(int j = middle; j >=t[i] ; j--){
				dp[j] = max(dp[j], dp[j-t[i]]+t[i]);
			}
	}
	printf("%d",time-dp[middle]);
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
