#include<iostream>
#include<cstring>
using namespace std;

/*
ID:zrfan3
PROG:rplow
LANG: C++
*/

int ans,x,y,p,x1,y1,x2,y2,i,j,k;
bool f[245][245]={true};

int main()
{
    freopen("rplow.in","r",stdin);
    freopen("rplow.out","w",stdout);
    scanf("%d %d %d",&x,&y,&p);
    memset(f,true,sizeof(f));
    for (i=1;i<=p;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for (j=x1;j<=x2;j++)
            for (k=y1;k<=y2;k++)
                if (f[j][k]) {f[j][k]=false;ans++;}
    }
    printf("%d\n",ans);
    return 0;
}
