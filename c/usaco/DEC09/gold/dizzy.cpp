#include<iostream>
#include<cstring>
using namespace std;

/*
ID:zrfan3
TASK:dizzy
LANG:C++
*/

int i,j,n,m1,m2,s,x,y;
int order[100005];
int list[100005];
int v[100005];
int a[100005],edge[100005][2];

int cmp(const void *p,const void *q)
{
    return ((int *)p)[0]-((int *)q)[0];
}

int main()
{
    freopen("dizzy.in","r",stdin);
    freopen("dizzy.out","w",stdout);
    scanf("%d %d %d",&n,&m1,&m2);
    memset(v,0,sizeof(v));
    memset(list,0,sizeof(list));
    for (i=0;i<m1;i++) {scanf("%d %d",&edge[i][0],&edge[i][1]);v[edge[i][1]]++;}
    qsort(edge,m1,sizeof(edge[1]),cmp);
    memset(a,-1,sizeof(a));
    for (i=1;i<=n;i++) if (!v[i]) list[++list[0]]=i;
    for (i=0;i<m1;i++)
        if (a[edge[i][0]]==-1) a[edge[i][0]]=i;
    s=1;
    for (int ll=1;ll<=n;ll++)
    {
        int s1=list[s];
        order[s1]=ll;
        if (a[s1]==-1) {order[s1]=ll;s++;continue;}
        
        for (j=a[s1];j<=m1;j++)
        {
            if (edge[j][0]!=s1) break;
            v[edge[j][1]]--;
            if (!v[edge[j][1]]) list[++list[0]]=edge[j][1];
        }
        s++;
    }
    for (i=1;i<=m2;i++)
    {
        scanf("%d %d",&x,&y);
        if (order[x]>order[y]) printf("%d %d\n",y,x);
        else printf("%d %d\n",x,y);
    }
    return 0;
}
