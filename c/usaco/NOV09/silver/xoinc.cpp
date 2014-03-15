#include<iostream>
#include<cstring>
using namespace std;
int ans[2001][2001];
long a[2001],s[2001];
int n,i,j,k;

int max1(int p,int q)
{
    if (p>q) return p;else return q;
}

/*
ID:zrfan3
PROG:xoinc
LANG: C++
*/
int main()
{
    freopen("xoinc.in","r",stdin);
    freopen("xoinc.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[n-i+1];
    }
    for (i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    memset(ans,0,sizeof(ans));
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            ans[i][j]=max1(ans[i][j],ans[i][j-1]);
            if (i>=j*2-1) ans[i][j]=max1(ans[i][j],s[i]-ans[i-2*j+1][j*2-1]);
            if (i>=2*j) ans[i][j]=max1(ans[i][j],s[i]-ans[i-2*j][j*2]);
        }
    }
    cout<<ans[n][1]<<endl;
    return 0;
}
