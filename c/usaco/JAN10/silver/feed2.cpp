#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

/*
LANG:C++
ID:zrfan3
PROG:feed2
*/

long ans[105][105];
int k,e,n,i,j,l,a[105][3];

int cmp(const void*p,const void *q)
{
    if (((int *)p)[0]==((int *)q)[0]) return ((int *)p)[1]-((int *)q)[1];
    else return ((int *)p)[0]-((int *)q)[0];
}

int main()
{
    freopen("feed2.in","r",stdin);
    freopen("feed2.out","w",stdout);
    cin>>k>>e>>n;
    for (i=0;i<n;i++) cin>>a[i][0]>>a[i][2]>>a[i][1];
    qsort(a,n,sizeof(a[1]),cmp);
    memset(ans,-1,sizeof(ans));
    for (i=0;i<=a[0][2];i++) {ans[0][i]=i*a[0][1];}
    ans[0][0]=0;
    for (i=0;i<n;i++) ans[i][0]=0;
    for (i=1;i<n;i++)
    {
        for (l=1;l<=k;l++)
        {
            if (ans[i-1][l]>=0) ans[i][l]=ans[i-1][l]+l*(a[i][0]-a[i-1][0]);
            else ans[i][l]=-1;
            for (j=1;j<=a[i][2];j++)
            {
                if (j>l) break;
                if (ans[i-1][l-j]>=0)
                if (ans[i][l]==-1||ans[i-1][l-j]+j*a[i][1]+(l-j)*(a[i][0]-a[i-1][0])<ans[i][l]) 
                ans[i][l]=ans[i-1][l-j]+j*a[i][1]+(l-j)*(a[i][0]-a[i-1][0]);
            }
        }
    }
    cout<<ans[n-1][k]+k*(e-a[n-1][0])<<endl;
    return 0;
}
