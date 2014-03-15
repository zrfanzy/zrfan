#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int a[405],b[405],c[405],x,y,z,r,i,j,n,ans[405];

/*
ID:zrfan3
PROG:cropcir
LANG:C++
*/

int main()
{
    freopen("cropcir.in","r",stdin);
    freopen("cropcir.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d %d %d",&a[i],&b[i],&c[i]);
    memset(ans,0,sizeof(ans));
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (i!=j)
            {
                x=a[i]-a[j];if (x<0) x*=-1;
                y=b[i]-b[j];if (y<0) y*=-1;
                z=x*x+y*y;r=c[i]+c[j];
                if (z<=(r*r)) ans[i]++;
            }
    for (i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
