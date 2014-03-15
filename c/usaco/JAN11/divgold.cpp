#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int i,j,ans[1000001],a[1000001],n,sum;

/*
ID:zrfan3
PROG:divgold
LANG:C++
*/

int main()
{
    freopen("divgold.in","r",stdin);
    freopen("divgold.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(ans,-1,sizeof(ans));
    ans[0]=1;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for (i=1;i<=n;i++)
        for (j=sum/2-a[i];j>=0;j--)
            if (ans[j]>=0)
            {
                if (ans[j+a[i]]==-1) ans[j+a[i]]=0;
                ans[j+a[i]]+=ans[j];
                ans[j+a[i]]%=1000000;
            }
    for (i=sum/2;i>=0;i--)
        if (ans[i]>=0) {printf("%d\n%d\n",sum-i*2,ans[i]);break;}
    return 0;
}
