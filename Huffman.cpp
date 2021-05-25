#include <bits/stdc++.h>
using namespace std;

int ans = 0 ;
vector<int>tmp;

int main(){
    int n;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int> >cmp;
    for(int i=0 ; i<n; ++i){
        int x;
        scanf("%d",&x);
        cmp.push(x);
    }
    while(cmp.size()>1){
        int x = cmp.top();
        cmp.pop();
        int y = cmp.top();
        cmp.pop();
        tmp.push_back(x);
        tmp.push_back(y);
        ans+=x+y;
        cmp.push(x+y);
    }
    printf("WPL = %d\n",ans);
    for (int i = 0 ; i < tmp.size() ; ++i)
        printf("%d ",tmp[i]);
    printf("\n");
    system("pause");
    return 0;

}
/*
8
5 5 10 10 10 15 20 25 
*/
