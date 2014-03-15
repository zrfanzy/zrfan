#include <iostream>

using namespace std;

const int V=50001;

struct edge
{
    int v;
    edge *next;
    edge(int v,edge *next):v(v),next(next) {}
} *e[V];
int nx,ny,mx[V],my[V],dx[V],dy[V],q[V];

inline bool bfs()
{
    memset(dx,0,sizeof(dx));
    memset(dy,0,sizeof(dy));
    bool flag=false;
    int head=0,tail=0;
    for(int i=1;i<=nx;++i)
        if(!mx[i])
            q[tail++]=i;
    for(;head<tail;++head)
        for(edge *t=e[q[head]];t;t=t->next)
            if(!dy[t->v])
            {
                dy[t->v]=dx[q[head]]+1;
                if(!my[t->v]) flag=true;
                else
                {
                    dx[my[t->v]]=dy[t->v]+1;
                    q[tail++]=my[t->v];
                }
            }
    return flag;
}

bool dfs(int v)
{
    for(edge *t=e[v];t;t=t->next)
        if(dy[t->v]==dx[v]+1)
        {
            dy[t->v]=0;
            if(!my[t->v]||dfs(my[t->v]))
            {
                mx[v]=t->v;
                my[t->v]=v;
                return true;
            }
        }
    return false;
}

int main()
{
    freopen("Hungary3.in","r",stdin);
    freopen("test.out","w",stdout);
    int m,a,b,ans=0;
    for(scanf("%d%d%d",&nx,&ny,&m);m;--m)
    {
        scanf("%d%d",&a,&b);
        e[a]=new edge(b,e[a]);
    }
    while(bfs())
        for(int i=1;i<=nx;++i)
            if(!mx[i]&&dfs(i))
                ++ans;
    printf("%d\n",ans);
    return 0;
}
