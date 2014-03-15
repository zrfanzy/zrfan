#include<iostream>
#include<cstring>
using namespace std;
int n,i;
char ch[100];
/*
ID:zrfan3
PROG:evenodd
LANG: C++
*/

int main()
{
    freopen("evenodd.in","r",stdin);
    freopen("evenodd.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s\n",ch);
        if (ch[strlen(ch)-1]%2==0) printf("even\n");
        else printf("odd\n");
    } 
}
