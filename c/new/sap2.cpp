#include<iostream>
using namespace std;
const int inf=0x7fffffff;
const int N=210;
int n,m,i,j,x,y,z,aug,tmp,j1,minn,flow;
bool flag;
int map[N][N],di[N],pre[N],dis[N],vh[N],his[N];

void sap_gap(){
     vh[0]=n;
     for(i=1;i<=n;i++) di[i]=1;
     i=1;
     aug=inf;flow=0;
     while(dis[1]<n){
         his[i]=aug;
         flag=false;
         for(j=di[i];j<=n;j++){
             if(map[i][j]>0 && dis[j]+1==dis[i]){
                 flag=true;
                 di[i]=j; 
                 if(map[i][j]<aug) aug=map[i][j];
                 pre[j]=i; 
                 i=j;
                 if(i==n){
                     flow+=aug;
                     while(i!=1){
                             tmp=i;
                             i=pre[i];
                             map[i][tmp]-=aug;
                             map[tmp][i]+=aug;
                     }
                     aug=inf;
                 }
                 break;
             }
         }
         if(flag) continue;
         minn=n-1;
         for(j=1;j<=n;j++){
             if(map[i][j]>0 && dis[j]<minn) { j1=j;minn=dis[j]; }
         }
         di[i]=j1;
         vh[dis[i]]--;
         if(vh[dis[i]]==0) break;
         dis[i]=minn+1;
         vh[dis[i]]++;
         if(i!=1) {
             i=pre[i];
             aug=his[i];
         }
     }
}


int main(){
    freopen("ditch.in","r",stdin);
    freopen("test.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(map,0,sizeof(map));
        memset(dis,0,sizeof(dis));
        memset(his,0,sizeof(his));
        memset(pre,0,sizeof(pre));
        memset(vh,0,sizeof(vh));
        for(i=1;i<=m;i++) {
            scanf("%d%d%d",&x,&y,&z); map[x][y]+=z;
        }
        sap_gap();
        printf("%d\n",flow);
    }
}
