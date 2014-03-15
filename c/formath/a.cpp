#include<iostream>
using namespace std;

int main()
{
    freopen("test.out","w",stdout);
    int ans=0;
    int i;
    for (i=1;ans<=1000;i++)
    {
        if (i%3!=0&&i%5!=0&&i%7!=0) ans++;
        if (i==105) printf("%d\n",ans);
    }
    printf("%d\n",i);
    return 0;
}
