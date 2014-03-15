#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;
long long num[750000][2];
long long n,a,b,c,d,e,f,g,h,i,ans,m;
/*
int cmp(const void *p,const void *q){
     if (((long *)p)[0]>((long *)q)[0]) return -1;
     else if (((long *)p)[0]==((long *)q)[0]) 
     {
          if (((long*)q)[1]>((long *)p)[1]) return 1;
          else return -1;
     }
     else if (((long *)p)[0]<((long *)q)[0]) return 1;
}*/
/*
ID:zrfan3
PROG:farmoff
LANG: C++
*/

long long power(long long x,int y,long long z)
{
     long long p=1;
     for (int k=1;k<=y;k++)
     {
         p=(p*x)%z;
     }
     return p;
}

int main()
{
    freopen("farmoff.in","r",stdin);
    freopen("farmoff.out","w",stdout);
    cin>>n>>a>>b>>c>>d>>e>>f>>g>>h>>m;
    for (i=0;i<3*n;i++){
        num[i][1]=(a*power(i,5,d)%d+b*power(i,2,d)%d+c%d)%d;
        num[i][0]=(e*power(i,5,h)%h+f*power(i,3,h)%h+g%h)%h;
    }
    //qsort(num,n*3,sizeof(long long)*2,cmp);
    for (i=n*3-1;i>n*3-n;i--)
        ans=(ans+num[i][1])%m;
    cout<<ans%m<<endl;
    return 0;
}
