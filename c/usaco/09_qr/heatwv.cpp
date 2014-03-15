#include<iostream>
#include<cstring>
bool visit[2505]={false};
int mini,min1,x,y,z,t,c,ts,te,i,k;
int ans[2505];
bool f;
short b[2505][2505];

/*
ID:zrfan3
PROG:heatwv
LANG: C++
*/

int main()
{
    freopen("heatwv.in","r",stdin);
    freopen("heatwv.out","w",stdout);
    scanf("%d %d %d %d",&t,&c,&ts,&te);
    for (i=1;i<=c;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        b[x][y]=z;
        b[y][x]=z;
    }
    visit[ts]=true,min1=0;
    for (i=1;i<=t;i++)
    {
        if (b[ts][i]){
        if (min1==0||min1>b[ts][i]) {min1=b[ts][i],mini=i;}
        ans[i]=b[ts][i];
        }
    }
    f=true;ans[mini]=min1;visit[mini]=true;
    while (mini!=te)
    {
          k=mini;
          for (i=1;i<=t;i++)
          {
              if (!visit[i]&&b[k][i])
                 if (ans[i]==0||ans[i]>ans[k]+b[k][i]) ans[i]=ans[k]+b[k][i];
          }
          min1=0;
          for (i=1;i<=t;i++)
              if (!visit[i]&&ans[i])
                 if (min1==0||min1>ans[i]) {min1=ans[i];mini=i;}
          visit[mini]=true;
          
    }
    printf("%d\n",ans[te]);
    return 0;
}
