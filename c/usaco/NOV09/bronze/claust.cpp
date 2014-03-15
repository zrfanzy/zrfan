#include<iostream>
#include<cmath>
int a[2005][2];
int n,i,ans1,ans2,j;
long long f,ans;
/*
ID:zrfan3
TASK:claust
LANG:C++
*/

long long sq(long long p,long long q)
{
     return (p-q)*(p-q);
}

int main()
{
    FILE *fin=fopen("claust.in","r");
    FILE *fout=fopen("claust.out","w");
    fscanf(fin,"%d",&n);
    for (i=1;i<=n;i++)
    {
        fscanf(fin,"%d %d",&a[i][0],&a[i][1]);
    }
    ans1=1,ans2=2,ans=sq(a[1][0],a[2][0])+sq(a[1][1],a[2][1]);
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++)
        {
           f=sq(a[i][0],a[j][0])+sq(a[i][1],a[j][1]);
           if (f<ans)
           {
            ans=f,ans1=i,ans2=j;
           }
        } 
    fprintf(fout,"%d %d\n",ans1,ans2);      
    return 0;
}
