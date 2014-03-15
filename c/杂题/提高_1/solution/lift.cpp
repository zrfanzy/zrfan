#include<iostream>
using namespace std;
int f[205][205];
int i,j,k,a,b,n;

int main()
{
    freopen("lift.in","r",stdin);
    freopen("lift.out","w",stdout);
    cin>>n>>a>>b;
    for (i=1;i<=n;i++)
    {
        cin>>j;
        if (i-j>0) f[i][i-j]=1;
        if (i+j<=n) f[i][i+j]=1;
    }
    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                {if (f[i][k]&&f[k][j])
                    if (!f[i][j]||f[i][j]>f[i][k]+f[k][j])
                       f[i][j]=f[i][k]+f[k][j];}
    if (a==b) cout<<0<<endl;
    else if (f[a][b]) cout<<f[a][b]<<endl;
    else cout<<-1<<endl;
    return 0;
}
