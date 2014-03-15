#include<iostream>
#include<cstring>
using namespace std;
const int inf=0x7fffffff;
const int N=210;
int n,m,i,j,aug,flow,mann,x,y,z,j1,tmp;
bool flag;
int vh[N],map[N][N],his[N],pre[N],di[N],dis[N];

/*
TASK:ditch
ID:zrfan3
LANG:C++
*/

void sap()
{
     vh[0]=m;
     for (i=1;i<=m;i++) di[i]=1;
     flow=0,aug=inf;i=1;
     while (dis[1]<m)
     {
           flag=false;
           his[i]=aug;
           for (j=di[i];j<=m;j++)
               if (map[i][j]&&dis[j]+1==dis[i])
               {
                  flag=true;di[i]=j;
                  if (map[i][j]<aug) aug=map[i][j];
                  pre[j]=i;i=j;
                  if (i==m)
                  {
                      flow+=aug;
                      while (i!=1)
                      {
                            tmp=i,i=pre[i],map[i][tmp]-=aug,map[tmp][i]+=aug;
                      }
                      aug=inf;
                  }
                  break;
               }
           if (flag) continue;
           vh[dis[i]]--;
           if (vh[dis[i]]==0) break;
           mann=m+1;
           for (j=1;j<=m;j++)
               if (map[i][j]&&dis[j]<mann) {mann=dis[j];j1=j;}
           di[i]=j1;
           dis[i]=mann+1;
           vh[dis[i]]++;
           if (i!=1)
           {
                    i=pre[i],aug=his[i];
           }
     }
}

int main()
{
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    while (scanf("%d %d",&n,&m)!=EOF){
    memset(di,0,sizeof(di));
    memset(dis,0,sizeof(dis));
    memset(map,0,sizeof(map));
    memset(his,0,sizeof(his));
    memset(pre,0,sizeof(pre));
    for (i=1;i<=n;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        map[x][y]+=z;
    }
    sap();
    printf("%d\n",flow);
    }
    return 0;
}
