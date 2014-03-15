#include<iostream>
using namespace std;

long ans[2000],a[2000];
long n,i,k;

int main()
{
    freopen("4.in","r",stdin);
    freopen("4.out","w",stdout);
    scanf("%Ld",&n);
    int num=0;
    for (i=1;i<=n;i++){
        k=i;
        while (k%4==0) k=(int)(k/4);
        while (k%5==0) k=(int)(k/5);
        if (k==1) a[++num]=i;
    }
    ans[1]=2;ans[2]=3;
    for (i=3;i<=num;i++){
        if (num%20==0) ans[i]=(ans[i-1]+ans[i-2]-1)%100000000;
        else ans[i]=(ans[i-1]+ans[i-2])%100000000;  
    }
    printf("%Ld\n",ans[num]);
}
