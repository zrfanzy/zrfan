#include<iostream>
using namespace std;
long change[500005];
long ans[500005];
long ans1[500005];
long n,c,d,i,j,ans2;
long a,b;

int gcd(long p,long q)
{
    if (p<q) return gcd(q,p);
    else if (p%q==0) return q;
    else return (q,p%q);
}

int main()
{
   /* freopen("5.in","r",stdin);
    freopen("5.out","w",stdout);*/
    cin>>n>>a>>b>>c>>d;
    for (i=1;i<=n;i++) cin>>change[i];
    ans2=1;
    for (i=c+1;i<=n-d;i++)
        if (ans[i]==0)
        {
            memset(ans1,0,sizeof(ans1));
            ans1[0]=1;ans1[1]=i;
            j=change[i];
            while (j!=i)
            {
                  ans1[++ans1[0]]=j;
                  j=change[j];
            }
            for (j=1;j<=ans1[0];j++)
                ans[ans1[j]]=ans1[0];
            ans2=ans2*ans1[0]/gcd(ans2,ans1[0]);
        }
    if (a==1) cout<<(b-1)/ans2+1<<endl;
    else cout<<(b-1)/ans2-(a-2)/ans2<<endl;
    return 0;       
}
