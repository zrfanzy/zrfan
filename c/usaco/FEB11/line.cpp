#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

bool all[25];

char ch;
int i,kk,k,l,n,b;

/*
ID:zrfan3
PROG:line
LANG:C++
*/

int main()
{
    freopen("line.in","r",stdin);
    freopen("line.out","w",stdout);
    long long m,j,a[25];
    scanf("%d %d ",&n,&k);
    a[1]=1;
    for (i=2;i<n;i++) a[i]=a[i-1]*i;
    while(k)
    {
            scanf(" %c",&ch);
            memset(all,true,sizeof(all));
            if (ch=='P')
            {
                scanf("%lld ",&m);
                for (i=1;i<=n-1;i++)
                {
                    j=(m-1)/a[n-i];
                    j++;
                    kk=0;
                    for (l=1;l<=n;l++)
                    {
                        if (all[l]) kk++;
                        if (kk==j) {all[l]=false;printf("%d ",l);break;}
                    }
                    m-=a[n-i]*(j-1);
                }
                for (i=1;i<=n;i++)
                    if (all[i]) printf("%d\n",i);
            }
            else
            {
                m=0;
                for (i=1;i<=n-1;i++)
                {
                    scanf("%d",&b);
                    kk=0;
                    for (l=1;l<b;l++)if (all[l]) kk++;
                    all[b]=false;
                    m+=(kk)*a[n-i];
                }
                scanf("%d ",&b);
                printf("%lld\n",m+1);
            }
            k--;
    }
    return 0;
}
