#include<iostream>
#include<cstring>
using namespace std;
char ch;
int ans,ans1,x,y,mx,my,i,j1,j2,y1,j;
bool f;
int ne[10005][3],ne1[10005][3];
bool v[105][105]={true};

/*
ID:zrfan3
PROG:milkweed
LANG: C++
*/

int main()
{
    freopen("milkweed.in","r",stdin);
    freopen("milkweed.out","w",stdout);
    scanf("%d %d %d %d\n",&x,&y,&my,&mx);
    memset(v,true,sizeof(v));
    ans=0;ans1=0;
    for (i=y;i>=1;i--)
    {
        for (j=1;j<=x;j++)
        {
            scanf("%c",&ch);
            if (ch=='.'){ans+=1;v[i][j]=false;}
        }
        scanf("\n");
    }
    ne[0][0]=1;
    ne[1][0]=mx;ne[1][1]=my;v[mx][my]=true;
    f=true;
    ans--;
    if (ans==0||ne[0][0]==0) f=false;
    while (f)
    {
         ans1+=1;
         ne1[0][0]=ne[0][0];
         for (i=1;i<=ne[0][0];i++)   {ne1[i][0]=ne[i][0];ne1[i][1]=ne[i][1];}
         memset(ne,0,sizeof(ne));
         for (i=1;i<=ne1[0][0];i++)
         {
             x=ne1[i][0],y=ne1[i][1];
             for (j1=-1;j1<=1;j1++)
                 for (j2=-1;j2<=1;j2++)
                     if (!v[x+j1][y+j2])
                     {v[x+j1][y+j2]=true;y1=++ne[0][0];ne[y1][0]=x+j1;ne[y1][1]=y+j2;ans-=1;}
         }
         if (ans==0||ne[0][0]==0) f=false;
    }
    if (ans!=0) printf("-1\n");
    else printf("%d\n",ans1);
    return 0;
}
