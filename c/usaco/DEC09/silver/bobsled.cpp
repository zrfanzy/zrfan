#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int ans[100005];
int ans2[100005];
int a[100000][2];
int ans1,high,low,mid,i,j,n,m;
const int INF=2000000000;


/*
ID:zrfan3
TASK:bobsled
LANG:C++
*/

int cmp(const void *p,const void *q)
{
    return ((int *)p)[0]-((int *)q)[0];
}

inline int maxbetween(int s1, int s2, int dist) {
  return max(s1, s2) + int((dist - abs(s1 - s2)) / 2);
}

inline int min1(int s1,int s2)
{
        return s1>s2?s2:s1;
}

inline int max1(int s1,int s2)
{
        return s1<s2?s2:s1;
}

int main()
{
    freopen("bobsled.in","r",stdin);
    freopen("bobsled.out","w",stdout);
    scanf("%d %d",&n,&m);
    a[0][0]=0,a[0][1]=1;
    a[m+1][0]=n,a[m+1][1]=INF;
    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    qsort(a,m+2,sizeof(a[1]),cmp);
    
    ans[m+1]=a[m+1][1];
    for (i=m;i>=0;i--)
    {
        ans[i]=min1(ans[i+1]+(a[i+1][0]-a[i][0]),a[i][1]);
    }
    int ans1=0;
    ans2[0]=1;
    for (i=1;i<=m+1;i++)
    {
        ans2[i]=min1(ans[i],ans2[i-1]+(a[i][0]-a[i-1][0]));
        ans1=max1(ans1,
        maxbetween(ans2[i-1],ans2[i],a[i][0]-a[i-1][0]));

    }
    printf("%d\n",ans1);
    return 0;
}
