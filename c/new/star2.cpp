#include <iostream> 
#include<cstdlib> 
using namespace std;  

int cmp(const void *p,const void *q)
{
    if ( ((int *)p)[0] ==((int *)q)[0] ) return((int *)p)[1]-((int *)q)[1];
    else return ((int *)p)[0]-((int *)q)[0]; 
}

struct TNode  
{  
    int left, right;  
    int n;  
};  
TNode T[70000];
int a[15005][2];
int i,j,n;
int ans[15005];
  
void build(int s, int t, int step)  
{  
    T[step].left = s;  
    T[step].right = t;  
    T[step].n = 0;  
    if(s == t)  
        return;  
    int mid = (s + t) / 2;  
    build(s, mid, step*2);  
    build(mid+1, t, step*2+1);  
}  
void insert(int s, int t, int step)  
{  
    if(s == T[step].left && t == T[step].right)  
    {  
        T[step].n++;  
        return;  
    }  
    int mid = (T[step].left + T[step].right) / 2;  
    if(t <= mid)  
        insert(s, t, step*2);  
    else if(s > mid)  
         insert(s, t, step*2+1);  
    else  
    {  
        insert(s,mid, step*2);  
        insert(mid+1, t, step*2+1);  
    }  
}  
void calculate(int s, int t, int step, int target, int& count)  
{  
    count += T[step].n;  
    if(s == t)  
        return;  
    int mid = (s + t) / 2;  
    if(target <= mid)  
        calculate(s, mid, step*2, target, count);  
    else  
    {
        calculate(mid+1, t, step*2+1, target, count);
        calculate(s, mid, step*2, target, count);
    }  
}  
int main()  
{  
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    scanf("%d",&n);
    build(1,32000,1);
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    qsort(a,n,sizeof(a[1]),cmp);
    memset(ans,0,sizeof(ans));
    for (i=0;i<n;i++)
    {
        int count=0;
        calculate(1,T[1].right,1,a[i][1],count);
        ans[count]++;
        insert(1,a[i][1],1);
    }
    for (i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}  
