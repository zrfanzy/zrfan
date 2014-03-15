#include<iostream>
using namespace std;
int a[600],h[600];
char u[600][600],s[600][600],x[600][3];
bool b[600];
bool c[600][600];
int m,k,j,n,i,ans,n1,n2,i1,j1;
int girl[600],boy[600];

bool find(int x){
     int p;
     for (p=1;p<=n2;p++){
         if ((c[x][p]==true)&&(b[p]==false)){
              b[p]=true;
              if ((a[p]==0)||find(a[p])) {
                  a[p]=x;b[p]=false;return(true);
              }
              b[p]=false;
         } 
     }
     return(false);
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&m);
    for (k=1;k<=m;k++){
        n1=0;n2=0;
        memset(c,false,sizeof(c));
        memset(a,0,sizeof(a));
        scanf("%d\n",&n);
        for (i=1;i<=n;i++) {
            scanf("%d %s %s %s\n",&h[i],x[i],u[i],s[i]);
            if (strcmp(x[i],"M")==0){
                n1+=1;girl[n1]=i;
            }
            else {
                n2+=1;boy[n2]=i;
            }
        }
        for (i=1;i<=n1;i++){
            for (j=1;j<=n2;j++){
                i1=girl[i];j1=boy[j];
                if (!((abs(h[i1]-h[j1])>40)||
                    (strcmp(x[i1],x[j1])==0)||
                    (strcmp(s[i1],s[j1])==0)||
                    (strcmp(u[i1],u[j1])!=0))){
                    c[i][j]=true;
                }
            }
        }
        ans=0;
        for (i=1;i<=n1;i++) {
            memset(b,false,sizeof(b));
            if (find(i)) ans++;
        }
        printf("%d\n",n-ans);
    }
}
