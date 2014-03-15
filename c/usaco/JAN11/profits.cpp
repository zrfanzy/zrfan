#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

/*
ID:zrfan3
PROG:profits
LANG:C++
*/

int n,i,max1,ans,a[100005];

int main()
{
    freopen("profits.in","r",stdin);
    freopen("profits.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    max1=a[1];
    ans=a[1];
    for (i=2;i<=n;i++)
    {
        if (ans<0) ans=a[i];
        else ans+=a[i];
        if (ans>max1) max1=ans;
    }
    printf("%d\n",max1);
    return 0;
}
