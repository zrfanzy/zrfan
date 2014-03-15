#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
/*
ID:zrfan3
PROG:paren
LANG:C++
*/

#define mo 12345678910LL


int ch,n;
long long ans;

long long dg()
{
    long long ans1=0;
    scanf("%d",&ch);n--;
    while (ch==0)
    {
       ans1+=dg();
       scanf("%d",&ch);n--;
    }
    if (ans1==0) ans1=1;else
          {ans1*=2;
           ans1%=mo;}
    return (ans1%mo);
}

int main()
{
    freopen("paren.in","r",stdin);
    freopen("paren.out","w",stdout);
    ans=0;
    scanf("%d",&n);
    while (n)
    {
          scanf("%d",&ch);n--;
          ans+=dg();
          ans%=mo;
    }
    printf("%lld\n",(ans%mo));
    return 0;
}
