#include<iostream>
using namespace std;
long a,b,c,ans,k;

int main()
{
    //freopen("3.in","r",stdin);
    //freopen("3.out","w",stdout);
    while (cin>>a>>b>>c)
    {
          ans=-1;
          while (a<b+c&&b<a+c&&c<a+b&&a>0&&b>0&&c>0&&ans<=9999)
          {
                ans++;
                k=a+b+c;
                a=k-2*a,b=k-2*b,c=k-2*c;
          }
          if (ans<=9999)cout<<ans<<endl;
          else cout<<"The voyage seemed endless..."<<endl;
    }
    return 0;
}
