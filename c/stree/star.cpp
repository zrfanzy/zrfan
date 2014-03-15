#include<iostream>
#include<cstdlib>
using namespace std;

struct nod
{
       int a,b,t;
};
nod tree[64000];
int ans1[15000];
int a[15005][2];
int ans,i,j,n;

int cmp(const void *p,const void *q)
{
    if (((int *)p)[0]==((int *)q)[0]) return ((int *)p)[1]==((int *)q)[1];
    else return ((int *)p)[0]==((int *)q)[0];
}

int find1(int y1,int y2,int v)
{
    if (y1<=tree[v].a&&tree[v].b<=y2) return tree[v].t;
    else 
    {
         int ans3=0;
         if (y1<=(tree[v].a+tree[v].b)/2) ans3+=find1(y1,y2,v*2);
         if (y2>(tree[v].a+tree[v].b)/2+1&&tree[v].b>0) ans3+=find1(y1,y2,v*2+1);
         return ans3;
    }
}

int insert(int y,int v)
{
    if (tree[v].a==tree[v].b) tree[v].t++;
    else
    {
        if (y<=(tree[v].a+tree[v].b)/2) insert(y,v*2);
        if (y>(tree[v].a+tree[v].b)/2+1) insert(y,v*2+1);
        tree[v].t=tree[v*2].t+tree[v*2+1].t;
    } 
}

int dfs(int p)
{
    tree[p*2].a=tree[p].a,tree[p*2].b=(tree[p].a+tree[p].b)/2,tree[p*2].t=0;
    if (tree[p*2].a!=tree[p*2].b) dfs(p*2);
    tree[p*2+1].a=(tree[p].a+tree[p].b)/2+1,tree[p*2+1].b=tree[p].b,tree[p*2].t=0;
    if (tree[p*2+1].a!=tree[p*2+1].b) dfs(p*2+1);   
}

int main()
{
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d %d",&a[i][0],&a[i][1]);
    qsort(a,n,sizeof(a[1]),cmp);
    tree[1].a=1,tree[1].b=5,tree[1].t=0;
    dfs(1);
    for (i=0;i<n;i++)
    {
        ans=find1(1,a[i][1],1);
        ans1[ans]++;
        insert(a[i][1],1);
    }
    for (i=0;i<n;i++) printf("%d\n",ans1[i]);
    return 0;
}
