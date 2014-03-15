#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
bool vis[6];
double r[6];
long x2[6],y2[6],z2[6],n,x,y,z,x1,yy,z1,j,i;
double ans,max1;
long ans1;

double min1(double p1,double q1)
{
      if (p1-q1>1e-3) return q1;
      else return p1;
}

double dis(int i1,int i2,int i3,int i4,int i5,int i6)
{
      return sqrt((double)((i4-i1)*(i4-i1)+(i5-i2)*(i5-i2)+(i6-i3)*(i6-i3)));
}

int dg(int p)
{
    if (p<n)
    {
              for (int q=0;q<n;q++)
                  if (!vis[q])
                  {
                      vis[q]=true;
                      float k1=min1(x2[q]-x,x1-x2[q]);
                      k1=min1(k1,min1(y2[q]-y,yy-y2[q]));
                      k1=min1(k1,min1(z2[q]-z,z1-z2[q]));
                      for (int q1=0;q1<n;q1++)
                          if (vis[q1]&&q!=q1)
                             k1=min1(k1,dis(x2[q],y2[q],z2[q],x2[q1],y2[q1],z2[q1])-r[q1]);
                      r[q]=k1;
                      if (k1<0) k1=0;
                      ans=ans+k1*k1*k1*3.1415926538*4/3;
                      dg(p+1);
                      ans=ans-k1*k1*k1*3.1415926538*4/3;
                      r[q]=0;
                      vis[q]=false;
                  }
    }
    else
    {
        if (ans>max1) max1=ans;
    } 
}

int main()
{
    //freopen("balloon.in","r",stdin);
    //freopen("balloon.out","w",stdout);
    cin>>n;
    j=0;
    while (n)
    {
          j++;
          ans=0.0;
          max1=0.0;
          x=y=z=0,x1=yy=z1=0;
          cin>>x>>y>>z;
          cin>>x1>>yy>>z1;
          if (x>x1) 
          {
                    long q=x;x=x1;x1=q;}
          if (y>yy) 
          {long q=y;y=yy;yy=q;}
          if (z>z1) 
          {long q=z;z=z1;z1=q;}
          memset(vis,0,sizeof(vis));
          memset(r,0,sizeof(r));
          for (i=0;i<n;i++)
              cin>>x2[i]>>y2[i]>>z2[i];
          dg(0);
          ans1=(int)(max1*10);
          if (ans1%10>=5) ans1=ans1/10+1;
          else ans1/=10;
          long long ans2=(x1-x)*(yy-y)*(z1-z);
          cout<<"Box "<<j<<": "<<ans2-ans1<<endl;
          cin>>n;
    }
    return 0;
}
