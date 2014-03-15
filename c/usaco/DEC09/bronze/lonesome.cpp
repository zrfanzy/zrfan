#include<iostream>
#include<cmath>
using namespace std;
/*
ID:zrfan3
TASK:lonesome
LANG:C++
*/
int a[505][2];
int i,j,n,ansx,ansy;
double maxans;

double dis(int p,int q)
{
       double f1=(double)(a[i][0])-(double)(a[j][0]),f2=(double)(a[i][1])-(double)(a[j][1]);
       return sqrt(f1*f1+f2*f2);
}

int main()
{
    freopen("lonesome.in","r",stdin);
    freopen("lonesome.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d %d",&a[i][0],&a[i][1]);
    maxans=dis(1,2);
    ansx=1,ansy=2;
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++)
            if ((dis(i,j)-maxans)>1e-6) {maxans=dis(i,j),ansx=i,ansy=j;}
    printf("%d %d\n",ansx,ansy);
    return 0;
}
