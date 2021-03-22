#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
const int Len=9999;
int T[Len];
int find(int n,int m){
    int ans=0;
    int l=0,r=n-1;
    while(l<=r){
            int mid=(l+r)/2;
            if(m==T[mid]){
                ans=mid+1;
                break;
            }
            else if(m>T[mid]){
                l=mid+1;
            }
            else {
                r=mid-1;
            }
    }
    return ans;
}

int main(){
    int i,j,n,m;
    int ans;
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
