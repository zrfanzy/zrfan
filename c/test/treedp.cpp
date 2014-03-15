#include<iostream>
using namespace std;
int i,j,k,ans1,n,m;
int ans[4000][4000];
long a[4000];
long son[4000][4000][2];
long g[4000];

int max(int p,int q){
    if (p>q) return p;
    else return q;   
}

int min(int p,int q){
    if (p>q) return q;
    else return p;   
}

int dg(int p){
int l,q,t,tt;
    if (p>n-m) {
         ans[p][1]=a[p];
         g[p]=1;
    }
    else {
         for (l=1;l<=son[p][0][1];l++){
             dg(son[p][l][1]);
             g[p]=g[p]+g[son[p][l][1]];
         }
         for (t=1;t<=son[p][0][1];t++){
             tt=son[p][t][1];
             for (l=g[p];l>=1;l--){                       
                 for (q=min(g[tt],l);q>=0;q--){
                     ans[p][l]=max(ans[p][l],ans[tt][q]+ans[p][l-q]-son[p][t][2]);
                 }   
             }
         }
    }
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d",&n,&m);
    memset(g,0,sizeof(g));
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        ans[i][j]=-50000;
    for (i=1;i<=n-m;i++){
      scanf("%d",&son[i][0][1]);
      k=son[i][0][1];
      for (j=1;j<=k;j++){
          scanf("%d %d",&son[i][j][1],&son[i][j][2]);
      }
    }
    for (i=n-m+1;i<=n;i++) scanf("%d",&a[i]);
    dg(1);
    ans1=0;
    for (i=1;i<=m;i++) 
         if ((ans[1][i]>=0)&&(ans1<i)) ans1=i;
    cout<<ans1<<endl;
}
