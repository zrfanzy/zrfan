#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,ans;

/*
ID:zrfan3
PROG:sym
LANG:C++
*/

void dg(int p,int q)
{
     if (p%2==1&&q%2==1)
     {
        dg((p-1)/2,(q-1)/2);
        ans*=4;
        ans++;
     }
}

int main()
{
    freopen("sym.in","r",stdin);
    freopen("sym.out","w",stdout);
    scanf("%d %d",&n,&m);
    ans=0;
    dg(n,m);
    printf("%d\n",ans);
    return 0;
}
