#include<iostream>
using namespace std;
const int maxn=15000;
int distx[maxn],disty[maxn],matex[maxn],matey[maxn],q[maxn];
int g[maxn][maxn];

bool bfs(int n){
     bool found=false;
     int fore=1,near=1;
     for (int i=0;i<n;++i){
         if (matex[i]==-1) q[near++]=i;
         distx[i]=0;
         disty[i]=0;
     }
     for (;fore<near;++fore){
         int x=q[fore];
         for (int it=1;it<=g[x][0];it++){
             if (!disty[it]){
                disty[it]=distx[x]+1;
                if (matey[it]==-1) found=true;
                else {
                     distx[matey[it]]=disty[it]+1;
                     q[near++]=matey[it];
                }
             }
         }
     }
     return found;
}

bool dfs(int x){
     for (int it=1;it<=g[x][0];it++){
         if (disty[it]==distx[x]+1){
            disty[it]=0;
            if (matey[it]==-1||dfs(matey[it]))
                return matex[x]=it,matey[it]=x,true;
            }
     }
     return false;
}

int Hopcroft_Karp(int n){
    int res=0;
    fill_n(matex,n,-1);fill_n(matey,n,-1);
    while (bfs(n))
          for (int i=0;i<n;++i){
              if (matex[i]==-1 && dfs(i)) ++res;
          }
          return res;
}

int main(){
    freopen("Hungary3.in","r",stdin);
    freopen("test.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for (;m;--m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u][++g[u][0]]=v;
    }
    printf("%d\n",Hopcroft_Karp(n));
}
