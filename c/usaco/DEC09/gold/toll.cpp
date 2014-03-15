#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int i,j,l,n,m,k,x,y,z,l1;
int cost[260],v[260];
int a[255][255],cost1[255][255],dist[255][255];

/*
ID:zrfan3
TASK:toll
LANG:C++
*/
int max1(int p1,int p2,int p3)
{
    int max2=p1>p2?p1:p2;
    return max2>p3?max2:p3;
}

int main()
{
    freopen("toll.in","r",stdin);
    freopen("toll.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    memset(cost,0,sizeof(cost));
    memset(a,0,sizeof(a));
    memset(cost1,0,sizeof(cost1));
    memset(dist,0,sizeof(dist));
    for (i=1;i<=n;i++)
    {
        scanf("%d",&cost[i]);
    }
    for (i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        if (!dist[x][y]||dist[x][y]>z) {dist[x][y]=z,dist[y][x]=z;cost1[x][y]=dist[x][y]+max1(cost[x],cost[y],0);
        cost1[y][x]=cost1[x][y];}
    }
    for (i=1;i<=n;i++) v[i]=i;
    for (i=1;i<=n;i++)
        for (j=i;j>1&&cost[v[j]]<cost[v[j-1]];j--)
        {
            int s=v[j];v[j]=v[j-1],v[j-1]=s;
        }
    for (l1=1;l1<=n;l1++)
    {
        l=v[l1];
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                if (dist[i][l]&&dist[l][j])
                {
                   if (!dist[i][j]||dist[i][j]>=dist[i][l]+dist[l][j])
                   {
                      dist[i][j]=dist[i][l]+dist[l][j];
                      if (!cost1[i][j]||cost1[i][j]>dist[i][j]+max1(cost[i],cost[j],cost[l]))
                         cost1[i][j]=dist[i][j]+max1(cost[i],cost[j],cost[l]);
                   }
                }
    }
    for (i=1;i<=k;i++)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",cost1[x][y]);
    }
    return 0;
}
