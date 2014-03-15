#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
long n,m;
long left1[100005],right1[100005];
long a[200010][2];
long line[1000005];
bool v[1000000],vv[1000000];

int cmp(const void *p,const void *q){
     return((long *)p)[0]-((long *)q)[0];
}

/*void qsort(long l,long r)
{
    long i = l, j = r, x = a[(int)((l+r)/2)];
    long y;
    do{
        while (a[i]<x) i++;
        while (x<a[j]) j--;
        if (i<=j)){
           y=a[i];a[i]=a[j];a[j]=y;
           y=b[i];b[i]=b[j];b[j]=y;
        }
        i++;j--;
    }
    while (i<=j);
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
};
*/
inline bool ok(long p){
    long i,ans,start,en,j,k;
    for (i=1;i<=n;i++){
        a[i*2-2][0]=p-left1[i];
        a[i*2-1][0]=right1[i]-p;
        a[i*2-2][1]=i;a[i*2-1][1]=i;
    }
    qsort(a,n*2,sizeof(long)*2,cmp);
    ans=0;
    memset(v,false,sizeof(v));
    memset(vv,false,sizeof(vv));
    start=1;en=0;i=0;
    while (i<=n*2-1){
        j=a[i][0];
        if (v[a[i][1]]==false){
           line[++en]=a[i][1];
           v[a[i][1]]=true;
        } 
        else{
           if (vv[a[i][1]]==false){
              if(ans+1>m) return(false);
              else {
                   ans++;
                   for (k=start;k<=en;k++){
                       vv[line[k]]=true;
                   }
                   start=en+1;
              }
           }
           while (a[i+1][0]==j){
            vv[a[++i][1]]=true;v[a[i][1]]=true;
            }
        }
        i++;
    }
    return true;
}

int main(){
    long loop,loop1,i,x,y,max,min,high,low,mid;
    freopen("test1.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&loop);
    for (loop1=1;loop1<=loop;loop1++){
        min=1000001;
        scanf("%d %d",&n,&m);
        for (i=1;i<=n;i++){
            scanf("%d %d",&y,&x);
            left1[i]=y-x,right1[i]=y+x;
            if (y<min) min=y;
        }
        high=min;
        max=1;low=min-max;
        while (!ok(low)){
              high=low-1;
              max*=2;
              low=min-max;
        }
        while (high>low){
          mid =high-(int)((high-low)/2);
          if (ok(mid)) high=mid-1; else low=mid;
        }
        printf("Case %Ld: %Ld\n",loop1,high);
    }
}
