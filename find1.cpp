#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
const int Len=9999;
int T[Len];
int find(int n,int m){
    int ans=0;
        for(int i=0;i<n;++i){
            if(m==T[i]){
                ans=i+1;
                break;
            }
        }
    return ans;
}
int main(){
    int i,j,n,m,ans;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&T[i]);
    }
    while(~scanf("%d",&m),m!=-1){
        ans=find(n,m);
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
