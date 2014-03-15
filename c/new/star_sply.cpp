#include<iostream>
#include<cstdlib>
using namespace std;


int tot=0;
int top=1;
int n,i,j;
int a[15005][2];
int ans1[15005];

struct Tnod
{
       int l,r,f,num,s,cf;
};
Tnod tree[15005];


int cmp(const void *p,const void *q)
{
    if (((int *)p)[0]==((int *)q)[0]) return ((int *)p)[1]-((int *)q)[1];
    else return ((int *)p)[0]-((int *)q)[0];
}


inline void turn_left(int ll, int rr) 
{
    if (ll==top)
    {
        top=rr;tree[rr].f=0;
    }
    else
    {
        int ff=tree[ll].f;tree[rr].f=ff;
        if (ll==tree[ff].l) tree[ff].l=rr;
        else tree[ff].r=rr;
    };
    tree[ll].r=tree[rr].l;tree[tree[ll].r].f=ll;tree[rr].l=ll;tree[ll].f=rr;
    /*int c;
    c=tree[ll].num,tree[ll].num=tree[rr].num,tree[rr].num=c;
    c=tree[ll].s,tree[ll].s=tree[rr].s,tree[rr].s=c;
    c=tree[ll].cf,tree[ll].cf=tree[rr].cf,tree[rr].cf=c;*/
    tree[ll].num=tree[tree[ll].r].num+tree[tree[ll].l].num+tree[tree[ll].l].cf+tree[tree[ll].r].cf;
    tree[rr].num=tree[tree[rr].r].num+tree[tree[rr].l].num+tree[tree[rr].l].cf+tree[tree[rr].r].cf;
    tree[ll].num=tree[tree[ll].r].num+tree[tree[ll].l].num+tree[tree[ll].l].cf+tree[tree[ll].r].cf;
    tree[rr].num=tree[tree[rr].r].num+tree[tree[rr].l].num+tree[tree[rr].l].cf+tree[tree[rr].r].cf;
};
  
inline void turn_right(int ll, int rr) 
{
    if (rr==top)
    {
        top=ll;tree[ll].f=0;
    }
    else
    {
        int ff=tree[rr].f;tree[ll].f=ff;
        if (rr==tree[ff].l) tree[ff].l=ll;
        else tree[ff].r=ll;
    };
    tree[rr].l=tree[ll].r;tree[tree[rr].l].f=rr;tree[ll].r=rr;tree[rr].f=ll;
    /*int c;
    c=tree[ll].num,tree[ll].num=tree[rr].num,tree[rr].num=c;
    c=tree[ll].s,tree[ll].s=tree[rr].s,tree[rr].s=c;
    c=tree[ll].cf,tree[ll].cf=tree[rr].cf,tree[rr].cf=c;*/
    tree[ll].num=tree[tree[ll].r].num+tree[tree[ll].l].num+tree[tree[ll].l].cf+tree[tree[ll].r].cf;
    tree[rr].num=tree[tree[rr].r].num+tree[tree[rr].l].num+tree[tree[rr].l].cf+tree[tree[rr].r].cf;
    tree[ll].num=tree[tree[ll].r].num+tree[tree[ll].l].num+tree[tree[ll].l].cf+tree[tree[ll].r].cf;
    tree[rr].num=tree[tree[rr].r].num+tree[tree[rr].l].num+tree[tree[rr].l].cf+tree[tree[rr].r].cf;
};

inline void splay(int x)
{
    int y,z;
    while (x!=top)
    {
        if ((y=tree[x].f)==top)
            if (tree[y].l==x)
                turn_right(x,y);
            else
                turn_left(y,x);
        else
            if (tree[y].l==x)
            {
                if (tree[ (z=tree[y].f) ].l==y)
                {
                    turn_right(y,z);
                    turn_right(x,y);
                }
                else
                {
                    turn_right(x,y);
                    turn_left(z,x);
                };
            }
            else
            {
                if (tree[ (z=tree[y].f) ].r==y)
                {
                    turn_left(z,y);
                    turn_left(y,x);
                }
                else
                {
                    turn_left(y,x);
                    turn_right(x,z);
                };
            };
    };
};

inline void insert(int st,int x)
{
       if (tree[x].s==st) {tree[x].cf++;splay(x);top=x;}
       else if (tree[x].s>st)
       {
            if (tree[x].r==0)
            {tot++,tree[x].r=tot,tree[tot].f=x;tree[tot].s=st,tree[tot].cf=1;splay(tot);top=tot;}
            else insert(st,tree[x].r);
       }
       else 
       {
            if (tree[x].l==0)
            {tot++,tree[x].l=tot,tree[tot].f=x;tree[tot].s=st,tree[tot].cf=1;splay(tot);top=tot;}
            else insert(st,tree[x].l);
       }
}

int main()
{
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++) {scanf("%d %d",&a[i][0],&a[i][1]);a[i][1]++;}
    qsort(a,n,sizeof(a[1]),cmp);
    tree[0].num=0;
    tree[1].f=0,tree[1].l=0,tree[1].r=0,tree[1].s=a[0][1],tree[1].num=0,tree[1].cf=1;
    tot=1;
    ans1[0]++;
    for (i=1;i<n;i++)
    {
        insert(a[i][1],top);
        ans1[tree[tree[top].r].num+tree[tree[top].r].cf+tree[top].cf-1]++;
    }
    for (i=0;i<n;i++) printf("%d\n",ans1[i]);
    return 0;
}
