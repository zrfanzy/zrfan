#include<iostream>
using namespace std;
const int maxn=3000;
const long inf=2147483647;

long cf[maxn][maxn],g[maxn][maxn];
long d[maxn],pre[maxn],list[maxn],mina[maxn],cur[maxn],numb[maxn];
long n,m,maxflow;

int modify(){
    long i=n;
    while (pre[i]!=0) {
          cf[i][pre[i]]+= mina[n];
          cf[pre[i]][i]-= mina[n];
          i=pre[i];
    }
    maxflow+=mina[n];
}

int sap(){
    long i,j,k;
    bool flag;
    i=1;maxflow=0;mina[1]=inf;
    while (d[1]<n) {
          flag=false;k=inf;
          while (cur[i]<=g[i][0]){
                if (cf[i][g[i][cur[i]]]>0 && d[g[i][cur[i]]]+1==d[i]){
                   flag=true,pre[g[i][cur[i]]]=i;
                   if (cf[i][g[i][cur[i]]]<mina[i]) mina[g[i][cur[i]]]=cf[i][g[i][cur[i]]];
                   else mina[g[i][cur[i]]]=mina[i];
                   i=g[i][cur[i]];
                   if (i==n){
                      modify();
                      i=1;
                   }
                }
                else cur[i]++;
          }
          if (!flag){
             numb[d[i]]--;
             if (numb[d[i]]==0) return(0);
             for (j=1;j<=g[i][0];j++)
                 if (cf[i][g[i][j]]>0 && d[g[i][j]]<k) k=d[g[i][j]];
             if (k<inf) d[i]=k+1;
             else d[i]=n;
             cur[i]=1;
             numb[d[i]]++;
             if (i!=1) i=pre[i];
          }
    }
}

int main(){
    long i,a,b,c,open,closed;
    freopen("dinic1.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d",&n,&m);
    memset(cf,0,sizeof(cf));
    memset(g,0,sizeof(g));
    for (i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        cf[a][b]+=c;
        g[a][++g[a][0]]=b;
        g[b][++g[b][0]]=a;
    }
    memset(d,inf,sizeof(d));
    d[n]=0,list[1]=n,open=1,closed=0;
    while (open>closed){
          a=list[++closed];
          for (i=1;i<=g[a][0];i++){
              if (d[a]+1<d[g[a][i]]) list[++open]=g[a][i];d[g[a][i]]=d[a]+1;
          }
    }
    for (i=1;i<=n;i++) numb[d[i]]++;
    sap();
    printf("%Ld\n",maxflow);
    return 0;
}
