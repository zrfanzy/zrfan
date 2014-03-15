#include<iostream>
using namespace std;

int max3(int p,int q)
{
    if (p>q) return p; else return q;
}

int min3(int p,int q)
{
    if (p>q) return q;else return p;
}

int n,min1,min2,max1,max2,i,x,y;

int main()
{
    /*freopen("4.in","r",stdin);
    freopen("4.out","w",stdout);*/
    scanf("%d",&n);
    scanf("%d %d",&min1,&min2);
    max1=min1,max2=min2;
    cout<<max3(min1+max2,min2+max1)<<endl;
    for (i=2;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        if (x<min1) min1=x;
        if (x>max1) max1=x;
        if (y<min2) min2=y;
        if (y>max2) max2=y;
        cout<<max3(min1+max2,min2+max1)<<endl;
    }
}
