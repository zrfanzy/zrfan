#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int ans[50005];
int a[50005][2];
int i,j,n,low,high,mid,ans1,ans2;
/*
ID:zrfan3
TASK:sgraze
LANG:C++
*/

int cmp(const void *p,const void *q)
{
    return ((int *)p)[0]-((int *)q)[0];
}

int main()
{
    freopen("sgraze.in","r",stdin);
    freopen("sgraze.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%d %d",&a[i][0],&a[i][1]);
    qsort(a,n,sizeof(a[1]),cmp);
    ans1=0;ans2=0;
    for (i=0;i<n;i++)
    {
        if (ans1!=0){
        low=0,high=ans1;
        while (low<high)
        {
              mid = low + (high - low) / 2;
              if(ans[mid]<=a[i][0]) low=mid+1;
              else high=mid;
        }
        if (ans[low]>a[i][0]) low--;}else low=0;
        if (low>=ans1) ans1=low+1;
        if (!ans[low+1]||ans[low+1]>a[i][1]) ans[low+1]=a[i][1];
        printf("%d %d %d\n",a[i][0],a[i][1],low+1);
    }
    printf("%d\n",ans1);
    return 0;
}
