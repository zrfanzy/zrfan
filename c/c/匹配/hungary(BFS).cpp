#include<iostream>
using namespace std;
int a[600];
bool b[600];
bool c[600][600];
int m,k,j,n,n1,i,ans,i1,j1;

bool find(int x){
     int p;
     for (p=1;p<=n1;p++){
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
    freopen("hungary3.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d %d",&n,&n1,&m);
    memset(c,false,sizeof(c));
    for (i=1;i<=m;i++){
        scanf("%d %d",&i1,&j1);
        c[i1][j1]=true;
    }
    ans=0;
    for (i=1;i<=n1;i++) {
        memset(b,false,sizeof(b));
        if (find(i)) ans++;
    }
    printf("%d\n",ans);
}
