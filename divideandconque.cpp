#include<iostream>
#include<math.h>  
#include<time.h> 
#include<fstream> 
#include<algorithm>
#include<cstdlib>
using namespace std;

const int Max=0x3f3f3f3f;
const int m=9999;

int cmpx( int &a , int &b)//升序排序
{
    return a<b;
}

int localData(int a[],int value)//返回value在数组中的位置
{
	int i=0;
	while(a[i]!=value)
		i++;
	return i;
}

void copyData(int a[],int d[],int n)//将数组d复制到数组a
{
	int i;
	for(i=0;i<n;i++)
		a[i]=d[i];
}


int select(int a[],int n , int k){
    int cnt=n/5;
    if(n<=6){
        sort(a,a+n,cmpx);
        return a[k-1];
    }
    else{
        int b[m],c[m],d[m];
        int j=0,t=0;
        for(int i= 0 ; i<n ;++i){
            b[j++]=a[i];
            if((i+1) % 5==0||i==n-1){
                sort(b,b+j,cmpx);
                c[t++]=b[j/2];
                j=0;
            }
        }
        sort(c,c+t,cmpx);
        if(k==localData(a,c[t/2]))
			return c[t/2];
        else if (k<localData(a,c[t/2])){
            int i=0;j=0;
            while(i<n)
			{
				if(a[i]<c[t/2])
					d[j++]=a[i];
				i++;
			}
            n=j;
            copyData(a,d,j);
            return select(a,n,k);
        }
        else {
            int i=0,j=0;
			while(i<n)
			{
				if(a[i]>c[t/2])
					d[j++]=a[i];
				i++;
			}
			k=k-n+j;
			n=j;
			copyData(a,d,j);
			return select(a,n,k);
        }

    }
}

int main(){
    int n,min,a[m],y;
    scanf("%d %d",&n,&min);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    int ans=select(a,n,min);
    printf("%d ",ans);
    system("pause");
    return 0;
}
/*
15 10
17 21 5 23 9 37 15 3 11 25 31 13 29 7 19
*/
