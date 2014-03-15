#include<iostream>
using namespace std;
int ans,n;

/*
TASK:bigdance
LANG:C++
ID:zrfan3
*/

void divide(int p,int q)
{
    if (p==q) ;
    else if (p+1==q) ans+=p*q;
    else if (p+2==q) ans+=p*(p+1);
    else
    {
        int mid=p+(q-p)/2;
        if (q-mid-1>mid-p) mid++;
        divide(p,mid);divide(mid+1,q);
    }
}

int main()
{
    ans=0;
    freopen("bigdance.in","r",stdin);
    freopen("bigdance.out","w",stdout);
    scanf("%d",&n);
    divide(1,n);
    printf("%d\n",ans);
    return 0;
}
