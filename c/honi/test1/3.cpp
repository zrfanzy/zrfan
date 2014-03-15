#include<iostream>
#include<cstring>
using namespace std;
long long ans;
char ch[150];
int ch1[150];
int p1,a1,a2,i;

int dg(int p)
{
    if (p==strlen(ch)&&(p1>0))
    {
        long long ans1=1;
        for (i=0;i<strlen(ch);i++)
            if (ch[i]=='_')
            {
               if (ch1[i]==1) ans1*=5;
               else if (ch1[i]==2) ans1*=1;
               else ans1*=20;
            }
        ans+=ans1;
        return 0;
    }
    else {
        if (ch[p]=='_')
        {
            if (a1<2)
            {
                     ch1[p]=1;a1++;int a3=a2;a2=0;dg(p+1);a1--;a2=a3;
            }
            if (a2<2)
            {
                     ch1[p]=3;a2++;int a3=a1;a1=0;
                     dg(p+1);
                     a2--;a1=a3;
                     ch1[p]=2;a2++;p1++;a3=a1;a1=0;dg(p+1);p1--;a2--;a1=a3;
            }
        }
        else if (ch[p]=='A'||ch[p]=='E'||ch[p]=='I'||ch[p]=='O'||ch[p]=='U')
        {if (a1<2){a1++;int a3=a2;a2=0;dg(p+1);a1--;a2=a3;}}
        else if (ch[p]=='L')
        {if (a2<2){a2++;p1++;int a3=a1;a1=0;dg(p+1);p1--;a2--;a1=a3;}}
        else
        {if (a2<2){a2++;int a3=a1;a1=0;dg(p+1);a2--;a1=a3;}}
    }
    return 0;
}

int main()
{
    /*freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);*/
    scanf("%s",ch);
    p1=a1=a2=0;
    dg(0);
    cout<<ans<<endl;
    return 0;
}
