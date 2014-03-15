#include<iostream>
using namespace std;
int a[50005];
int x,i,n,q,low,high,mid;
bool f;

/*
ID:zrfan3
TASK:mnotes
LANG:C++
*/

int main()
{
    freopen("mnotes.in","r",stdin);
    freopen("mnotes.out","w",stdout);
    scanf("%d %d",&n,&q);
    a[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[i]=a[i-1]+x;
    }
    for (i=1;i<=q;i++)
    {
        scanf("%d",&x);
        if (x>=a[n-1]) printf("%d\n",n);
        else
        {
            low=0,high=n-2;f=false;
            while (low<high)
            {
                  mid=low+(high-low)/2;
                  if (a[mid]<=x&&a[mid+1]>x) {printf("%d\n",mid+1);f=true;break;}
                  else if (a[mid]>x) high=mid;
                  else low=mid+1;
            }
            if (!f) printf("%d\n",low+1);
        }
    }
    return 0;
}
