#include<iostream>
#include<algorithm>
using namespace std;

int cmp(const void *p,const void *q){
     return((int *)p)[0]-((int *)q)[0];
}

int i,n,c,s,ans;
long a[20][2];

/*
ID:zrfan3
PROG:allow
LANG: C++
*/

int main()
{
    freopen("allow.in","r",stdin);
    freopen("allow.out","w",stdout);
    cin>>n>>c;
    for(i=0;i<n;i++) 
        cin>>a[i][0]>>a[i][1];
    qsort(a,n,sizeof(long)*2,cmp);
    bool f=true;
  
    ans=0;
    while (f)
    {
          s=c;
          f=false;
          for (i=n-1;i>=0;i--)
          {
              while (a[i][1]&&s-a[i][0]>=0)
              {
                    a[i][1]--;
                    s-=a[i][0];
              }
          }
          for (i=0;i<n;i++)
          {
              if (a[i][1]&&s)
              {
                  a[i][1]--;
                  s-=a[i][0];
                  break;
              }
          }
          if (s<=0) f=true;
          if (f) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
