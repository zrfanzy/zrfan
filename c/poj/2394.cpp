#include<iostream>
using namespace std;
int f,p,c,m,x,y,z,i,j,start,end,s[505],ss[505],l[505],a[2005][3];
bool v[505];
int ans[505];

int cmp(const void *p,const void *q)
{
    return ((int *)p)[0]-((int *)q)[0];
}

int main()
{
    //freopen("2394.in","r",stdin);
    //freopen("2394.out","w",stdout);
    scanf("%d %d %d %d",&f,&p,&c,&m);
    for (i=0;i<p;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        a[i*2][0]=x,a[i*2][1]=y,a[i*2][2]=z;
        a[i*2+1][0]=y,a[i*2+1][1]=x,a[i*2+1][2]=z;   
    }
    qsort(a,p*2,sizeof(a[1]),cmp);
    memset(l,-1,sizeof(l));
    for (i=0;i<2*p;i++)
    {
        if (l[a[i][0]]==-1) l[a[i][0]]=i;
    }
    start=-1;end=0;
    s[0]=1;
    memset(ss,-1,sizeof(ss));
    memset(v,false,sizeof(v));
    v[1]=true;
    ss[1]=0;
    do
    {
        start=(start+1)%f;
        x=s[start];
        if (l[x]>-1)
        {
             i=l[x];
             while (a[i][0]==x)
             {
                   if (ss[a[i][1]]==-1||(ss[a[i][1]]>ss[x]+a[i][2]))
                   {
                       ss[a[i][1]]=ss[x]+a[i][2];
                       if (!v[a[i][1]])
                       {
                           v[a[i][1]]=true;
                           end=(end+1)%f;
                           s[end]=a[i][1];
                       }
                   }
                   i++;
             }
        }
        v[x]=false;
    }
    while (start!=end);
    memset(ans,0,sizeof(ans));
    for (i=1;i<=c;i++)
    {
        scanf("%d",&x);
        if (ss[x]>=0&&ss[x]<=m)
        {
            ans[++ans[0]]=i;
        }
    }
    printf("%d\n",ans[0]);
    for (i=1;i<=ans[0];i++)
       printf("%d\n",ans[i]);
    return 0;
}
