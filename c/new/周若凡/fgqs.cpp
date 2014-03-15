#include<iostream>
#include<cstring>
using namespace std;
const int num[6]={1,2,4,8,16,32};
int ans[35][10005];
int zt[6];
int max1;
int i,j,n,m,nn,ans1,xx;
int a[6][10005];
int zt1[35][6];
bool zt2[35][35];

const int inf=0x7fffffff;
const int N=2005;
int x,y,z,aug,tmp,j1,minn,flow;
bool flag;
int map[N][N],di[N],pre[N],dis[N],vh[N],his[N];

void sap_gap(){
     vh[0]=nn;
     for(i=1;i<=nn;i++) di[i]=1;
     i=1;
     aug=inf;flow=0;
     while(dis[1]<nn){
         his[i]=aug;
         flag=false;
         for(j=di[i];j<=nn;j++){
             if(map[i][j]>0 && dis[j]+1==dis[i]){
                 flag=true;
                 di[i]=j; 
                 if(map[i][j]<aug) aug=map[i][j];
                 pre[j]=i; 
                 i=j;
                 if(i==nn){
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
         minn=nn-1;
         for(j=1;j<=nn;j++){
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

int main()
{
    freopen("fgqs.in","r",stdin);
    freopen("fgqs.out","w",stdout);
    scanf("%d %d",&m,&n);

    //case 1
    if (m<=5)
    {
       for (i=0;i<m;i++)
       for (j=0;j<n;j++)
            scanf("%d",&a[i][j]);
       memset(ans,0,sizeof(ans));
       for (i=0;i<=num[m];i++)
       {
           int k1=i;memset(zt,false,sizeof(zt));

           for (j=m;j>=0;j--)
           {
               if (k1>=num[j]) {k1-=num[j],zt[j]=1;}
           }
           bool f1=true;
           for (j=0;j<=m-1;j++) zt1[i][j]=zt[j];
           for (j=1;j<=m-2;j++)
               if (zt[j]&&(zt[j-1]||zt[j+1])) f1=false;
           if (!f1) {for (j=1;j<=n;j++) ans[i][j]=-1;}
           else
           {
               for (j=0;j<=m-1;j++)
                   ans[i][1]+=a[j][0];
               if (ans[i][1]>max1) max1=ans[i][1];
           }
       }
       memset(zt2,false,sizeof(zt2));
       for (i=0;i<=num[m];i++)
           for (j=0;j<=num[m];j++)
           {
               bool f1=true;
               for (int j1=0;j1<m;j1++)
                   if (zt1[i][j1]&&zt1[j][j1]) f1=false;
               if (f1) zt2[i][j]=true;
           }
       for (i=2;i<=n;i++)
       {
           for (j=0;j<=num[m];j++)
           {
               if (ans[j][i]==-1) continue;
               int k1=0;
               for (int j1=0;j1<=m-1;j1++) if (zt1[j][j1]) k1+=a[j1][i];
               for (int j1=0;j1<=num[m];j1++)
                   if (zt2[j][j1]&&k1+ans[j1][i-1]>ans[j][i]) ans[j][i]=ans[j1][i-1]+k1;
               if (ans[j][i-1]>max1) max1=ans[j][i-1];
           }
       }
       printf("%d\n",max1);
    }
    else
    {
    //case 2
    nn=n*m*2+2;
    memset(map,0,sizeof(map));
    memset(dis,0,sizeof(dis));
    memset(his,0,sizeof(his));
    memset(pre,0,sizeof(pre));
    memset(vh,0,sizeof(vh));
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        {
            
            scanf("%d\n",&xx);ans1+=xx;
            int wz=(i-1)*n+j;
            int wz1=wz+n*m;
            map[1][wz+1]=inf;
            map[wz1+1][wz]=xx;
            map[wz1+1][nn]=xx;
            if (i>1) map[wz+1][(i-1)*n+j+1+n*m]=xx;
            if (i<m) map[wz+1][(i+1)*n+j+1+n*m]=xx;
            if (j>1) map[wz+1][wz+n*m]=xx;
            if (j<n) map[wz+1][wz+2+n*m]=xx;
        }
    sap_gap();
    printf("%d\n",ans1-flow);
    }
    return 0;
}
