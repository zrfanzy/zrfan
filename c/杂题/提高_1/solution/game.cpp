#include<iostream>
using namespace std;
int r[65536][5][5];
int ans1,ans,ans2,s,t,i,j,i1,j1,k,i2,j2;
int ne[5][5];
int a[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
char ch;
bool f[65536];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ans=0;
    for (i=1;i<=4;i++) {
        for (j=1;j<=4;j++) 
        {
                    cin>>ch;if (ch=='1') r[1][i][j]=1; else r[1][i][j]=0;
            ans+=r[1][i][j]*a[(i-1)*4+j-1];
        }
        scanf("\n");
    }
    f[ans]=true;
    scanf("\n");
    for (i=1;i<=4;i++) {
        for (j=1;j<=4;j++) {cin>>ch;if (ch=='1') ans2+=a[(i-1)*4+j-1];}
        scanf("\n");
    }
    s=1;t=1;
    if (ans==ans2) {cout<<0<<endl;return 0;}
    while (true)
    {
          ans1++;
          int t1=t;
          for (i=s;i<=t1;i++)
          {
              ans=0;
              for (i1=1;i1<=4;i1++)
                  for (j1=1;j1<=4;j1++)
                      {ne[i1][j1]=r[i][i1][j1];ans+=r[i][i1][j1]*a[(i1-1)*4+j1-1];}
              for (i1=1;i1<=4;i1++)
                  for (j1=1;j1<=4;j1++)
                  {
                      if (j1<=3){
                      if (ne[i1][j1]==0) ans+=a[(i1-1)*4+j1-1]; else ans-=a[(i1-1)*4+j1-1];
                      if (ne[i1][j1+1]==0) ans+=a[(i1-1)*4+j1]; else ans-=a[(i1-1)*4+j1];
                      if (ans==ans2) {cout<<ans1<<endl;return 0;}
                      if (!f[ans]) {f[ans]=true;t++;
                      for (i2=1;i2<=4;i2++) for (j2=1;j2<=4;j2++) r[t][i2][j2]=ne[i2][j2];
                      r[t][i1][j1]=1-ne[i1][j1];r[t][i1][j1+1]=1-ne[i1][j1+1];}
                      if (ne[i1][j1]==0) ans-=a[(i1-1)*4+j1-1]; else ans+=a[(i1-1)*4+j1-1];
                      if (ne[i1][j1+1]==0) ans-=a[(i1-1)*4+j1]; else ans+=a[(i1-1)*4+j1];
                      }
                      // left
                      if (i1<=3)
                      {
                      if (ne[i1][j1]==0) ans+=a[(i1-1)*4+j1-1]; else ans-=a[(i1-1)*4+j1-1];
                      if (ne[i1+1][j1]==0) ans+=a[(i1)*4+j1-1]; else ans-=a[(i1)*4+j1-1];
                      if (ans==ans2) {cout<<ans1<<endl;return 0;}
                      if (!f[ans]) {f[ans]=true;t++;
                      for (i2=1;i2<=4;i2++) for (j2=1;j2<=4;j2++) r[t][i2][j2]=ne[i2][j2];
                      r[t][i1][j1]=1-ne[i1][j1];r[t][i1+1][j1]=1-ne[i1+1][j1];}
                      if (ne[i1][j1]==0) ans-=a[(i1-1)*4+j1-1]; else ans+=a[(i1-1)*4+j1-1];
                      if (ne[i1+1][j1]==0) ans-=a[(i1)*4+j1-1]; else ans+=a[(i1)*4+j1-1];
                      }
                      //down
                  }
          }
    }
    return 0;
}
