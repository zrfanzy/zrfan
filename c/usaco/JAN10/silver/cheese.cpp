#include<iostream>
#include<cstring>
using namespace std;
long ans[1005];
bool f;
long ans1,max1;
int i,j,l,w,n,t,k,a[105][3];

/*
LANG:C++
ID:zrfan3
PROG:cheese
*/

int main()
{
    freopen("cheese.in","r",stdin);
    freopen("cheese.out","w",stdout);
    cin>>n>>t>>k;
    ans1=0;
    for (i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    for (i=1;i<=n;i++)
    {
        max1=0;
        memset(ans,0,sizeof(ans));
        if (a[i][1]>=k) f=true;else f=false;
        for (j=1;j<=n;j++)
        {
            if (f) w=(a[j][1]/5*4);else w=a[j][1];
            for (l=w;l<=t-a[i][1];l++)
            {
                if (ans[l-w]+a[j][0]>ans[l]) ans[l]=ans[l-w]+a[j][0];
                if (ans[l]>max1) max1=ans[l];
            }
        }
        if (max1+a[i][0]>ans1) ans1=max1+a[i][0];
    }
    cout<<ans1<<endl;
    return 0;
}
