#include<iostream>
#include<cstring>
using namespace std;
int dp[100005],dp2[100005];
int a[15],b[15];
int n,v,n1,v1,i,j,k;

/*
ID:zrfan3
LANG:C++
TASK:vidgame
*/
int main()
{
    freopen("vidgame.in","r",stdin);
    freopen("vidgame.out","w",stdout);
    scanf("%d %d",&n,&v);
    memset(dp2,0,sizeof(dp2));
    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&v1,&n1);
        for (j=v1;j<=v;j++) dp[j]=dp2[j-v1];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (j=1;j<=n1;j++) scanf("%d %d",&a[j],&b[j]);
        for (k=1;k<=n1;k++)
            for (j=v;j>=v1+a[k];j--)
                if (dp[j-a[k]]+b[k]>dp[j]) dp[j]=dp[j-a[k]]+b[k];
        for (j=v1;j<=v;j++) if (dp[j]>dp2[j]) dp2[j]=dp[j];
    }
    printf("%d\n",dp2[v]);
    return 0;
}
