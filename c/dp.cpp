#include<iostream>
using namespace std;
long f[200][200][100][100];
int n,m,k,i,j,xx,yy,x,y;
long ans;

int main(){
  freopen("party.0.in","r",stdin);
  freopen("test.out","w",stdout);
  scanf("%d %d %d",&n,&m,&k);
  f[0][0][k][k]=1;
  for (i=0;i<=n;i++)
      for (j=0;j<=m;j++)
          for (x=-k;x<=k;x++)
              for (y=x;y<=k;y++){
                xx=y+1;
                if (y<0) yy=1;else yy=y+1;
                f[i+1][j][xx+k][yy+k]=(f[i+1][j][xx+k][yy+k]+f[i][j][x+k][y+k])%12345678;
                if (x>0) xx=-1;else xx=x-1;
                yy=y-1;
                f[i][j+1][xx+k][yy+k]=(f[i][j+1][xx+k][yy+k]+f[i][j][x+k][y+k])%12345678;
              }
  ans=0;
  for (i=-k;i<=k;i++)
    for (j=-k;j<=k;j++)
      ans+=f[n][m][i+k][j+k];
   /*for (i=0;i<=n;i++)
      for (j=0;j<=m;j++)
          for (x=-k;x<=k;x++)
              for (y=x;y<=k;y++)
                printf("%d %d %d %d %d\n",i,j,x,y,f[i][j][x+k][y+k]);*/
  printf("%Ld\n",ans);
}
