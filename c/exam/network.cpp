#include<iostream>
using namespace std;
char ch[1000];
long n,m,len,i,x,y,z,d,i1,j1,deep;
long ans[100000];
long son[100000][1000],link[100000][1000];
long start[100000],end[100000],score[100000];
long dfs[200010];
bool visit[100010];
long ans1[4000000];

long ask(long m,long l,long r,long w){
     if (l==r){
        deep=1;
        return(ans1[m]);
     }     
     else {
          long xx=(int)((l+r)/2);
          if (w<=xx){
             return(ask(m*2-1,l,xx,w)+ans1[m]);
          }
          else {
               return(ask(m*2,xx,r,w)+ans1[m]);
          }
     }
}

void insert(long m,long l,long r,long p,long q){
     long xx=(int)(((l+r)/2));
     if ((l==r)||((l>=p)&&(r<=q))){
          ans1[m]+=d;
     }
     else {
          if ((p<=xx)&&(q>=l)) insert(m*2-1,l,xx,p,q);
          if ((q>=xx)) insert(m*2,xx+1,r,p,q);
     }
}

void dfss(long p){
     visit[p]==true;
     long q;
     for (q=1;q<=son[p][0];q++){
         if (!visit[son[p][q]]){
            dfs[++len]=son[p][q];
            start[son[p][q]]=len;
            score[son[p][q]]=link[p][q];
            visit[son[p][q]]=true;
            dfss(son[p][q]);
         }
     }
     end[p]=++len;
     dfs[len]=p;
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
    len=1;
    visit[1]=true;
    dfss(1);
    for (i=1;i<=len;i++){
        printf("%d %d\n",dfs[i],score[i]);        
    }
    for (i=2;i<=n;i++){
        d=score[i];
        insert(1,1,n,start[i],end[i]);
    }
    for (i=1;i<=m;i++){
        scanf("%s %d %d\n",ch,&i1,&j1);
        if (ch[0]=='I') { d=-j1;insert(1,1,n,start[i1],end[i1]);}
        else {
             printf("%Ld\n",abs(ask(1,1,n,start[i1])-ask(1,1,n,start[j1])));
        }
    }
    return(0);
}
