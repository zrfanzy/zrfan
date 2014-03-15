#include<iostream>
using namespace std;
int n,k1,k2,i,i1,j,k,x,z,ans;
int a[205][205];
char y;

int main()
{
    //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
    cin>>n>>k1>>k2;
    scanf("\n");
    for (i=1;i<=k1;i++)
    {
        scanf("l%d %c l%d\n",&x,&y,&z);
        if (y=='p') i1=1; else i1=-1;
        if (a[x][z]!=0&&a[x][z]!=i1) {cout<<"There must be something wrong..."<<endl;return 0;}
        else
        {
            a[x][z]=i1,a[z][x]=i1;
        }
    }
    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                if (a[i][k]!=0&&a[k][j]!=0)
                {
                    i1=a[i][k]*a[k][j];
                    if (a[i][j]!=0&&a[i][j]!=i1){cout<<"There must be something wrong..."<<endl;return 0;}
                    else
                    {
                        a[i][j]=i1,a[j][i]=i1;
                    }
                }
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++)
            if (a[i][j]==1) ans++;
    cout<<ans<<endl;
    for (i=1;i<=k2;i++)
    {
        scanf("l%d l%d\n",&x,&z);
        if (a[x][z]==1) cout<<"Parallel."<<endl;
        else if (a[x][z]==-1) cout<<"Vertical."<<endl;
        else cout<<"No idea."<<endl;
    }
    return 0;
}
