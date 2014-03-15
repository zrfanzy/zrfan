#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

/*
ID:zrfan3
PROG:tri
LANG:C++
*/

int min1(int p,int q)
{
    return (p>q?q:p);
}
int ans,n,k,now,now1,a[705][705],b[705][705],s[705][705],i,j,k1;

int main()
{
    freopen("tri.in","r",stdin);
    freopen("tri.out","w",stdout);
    bool f=false;
    ans=0;
    scanf("%d %d",&n,&k);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(s,0,sizeof(s));
    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
        {
            scanf("%d",&b[i][j]);
            a[i][j+n-i]=b[i][j];
        }
    for (i=1;i<=n;i++)
    {
        s[i][1]=a[1][i];
        for (j=2;j<=n;j++)
            s[i][j]=s[i][j-1]+a[j][i];
    }
    for (i=1;i<=n;i++)
        for (j=n-i+1;j<=n;j++)
        {
            now=0;now1=0;
            if (min1(n-j+1,i)>=k){
            for (k1=1;k1<=min1(n-j+1,i);k1++)
            {
                now+=s[j+k1-1][i]-s[j+k1-1][i-k1];
                now1+=k1;
                if (k1>=k&&((f==false)||(now/now1>ans)))
                {
                    f=true;ans=now/now1;
                }
            }}
        }
    memset(s,0,sizeof(s));
    for (i=1;i<=n;i++)
    {
        s[i][1]=b[1][i];
        for (j=2;j<=n;j++)
            s[i][j]=s[i][j-1]+b[j][i];
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
        {
            now=0;now1=0;
            if (min1(i-j+1,n-i+1)>=k){
            for (k1=1;k1<=min1(i-j+1,n-i+1);k1++)
            {
                now+=s[j+k1-1][i+k1-1]-s[j+k1-1][i-1];
                now1+=k1;
                if (k1>=k&&((f==false)||(now/now1>ans)))
                {
                    f=true;ans=now/now1;
                }
            }}
        }
    printf("%d\n",ans);
    return 0;
}
