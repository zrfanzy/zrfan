#include<iostream>
using namespace std;
long v,n,c,i,j;
long k[10005],m[10005];
long ans[10005];

int main()
{
    freopen("4.in","r",stdin);
    freopen("4.out","w",stdout);
    scanf("%Ld %Ld %Ld",&v,&n,&c);
    for (i=1;i<=n;i++) scanf("%Ld %Ld",&k[i],&m[i]);
    for (i=1;i<=n;i++)
        for (j=c;j>=m[i];j--)
            if (ans[j-m[i]]+k[i]>ans[j]) ans[j]=ans[j-m[i]]+k[i];
    for (i=1;i<=c;i++){
        if (ans[i]>=v)
        {
                     printf("%Ld\n",c-i);
                     exit(0);        
        }
    }
    printf("Impossible\n");
    return(0);
}
