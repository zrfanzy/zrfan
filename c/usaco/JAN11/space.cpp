#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,i,j,ans;
bool v[1005][1005];
char ch;

/*
ID:zrfan33
PROG:space
LANG:C++
*/

void dg(int p,int q)
{
     v[p][q]=false;
     if (p>1&&v[p-1][q]) dg(p-1,q);
     if (q>1&&v[p][q-1]) dg(p,q-1);
     if (p<n&&v[p+1][q]) dg(p+1,q);
     if (q<n&&v[p][q+1]) dg(p,q+1);
}

int main()
{
    freopen("space.in","r",stdin);
    freopen("space.out","w",stdout);
    ans=0;
    scanf("%d ",&n);
    memset(v,false,sizeof(v));
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            ch=getchar();
            if (ch=='*') v[i][j]=true;
        }
        ch=getchar();
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (v[i][j]==true) {dg(i,j);ans++;}
    printf("%d\n",ans);
    return 0;
}
