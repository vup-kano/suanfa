#include<iostream>
#include<math.h>  
#include<time.h> 
#include<fstream> 
#include<algorithm>
#include<cstdlib>
using namespace std;

const int Max=0x3f3f3f3f;
const int m=9999;
int n;
struct point{
    double x;
    double y;
}p[m];

int a[m];

int cmpx(const point& a ,const point &b){
    return a.x<b.x;
}

int cmpy(int &a,int &b){
    return p[a].y<p[b].y;
}


double min (double a ,double b){
    return a<b ? a:b;
}


double dst(const point& a, const point& b)
{
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double closeset(int low ,int high){
    if(low==high)return Max;
    if(low+1==high)return dst(p[low],p[high]);
    int mid =(low + high )>>1;
    double ans=min(closeset(low,mid),closeset(mid+1,high));
    int i,j,c=0;
    for(i=low ;i<high;++i){
        if(p[i].x>=p[mid].x-ans&&p[i].x<=p[mid].x+ans){
            a[c++]=i;
        }
    }
    sort(a,a+c,cmpy);
    for(i=0;i<c;++i){
        int k=i+7>c ? c : i+7;
        for(j=i+1;j<k;++j){
            ans = min(dst(p[a[i]], p[a[j]]), ans); 
        }
    }
    return ans;
}

double bruteForce()
{
    double res =  Max * 1.0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            res = min(res, dst(p[i], p[j]));
        }
    }
    return res;
}

int main(){
    double x1,y1;
    double mindst,mindst2;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lf %lf",&x1,&y1);
        p[i].x=x1;
        p[i].y=y1;
    }
    sort(p,p+n,cmpx);
    mindst=closeset(0,n-1);
    mindst2=bruteForce();
    printf("min = %lf\n",mindst);
    printf("min = %lf\n",mindst2);
    system ("pause");
    return 0;
}
/*
15
5 10
9 1
10 12
10 19
13 15
15 19
16 20
19 9
24 0
24 12
31 32
32 24
38 29
40 56
45 23
*/
