#include<iostream>
#include<cstdlib>
using namespace std;
int f1[1005][1005],f2[1005][1005],a[1005],i,j,n,l;

int cmp(const void *p,const void *q)
{
    return (*(int *)p)-(*(int *)q);
}

int min1(int p,int q)
{
    return (p>q?q:p);
}

int main()
{
    //freopen("3042.in","r",stdin);
    //freopen("3042.out","w",stdout);
    scanf("%d %d",&n,&l);
    
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a+1,n,sizeof(a[0]),cmp);
    for (i=1;i<=n;i++)
    {
        f1[i][i]=abs(a[i]-l)*(n);
        f2[i][i]=abs(l-a[i])*(n);
    }
    for (j=2;j<=n;j++)
    {
        for (i=1;j+i-1<=n;i++)
        {
            f1[i][i+j-1]=min1(f1[i+1][i+j-1]+(a[i+1]-a[i])*(n-j+1),f2[i+1][i+j-1]+(a[i+j-1]-a[i])*(n-j+1));
            f2[i][i+j-1]=min1(f2[i][i+j-2]+(a[i+j-1]-a[i+j-2])*(n-j+1),f1[i][i+j-2]+(a[i+j-1]-a[i])*(n-j+1));
        }
    }
    printf("%d\n",min1(f1[1][n],f2[1][n]));
    return 0;
}
