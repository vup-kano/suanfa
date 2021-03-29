#include <iostream>
#include <vector>
#include<algorithm>
#include<cstdlib>
const int maxn=1e4+10;

void merge(int a[],int left ,int middle,int right){
    int b[maxn];
    int index=0;
    int i=left,j=middle+1;
    while(i<=middle&&j<=right)
    {
        if(a[i]<a[j]){
            b[index]=a[i];
            i++;
            index++;
        }
        else{
            b[index]=a[j];
            j++;
            index++;
        }
    }
    while(i<=middle){
        b[index]=a[i];
        i++;
        index++;
    }
    while(j<=right){
        b[index]=a[j];
        j++;
        index++;
    }
    for(int i0=left;i0<=right;++i0){
        a[i0]=b[i0-left];
    }
}
void mergesort(int a[],int left ,int right)//升序对分
{
    if(left>=right)
        return;
    int middle =(left+right)/2;
    mergesort(a,left,middle);//左对分
    mergesort(a,middle+1,right);//右对分
    merge(a,left,middle,right);//排序

}
int main(){
    int n,m,i,a[maxn];
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    for (i=0;i<n;++i){
        printf("%d ",a[i]);
    }
    system("pause");
    return 0;
}
