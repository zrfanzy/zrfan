#include<iostream>
#include<cstdlib>
using namespace std;

struct nod
{
       int a,b,t;
};

nod tree[90000];
int a[15005][2];
int i,j,n;
int count1;
int ans[15005];


int cmp(const void *p,const void *q)
{
    if ( ((int *)p)[0] ==((int *)q)[0] ) return((int *)p)[1]-((int *)q)[1];
    else return ((int *)p)[0]-((int *)q)[0]; 
}

void build_tree(int p)
{
    int mid=(tree[p].a+tree[p].b)/2;int left=tree[p].a,right=tree[p].b;
    tree[p*2].a=left,tree[p*2].b=mid,tree[p*2].t=0;
    if (left<mid) build_tree(p*2);
    tree[p*2+1].a=mid+1,tree[p*2+1].b=tree[p].b,tree[p*2].t=0;
    if (mid+1<right) build_tree(p*2+1);
}

void find_tree(int y1,int y2,int v)
{
    if (tree[v].a==tree[v].b) count1+=tree[v].t;
    else if (tree[v].a>=y1&&tree[v].b<=y2) count1+=tree[v].t;
    else
    {
        int mid=(tree[v].a+tree[v].b)/2;
        if (y1<=mid) find_tree(y1,y2,v*2);
        if (y2>mid) find_tree(y1,y2,v*2+1);
    }
}

void insert_tree(int y1,int v)
{
    if (tree[v].a==tree[v].b) tree[v].t++;
    else{
         int mid=(tree[v].a+tree[v].b)/2;
         if (y1>=tree[v].a&&y1<=mid) insert_tree(y1,v*2);
         if (y1>mid&&y1<=tree[v].b) insert_tree(y1,v*2+1);
         tree[v].t=tree[v*2].t+tree[v*2+1].t;
    }
}

int main()
{
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    qsort(a,n,sizeof(a[1]),cmp);
    
    tree[1].a=0,tree[1].b=32000,tree[1].t=0;
    build_tree(1);
    memset(ans,0,sizeof(ans));
    for (i=0;i<n;i++)
    {
        count1=0;find_tree(0,a[i][1],1);
        ans[count1]++;
        insert_tree(a[i][1],1);
    }
    for (i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
