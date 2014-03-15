#include<iostream>
using namespace std;

int a[505],back[505][505],ans[1005][505],now[505],i,j,k,ans1,n;
int ok[505];
char map[505][505];

void search(int p)
{
     int i;
     if (p>k)
     {
         ans1++;
         for (i=1;i<=k;i++)
             ans[ans1][i]=now[i];
     }
     else
     {
         if (a[p])
         {
             if (p>1)
             {
                     for (i=1;i<=back[now[p-1]][0];i++)
                         if (back[now[p-1]][i]==a[p])
                         {
                             memset(map[p],0,sizeof(map[p]));
                             strcpy(map[p],map[p-1]);
                             bool f=true;
                             for (j=1;j<=back[now[p-1]][0];j++)
                             {
                                 if (ok[back[now[p-1]][j]]>p) f=false;
                                 map[p][back[now[p-1]][j]]='0';
                             }
                             if (!f) continue;
                             now[p]=a[p];
                             search(p+1);
                         }
             }
         }
         else if (p==1)
         {
              for (i=1;i<=n;i++)
                  if (map[0][i]=='1')
                  {
                      memset(map[1],0,sizeof(map[1]));
                      strcpy(map[1],map[0]);
                      //for (j=1;j<=back[i][0];j++)
                      //    map[1][back[i][j]]='0';
                      map[1][i]='0';
                      now[p]=i;
                      search(p+1);
                  }
         }
         else
         {
             for (i=1;i<=back[now[p-1]][0];i++)
             {
                 if (map[p-1][back[now[p-1]][i]]=='1')
                 {
                     memset(map[p],0,sizeof(map[p]));
                     strcpy(map[p],map[p-1]);
                     bool f=true;
                     for (j=1;j<=back[now[p-1]][0];j++)
                     {
                         if (ok[back[now[p-1]][j]]>p) f=false;
                         map[p][back[now[p-1]][j]]='0';
                     }
                     if (!f) continue;
                     now[p]=back[now[p-1]][i];
                     search(p+1);
                 }
             }
         }
     }
}

int main()
{
    freopen("6-3.in","r",stdin);
    freopen("6-3.out","w",stdout);
    scanf("%d\n",&n);
    memset(back,0,sizeof(back));
    for (i=1;i<=n;i++)
    {
         j=0;
         char ch;
         scanf("%d%ch",&k,&ch);
         back[i][++back[i][0]]=k;
         while (ch!='\n')
         {
               scanf("%d%ch",&k,&ch);
               back[i][++back[i][0]]=k;
         }
    }
    memset(map,'1',sizeof(map));
    map[0][n+1]='\0';
    scanf("%d",&k);
    memset(ok,0,sizeof(ok));
    for (i=1;i<=k;i++)
    {
        scanf("%d",&a[i]);
        if (a[i])
        {
           map[0][a[i]]='0';
           ok[a[i]]=i;
        }
    }
    search(1);
    printf("%d\n",ans1);
    for (i=1;i<=ans1;i++)
    {
        for (j=1;j<=k-1;j++)
            printf("%d ",ans[i][j]);
        printf("%d\n",ans[i][k]);
    }
    return 0;
}
