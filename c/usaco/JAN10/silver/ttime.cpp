#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

/*
LANG:C++
ID:zrfan3
PROG:ttime
*/

int n,m,qu,i,j,a[5000][2],d[1005],ans,x,y,c[1005];

inline int cmp(const void *p,const void*q)
{
    return ((int*) p)[0]-((int*)q)[0];
}

inline void dg(int p)
{
    c[p]=ans;
    if (d[p]>-1)
    {
       for (int k=d[p];;k++)
       {
          if (a[k][0]!=p) break;
           if (c[a[k][1]]==0) dg(a[k][1]);
       }
    }
}

int main()
{
    freopen("ttime.in","r",stdin);
    freopen("ttime.out","w",stdout);
    scanf("%d %d %d",&n,&m,&qu);
    for (i=0;i<m;i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
        a[m+i][0]=a[i][1],a[m+i][1]=a[i][0];
    }
    qsort(a,m*2,sizeof(a[0]),cmp);
    memset(c,0,sizeof(c));
    memset(d,-1,sizeof(d));
    for (i=0;i<m*2;i++)
    {
        if (d[a[i][0]]==-1) d[a[i][0]]=i;
    }
    d[a[0][0]]=0;ans=0;
    for (i=1;i<=n;i++)
    {
        if (c[i]==0)
        {
           ans++;
           dg(i);
        }
    }
    for (i=1;i<=qu;i++)
    {
        scanf("%d %d",&x,&y);
        if (c[x]==c[y]) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
