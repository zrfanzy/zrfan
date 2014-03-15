#include<iostream>
using namespace std;
long ans,a1,b1,c1,d1,low1,high1,mid1,low,high,mid,n,m,i,ans2;

long ans1(long p)
{
    if (p==1) return (b1%d1);
    else if (p%2==0) {int k=ans1(p/2); return (k*k)%d1;}
    else {int k=ans1(p/2);return (k*k*b1)%d1;}
}

bool ok1(long p)
{
     int k=mid-c1%d1;
     {
         int q=ans1(p);
         if ((q*a1)%d1==k) return true;else return false;
     }
}

bool ok(long p)
{
     high1=m;
     low1=ans;
     while(low1<high1){
       mid1=low1+(high1-low1)/2;
       if(ok1(mid1))
         high1=mid1;
       else
         low1=mid1+1;
     }
     if (ok1(low1)) {ans2=low1;return true;} else return false;
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d %d",&n,&m);
    ans=1;
    for (i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a1,&b1,&c1,&d1);
        high=1297580535;
        low=1297580534;
        while(low < high){
                  mid = low + (high - low) / 2;
                  if(ok(mid))
                  high = mid;
                  else
                  low = mid + 1;
        }
        printf("%d\n",ans=ans2);
    }
    return 0;
}
