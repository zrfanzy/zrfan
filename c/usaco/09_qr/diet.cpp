#include<iostream>
using namespace std;

/*
ID:zrfan3
PROG:diet
LANG: C++
*/

bool ans[45005]={false};
int max1,h,n,i,j;
int a[505];

int main()
{
    freopen("diet.in","r",stdin);
    freopen("diet.out","w",stdout);
    scanf("%d %d",&h,&n);
    for (i=1;i<=n;i++)   scanf("%d",&a[i]);
    ans[0]=true;max1=0;
    for (i=1;i<=n;i++)
        for (j=max1;j>=0;j--)
            if (ans[j]&&j+a[i]<=h) {ans[j+a[i]]=true;if (j+a[i]>max1) max1=j+a[i];}
    printf("%d\n",max1);
    return 0;
}
