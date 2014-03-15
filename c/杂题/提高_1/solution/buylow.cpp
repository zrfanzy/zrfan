#include<iostream>
using namespace std;
int a[5005];
int ans1[5005],ans2[5005];
int n,i,j,maxi;
long max1,max2;
bool f[65540];
bool ff[65540];

int main()
{
    freopen("buylow.in","r",stdin);
    freopen("buylow.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    memset(ans1,0,sizeof(ans1));
    memset(ans2,0,sizeof(ans2));
    max1=0;
    memset(f,false,sizeof(f));
    memset(ff,false,sizeof(ff));
    for (i=1;i<=n;i++)
    {
        memset(f,false,sizeof(f));
        ans1[i]=1,ans2[i]=1;
        for (j=i;j>=1;j--)
        {
            if (a[j]>a[i]&&ans1[j]+1==ans1[i]&&!f[a[j]])
            {
                 ans2[i]+=ans2[j];
                 
                 f[a[j]]=true;
            }
            if (a[j]>a[i]&&ans1[j]+1>ans1[i])
            {
                 ans1[i]=ans1[j]+1,ans2[i]=ans2[j];
                 
                 memset(f,false,sizeof(f));
                 f[a[j]]=true;
            }
        }
    }
    for (i=n;i>=1;i--)
    {
        if (ans1[i]>max1){max1=ans1[i],max2=ans2[i];memset(ff,false,sizeof(ff));ff[a[i]]=true;}
        else if (ans1[i]==max1&&!ff[a[i]]){max2+=ans2[i];ff[a[i]]=true;}
    }
    cout<<max1<<" "<<max2<<endl;
    return 0;
}
