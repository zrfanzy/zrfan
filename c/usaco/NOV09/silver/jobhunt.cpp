#include<iostream>
#include<cstring>
using namespace std;
bool visit[225];
int visit1[225];
int a[225][255];
bool visit2[225];
int list[48500];
int ans[225];
bool f1[225][255];
int x,y,z,start,d,p,c,f,s,i,e;
/*
ID:zrfan3
PROG:jobhunt
LANG: C++
*/
int main()
{
    freopen("jobhunt.in","r",stdin);
    freopen("jobhunt.out","w",stdout);
    cin>>d>>p>>c>>f>>s;
    for (i=1;i<=p;i++)
    {
        cin>>x>>y;
        a[x][y]=-d;f1[x][y]=true;
    }
    for (i=1;i<=f;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=z-d;f1[x][y]=true;
    }
    memset(visit,false,sizeof(visit));
    list[0]=1,list[1]=s,start=0,visit2[s]=true,ans[s]=-d;visit[s]=true;
    while (start<list[0])
    {
          start++;e=list[start];
          for (i=1;i<=c;i++)
              if (f1[e][i])
              {
                   if (ans[e]+a[e][i]<ans[i])
                   {
                       ans[i]=ans[e]+a[e][i];
                       if (!visit[i])
                       {
                          visit[i]=true;visit2[i]=true;
                          list[++list[0]]=i;
                          if (++visit1[i]>c) {cout<<-1<<endl;return 0;}
                       }
                   }
                   else if (!visit2[i])
                   {
                        ans[i]=ans[e]+a[e][i];
                        visit[i]=true;visit2[i]=true;
                        list[++list[0]]=i;
                   }
              }
          visit[e]=false;
    }
    int max1=0;
    for (i=1;i<=c;i++)
        if (max1>ans[i]) max1=ans[i];
    cout<<max1*-1<<endl;
    return 0;
}
