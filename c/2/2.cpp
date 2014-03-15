#include<iostream>

using namespace std;
int n,m,t,k,i,time1,j;
long a[3005][5];
bool t1[3005];
long ans[3005];
long gain[3005];
long max1;


int main()
{
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&t,&k);
    for (i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
        for (j=a[i][2];j<=t;j++)
            if (a[i][3]-a[i][1]>gain[j])
               gain[j]=a[i][3]-a[i][1];
    }
    for (i=1;i<=k;i++)
    {
        scanf("%d",&time1);
        t1[time1]=true;
    }
    for (i=0;i<=t;i++)
        if (t1[i])
        {
           for (j=0;j<=i;j++)
           {
               if (gain[i-j]+ans[j]>ans[i])
                  ans[i]=ans[j]+gain[i-j];
           }
           if (ans[i]>max1) max1=ans[i];
        }
    printf("%Ld\n",max1*n);
    return(0);
}
