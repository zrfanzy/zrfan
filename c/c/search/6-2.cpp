/*
对于一个超级大（80位）的数n，找出一个最大数p使得p^3+p^2+3p<=n 
*/
#include<iostream>
using namespace std;
char ch[100];
int num[100],a[100],c[100],ans1[100],w,n,i,high,low,mid;

bool ok()
{
     int j,k;
     memset(c,0,sizeof(c));
     for (j=1;j<=w;j++)
         for (k=1;k<=w;k++)
         {
             c[j+k-1]+=a[j]*a[k];
             c[j+k]+=c[j+k-1]/10;
             c[j+k-1]%=10;
         }
     int w1=w*2-1;
     while (c[w1+1]>0)
     {
           w1++;
           c[w1+1]=c[w1]/10;
           c[w1]%=10;
           if (w1>n) return false;
     }//c=a*a
     if (w1>n) return false;
     for (j=1;j<=w;j++)
     {
         c[j]+=a[j];
         c[j+1]+=c[j]/10;
         c[j]%=10;
     }
     while (c[w]>9)
     {
           c[w+1]=c[w]/10;
           c[w]%=10;
           w++;
           if (w>n) return false;
     }//c=p*p+p
     if (w>n) return false;
     if (w>w1) w1=w;
     memset(ans1,0,sizeof(ans1));
     for (j=1;j<=w1;j++)
         for (k=1;k<=w;k++)
         {
             ans1[j+k-1]+=c[j]*a[k];
             ans1[j+k]+=ans1[j+k-1]/10;
             ans1[j+k-1]%=10;
         }
     int w2=w1+w-1;
     while (ans1[w2+1]>0)
     {
           w2++;
           ans1[w2+1]=ans1[w2]/10;
           ans1[w2]%=10;
           if (w2>n) return false;
     }//ans1=(a*a+a)*a=a^3+a^2
     if (w2>n) return false;
     for (j=1;j<=w;j++)
     {
         ans1[j]+=a[j]*3;
         ans1[j+1]+=ans1[j]/10;
         ans1[j]%=10;
     }
     while (ans1[w]>9)
     {
           ans1[w+1]=ans1[w]/10;
           c[w]%=10;
           w++;
           if (w>n) return false;
     }//ans1=a^3+a^2+3*a
     if (w>n) return false;
     if (w>w2) w2=2;
     for (j=n;j>=1;j--)
         if (ans1[j]>num[j]) return false;
         else if (ans1[j]<num[j]) return true;
     return true;
}

int main()
{
    freopen("6-2.in","r",stdin);
    freopen("6-2.out","w",stdout);
    gets(ch);
    n=strlen(ch);
    w=n;
    for (i=1;i<=n;i++)
        num[n-i+1]=(int)ch[i-1]-(int)'0';
    memset(a,0,sizeof(a));
    bool f=true;
    for (i=n;i>=1;i--)
    {
        high=9;low=0;
        while (low<high-1)
        {
            a[i]=mid=low+(high-low)/2;
            if (ok()) low=mid;
            else  high=mid-1; 
        }
        if (f&&low==0) w--;
        else f=false;
        a[i]=low;
    }
    for (i=w;i>=1;i--) printf("%d",a[i]);
    if (w==0) printf("0\n");
    printf("\n");
    return 0;
}
/*
逐位确定*用二分来搜索 
*/ 
