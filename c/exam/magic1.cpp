#include<iostream>
using namespace std;
int n,now,ans1,a1,a2;
char ans[100000];
char zt[100000][200];
char y[20000];
int w[100000][500],len[100000];

inline void dg(){
       int i,j,start,end;
       bool flat;
       while (a1<=now){
       int p=len[a1],q=a1;
       if (p==n){
          if (strcmp(zt[q],ans)==0) {
             printf("%d\n",w[q][0]);
             for (j=1;j<=w[q][0];j++){
                 if (w[q][j]>=0) printf("insert %d\n",w[q][j]);
                 else printf("remove %d\n",-w[q][j]);
             }
             exit(0);
          }
       }      
       else {
            for (i=0;i<p;i++){
                if (p<n*2){
                memset(y,0,sizeof(y));
                start=i-1;end=i+1;
                flat=true;
                for (j=0;j<=i-1;j++) y[j]=zt[q][j];
                y[i]='0';
                for (j=i;j<p;j++) 
                    y[j+1]=zt[q][j];
                if (start<0) start=p;
                if (end>p) end=1;
                if (y[start]=='1') y[start]='0';else y[start]='1';
                if (y[end]=='1') y[end]='0';else y[end]='1';
                for (j=1;j<=now;j++) if (strcmp(zt[j],y)==0) flat=false;
                if (flat){
                   now++;
                   for( j=0;j<=p;j++) zt[now][j]=y[j];
                   w[now][0]=w[q][0]+1;
                   for (j=1;j<=w[q][0];j++) w[now][j]=w[q][j];
                   w[now][w[now][0]]=i;
                   len[now]=p+1;
                }
                }
                if (p>2){
                memset(y,0,sizeof(y));
                start=i-1;end=i;
                flat=true;
                for (j=0;j<i;j++) y[j]=zt[q][j];
                for (j=i+1;j<p;j++) 
                    y[j-1]=zt[q][j];
                if (start<0) start=p-2;
                if (end>p-2) end=1;
                if (y[start]=='1') y[start]='0';else y[start]='1';
                if (y[end]=='1') y[end]='0';else y[end]='1';
                for (j=1;j<=now;j++) if (strcmp(zt[j],y)==0) flat=false;
                if (flat){
                   now++;
                   for( j=0;j<=p-1;j++) zt[now][j]=y[j];
                   w[now][0]=w[q][0]+1;
                   for (j=1;j<=w[q][0];j++) w[now][j]=w[q][j];
                   w[now][w[now][0]]=-i-1;
                   len[now]=p+1;
                }
                }
            }     
            
       } 
       a1++;
       }
}

int main(){
    freopen("magic02a.in","r",stdin);
    freopen("magic02a.out","w",stdout);
    scanf("%d\n",&n);
    scanf("%s\n",ans);
    zt[1][0]='0';zt[1][1]='0';
    w[1][0]=0;
    len[1]=2;
    now=1;
    a1=1;
    dg();
    return(0);
}
