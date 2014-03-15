#include<iostream>
using namespace std;
int n,i,ans,x1,y1;
bool f[11];
int a[11],b[11];
float k1[11],b1[11],k2,b2;
int l[11];

int dg(int p)
{
    if (p>n) ans++;
    else 
    {
         for (int k=0;k<=n;k++)
             if (f[k])
             {
                 if (p==0)
                 {
                        f[k]=false;
                        l[p]=k;
                        x1=a[k],y1=b[k];
                        dg(p+1);
                        f[k]=true;
                 }
                 else
                 {
                     k2=(float)(b[k]-y1)/(float)(a[k]-x1);
                     b2=y1;
                     if (k2!=0) b2-=k2*x1;
                     bool f1=true;
                     for (i=1;i<=p-1;i++)
                     {
                         if (k1[i]!=k2){
                         float x3=(b2-b1[i])/(k1[i]-k2);
                         if (((x3>x1&&x3<a[k])||(x3>a[k]&&x3<x1))&&
                             ((x3>a[l[i]]&&x3<a[l[i-1]])||(x3>a[l[i]]&&x3>a[l[i-1]])))
                         {f1=false;break;}
                         }
                     }
                     if (f1){x1=a[k],y1=b[k],k1[p]=k2,b1[p]=b2,f[k]=false,l[p]=k,dg(p+1),f[k]=true;}
                 }
             }
    }
    return 0;
}

int main()
{
    freopen("lines.in","r",stdin);
    freopen("lines.out","w",stdout);
    n=0;
    cin>>a[n]>>b[n];
    while (a[n]!=0||b[n]!=0)
    {
          n++;
          cin>>a[n]>>b[n];
    }
    n--;
    memset(f,true,sizeof(f));
    dg(0);
    cout<<ans/2<<endl;
    return 0;
}
