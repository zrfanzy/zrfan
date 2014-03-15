#include<iostream>
using namespace std;

/*
ID:zrfan3
PROG:stroll
LANG: C++
*/

int i,p,k;
int a[1005][3];
int ans,ans1;

int dg(int q)
{
    if (ans1>ans) ans=ans1;
    if (a[q][1]!=0){ans1++;dg(a[q][1]);ans1--;}
    if (a[q][2]!=0){ans1++;dg(a[q][2]);ans1--;}
}

int main()
{
    freopen("stroll.in","r",stdin);
    freopen("stroll.out","w",stdout);
    scanf("%d",&p);
    for (i=1;i<=p;i++)
    {
        cin>>k;
        cin>>a[k][1]>>a[k][2];
    }
    ans1=1;
    dg(1);
    cout<<ans<<endl;
    return 0;
}
