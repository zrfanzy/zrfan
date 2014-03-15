#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int ans[30][30],a[30][30];
int ans1,i,j,n;

int max1(int p,int q)
{
    if (p>q) return p;else return q;
}
/*
ID:zrfan3
TASK:pachinko
LANG:C++
*/

int main()
{
    FILE *fin=fopen("pachinko.in","r");
    FILE *fout=fopen("pachinko.out","w");
    memset(ans,0,sizeof(ans));
    memset(a,0,sizeof(a));
    ans1=0;
    fscanf(fin,"%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
            fscanf(fin,"%d",&a[i][j]);
    ans[1][1]=a[1][1];
    for (i=2;i<=n;i++)
        for (j=1;j<=i;j++)
        {
            ans[i][j]=a[i][j];
            ans[i][j]+=max1(ans[i-1][j],ans[i-1][j-1]);
            if (ans[i][j]>ans1) ans1=ans[i][j];
        }
    fprintf(fout,"%d\n",ans1);
    return 0;
}
