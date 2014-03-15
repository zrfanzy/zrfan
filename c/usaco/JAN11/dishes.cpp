#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,a[10005],b[10005],c[10005],m,p,i,j;

/*
ID:zrfan3
PROG:dishes
LANG:C++
*/

int max1(int a1,int a2)
{
    return (a1>a2?a1:a2);
}

int main()
{
    freopen("dishes.in","r",stdin);
    freopen("dishes.out","w",stdout);
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++) a[i]=n-i+1;
    a[0]=n;
    while (c[0]<n)
    {
          scanf("%d %d",&m,&p);
          if (m==1)
          {
               for (i=a[0];i>=max1(a[0]-p+1,1);i--)
                   b[++b[0]]=a[i];
               a[0]=max1(a[0]-p,0);
          }
          else
          {
               for (i=b[0];i>=max1(b[0]-p+1,1);i--)
                   c[++c[0]]=b[i];
               b[0]=max1(b[0]-p,0);
          }
    }
    for (i=c[0];i>=1;i--) printf("%d\n",c[i]);
    return 0;
}
