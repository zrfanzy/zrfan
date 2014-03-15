#include<iostream>
#include<cstring>
using namespace std;

/*
ID:zrfan3
PROG:echo
LANG: C++
*/

char ch1[85],ch2[85];
int ans[85][85],ans1;
int i,j;

int main()
{
    freopen("echo.in","r",stdin);
    freopen("echo.out","w",stdout);
    scanf("%s\n",ch1);scanf("%s\n",ch2);
    memset(ans,0,sizeof(ans));
    ans1=0;
    for (i=0;i<strlen(ch1);i++)
        for (j=0;j<strlen(ch2);j++)
            {
                if (i==0||j==0)
                   if (ch1[i]==ch2[j]) ans[i][j]=1;
                if (i!=0&&j!=0)
                   if (ch1[i]==ch2[j]) ans[i][j]=ans[i-1][j-1]+1;
                if (ans[i][j]>ans1) ans1=ans[i][j];
            }
    cout<<ans1<<endl;
}
