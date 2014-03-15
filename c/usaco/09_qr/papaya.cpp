#include<iostream>
using namespace std;

int r,c,x,y,i,j,ans,max1,maxi;
int f[45][45];

/*
ID:zrfan3
PROG:papaya
LANG: C++
*/

int main()
{
    freopen("papaya.in","r",stdin);
    freopen("papaya.out","w",stdout);
    scanf("%d %d",&r,&c);
    for (i=1;i<=r;i++)
        for (j=1;j<=c;j++)
            scanf("%d",&f[i][j]);
    ans=f[1][1];
    f[1][1]=0;
    x=1,y=1;
    while (x!=r||y!=c)
    {
          max1=0;maxi=0;
          if (x-1>0&&f[x-1][y]>max1) {max1=f[x-1][y],maxi=1;}
          if (y-1>0&&f[x][y-1]>max1) {max1=f[x][y-1],maxi=2;}
          if (x+1<=r&&f[x+1][y]>max1) {max1=f[x+1][y],maxi=3;}
          if (y+1<=c&&f[x][y+1]>max1) {max1=f[x][y+1],maxi=4;}
          ans+=max1;
          if (maxi==1) {f[x-1][y]=0,x--;}
          else if (maxi==2) {f[x][y-1]=0,y--;}
          else if (maxi==3) {f[x+1][y]=0,x++;}
          else {f[x][y+1]=0,y++;}
    }
    cout<<ans<<endl;
    return 0;
}
