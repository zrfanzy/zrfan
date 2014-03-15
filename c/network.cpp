#include<iostream>
using namespace std;
int n,m,len,i,x,y,z;
long ans[100000];
long son[100000][1000],link[100000][1000];
long start[100000],end[100000],score[100000];
long dfs[200010];
bool visit[10010];

void dfss(long p){
     visit[p]==true;
     long q;
     for (q=1;q<=son[p][0];q++){
         if (!visit[son[p][q]]){
            dfs[++len]=son[p][q];
            start[son[p][q]]=len;
            score[son[p][q]]=link[p][q];
            dfss(son[p][q]);
         }
     }
     end[p]=++len;
}

int main(){
    freopen("network.in","r",stdin);
    freopen("network.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1;i<=n-1;i++){
        scanf("%d %d %d",&x,&y,&z);
        son[x][++son[x][0]]=y;
        son[y][++son[y][0]]=x;
        link[x][son[x][0]]=z;
        link[y][son[y][0]]=z;
    }
    memset(visit,false,sizeof(visit));
    dfs[1]=1;
    start[1]=1;
    dfss(1);
    for (i=1;i<=len;i++){
        printf("%d\n",dfs[i]);        
    }
}
