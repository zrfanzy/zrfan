#include<iostream>
using namespace std;
int n,i,max1,j;
int a[1005],ans[1005];

int g(int p,int q)
{
    if (p<q) return g(q,p);
    else if (p%q==0) return q;
    else return g(q,p%q);
}

int main()
{
    //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
    cin>>n;
    max1=0;
    for (i=1;i<=n;i++) cin>>a[i];
    for (i=1;i<=n;i++)
    {
        ans[i]=1;
        for (j=1;j<i;j++)
            if (ans[j]>=ans[i])
                if (g(a[i],a[j])>1) ans[i]=ans[j]+1;
        if (ans[i]>max1) max1=ans[i];
    }
    cout<<max1<<endl;
    return 0;
}
