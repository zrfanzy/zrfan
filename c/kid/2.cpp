#include<iostream>
using namespace std;

long long a[1005][1005];
long long a1[1005][1005];
long long sum[1005][1005];
long long dp[1005][1005];
long long n,k,i,j,f;
long long ans;

long long max(long long b,long long c)
{
     if (b>c) return b;
     else return c;
}

int main()
{
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) scanf("%d",&a[i][j]);
    sum[n][n]=a[n][n];
    for (i=n-1;i>=1;i--) {
        sum[n][i]=sum[n][i+1]+a[n][i];
        sum[i][n]=sum[i+1][n]+a[i][n];
    }
    for (i=n-1;i>=1;i--)
        for (j=n-1;j>=1;j--) sum[i][j]=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1]+a[i][j];
    for (i=1;i<=n-k+1;i++)
        for (j=1;j<=n-k+1;j++)
            a1[i][j]=sum[i][j]-sum[i+k][j]-sum[i][j+k]+sum[i+k][j+k];
    dp[n-k+1][n-k+1]=a1[n-k+1][n-k+1];
    for (i=n-k;i>=1;i--) {
        dp[n-k+1][i]=max(dp[n-k+1][i+1],a1[n-k+1][i]);
        dp[i][n-k+1]=max(dp[i+1][n-k+1],a1[i][n-k+1]);
    }
    ans=0;
    for (i=n-k;i>=1;i--)
        for (j=n-k;j>=1;j--)
            dp[i][j]=max(dp[i][j],max(dp[i+1][j],max(dp[i][j+1],a1[i][j])));
    for (i=1;i<=n-k+1;i++)
        for (j=1;j<=n-k+1;j++)
            if (a1[i][j]+max(dp[i+k][j],dp[i][j+k])>ans) ans=a1[i][j]+max(dp[i+k][j],dp[i][j+k]);
    printf("%Ld\n",ans);
    return 0;
}
