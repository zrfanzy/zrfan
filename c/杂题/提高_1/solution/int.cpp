#include<iostream>
using namespace std;
int a[20]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int ans[20000],ans2[20000];
int ans1[21];
int i,j,n,p,q,k,l;

int main()
{
    freopen("int.in","r",stdin);
    freopen("int.out","w",stdout);
    cin>>n;
    i=1,j=1;
    while (n>1)
    {
          i++;
          while (n%i==0)
          {
                ans1[++ans1[0]]=i;
                n/=i;
          }
    }
    ans[0]=1;
    ans[1]=1;j=0;
    for (i=ans1[0];i>=1;i--)
    {
        k=a[++j];
        for (l=1;l<ans1[i];l++)
        {
            memset(ans2,0,sizeof(ans2));
            for (p=1;p<=ans[0];p++)
                {ans2[p]+=ans[p]*k;ans2[p+1]+=ans2[p]/10,ans2[p]%=10;}
            p--;
            while (ans2[p+1]>0)
            {p++;
            ans2[p+1]+=ans2[p]/10,ans2[p]%=10;}
            for (q=1;q<=p;q++) ans[q]=ans2[q];
            ans[0]=p;
        }
    }
    for (i=ans[0];i>=1;i--) cout<<ans[i];
    cout<<endl;
    return 0;
}
