#include<iostream>
using namespace std;

int main()
{
    /*freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);*/
    bool f1=true,f2=true;
    int i,j;
    for (i=1;i<=8;i++)
    {
        scanf("%d",&j);
        if (j!=i) f1=false;
        if (8-j+1!=i) f2=false;
    }
    if (f1) printf("ascending\n");
    else if (f2) printf("descending\n");
    else printf("mixed\n");
}
