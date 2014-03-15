#include<iostream>
using namespace std;

int main()
{
    freopen("f.out","w",stdout);
    int i,j,ans;ans=0;
    for (i=1;i<=1000;i++)
        for (j=1;j<=1000;j++)
            if (3*i>j) ans++;
    printf("%d\n",ans);
    return 0;
}
