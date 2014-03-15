#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int cmp(const void *p,const void *q){
    if (fabs(((float *)p)[0]-((float *)q)[0])<1e-3){
       if  (((float *)p)[1]>((float *)q)[1]) return 1;
       else return -1;
    } 
    else 
    {
         if  (((float *)p)[0]>((float *)q)[0]) return 1;
         else return -1;
    }
}

int n,i,j,ans1,max1,k;
int a[700],b[700];
float ans[700][2];

int main()
{
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++) 
       cin>>a[i]>>b[i];
    for (i=1;i<=n;i++)
    {
        memset(ans,0,sizeof(ans));
        for (j=i+1;j<=n;j++)
        {
            ans[j-i][0]=(float)(b[i]-b[j])/(float)(a[i]-a[j]); 
            ans[j-i][1]=b[i]-ans[j-i][0]*(float)(a[i]);
        }
        qsort(ans,n-i+1,sizeof(float)*2,cmp);
        ans1=1;k=2;
        while (k<=n-i)
        {
              if (ans[k][0]-ans[k-1][0]<1e-3&&ans[k][1]-ans[k-1][1]<1e-3)
              {
                  ans1++;
              }
              else ans1=1;
              k++;
              if (ans1>max1) max1=ans1;
        }
        if (ans1>max1) max1=ans1;
    }
    cout<<max1+1<<endl;
    return 0;
}
