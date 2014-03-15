#include<iostream>
using namespace std;
double dp[20000][15][15],a[15];
int n,i,j,ans1,c[15];
bool b[15];
long p[15];

inline void make(int pp,int qq,int zt){
     int i1,j1,k1,k2,maxj;
     bool flat;
     double max,max1;
     int maxi;
     if ((qq>=n)){
        if (pp==i){
           for (i1=0;i1<n;i1++){
                if (b[i1]==true){
                   flat=true;
                   for (j1=0;j1<n;j1++){
                       if ((b[j1]==true)&&(a[j1]!=a[i1])){
                          flat=false;break;
                       }
                   }   
                   if (flat) {
                      for (j1=0;j1<n;j1++){
                          if (b[j1]) dp[zt][i1][j1]=1/(double)(i);
                      }
                   }
                   else {
                        max=0;
                        for (j1=0;j1<n;j1++){
                            if ((b[j1])&&(j1!=i1)){
                               k1=j1+1;
                               if (k1>=n) k1=1;
                               while (b[k1]==false){
                                     k1++;
                                     if (k1>=n) k1=0;
                               }
                               k2=j1;
                               if (k2>=n) k2=1;
                               while (b[k2]==false){
                                     k2++;
                                     if (k2>=n) k2=0;
                               }
                               max1=a[i1]*(dp[zt-p[j1]][k1][i1]);
                               if (max1>max) {
                                  max=max1;maxi=j1;maxj=k1;
                               }
                            }
                        }
                        dp[zt][i1][i1]=max;
                        for (j1=0;j1<n;j1++){
                            if ((b[j1]==true)&&(j1!=maxi)&&(j1!=i1))
                               dp[zt][i1][j1]=a[i1]*(dp[zt-p[maxi]][maxj][j1]);
                        }
                   }
                }
           }
        }
     }
     else {
          if (pp<i){
             b[qq]=true;make(pp+1,qq+1,zt+p[qq]);
             b[qq]=false;
          }     
          make(pp,qq+1,zt);
     }
}

int main(){
    freopen("fight.in","r",stdin);
    freopen("fight.out","w",stdout);
    scanf("%d",&n);
    p[0]=1;
    ans1=1;
    for (i=1;i<n;i++){
        p[i]=p[i-1]*2;
        ans1+=p[i];
    }
    for (i=0;i<n;i++){
        scanf("%d",&c[i]);
        a[i]=((double)(c[i])/100);
        dp[p[i]][i][i]=1;
        for (j=0;j<n;j++){
            if (j!=i) dp[p[i]][i][j]=0;
        }
    }
    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
           int k=p[i]+p[j];
           if (a[i]==a[j]){
              dp[k][i][j]=dp[k][j][i]=dp[k][j][j]=dp[k][i][i]=0.5;
           }
           else if (a[i]<a[j]){
              dp[k][i][i]=a[i];dp[k][i][j]=(1-a[i])*(a[j]);
              dp[k][j][j]=a[j];dp[k][j][i]=(1-a[j])*(a[i]);
           }
        }
    }
    for (i=3;i<=n;i++){
        memset(b,false,sizeof(b));
        make(0,0,0);
    }
    for (i=0;i<n;i++){
        printf("%.6f\n",dp[ans1][0][i]);
    }
    return(0);
}
