#include<iostream>
#include<cstring>
using namespace std;
long a,b,k;
int i;
char c[500];
long s[500];

long gcd(long p,long q)
{
     if (p<q) return gcd(q,p);
     else if (p%q) return gcd(q,p%q);
     else return q;
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    while (gets(c))
    {
          if (c[0]=='[')
          {
              i=1;
              memset(s,0,sizeof(s));
              s[0]=1;
              while (i<strlen(c)-1)
              {
                    if (c[i]==';'||c[i]==',') s[0]++;
                    else s[s[0]]=s[s[0]]*10+(int)(c[i])-(int)('0');
                    i++;
              }
              b=1;
              a=s[s[0]];s[0]--;
              while (s[0])
              {
                    k=a,a=b,b=k;
                    a+=b*s[s[0]];
                    s[0]--;
              }
              k=gcd(a,b);
              cout<<(a/k)<<'/'<<(b/k)<<endl;
          }
          else
          {
              a=0,b=0;
              i=0;
              while (c[i]!='/')
              {
                    a=a*10+(int)(c[i])-(int)('0');
                    i++;
              }
              i++;
              while (i<strlen(c))
              {
                    b=b*10+(int)(c[i])-(int)('0');
                    i++;
              }
              if (a==0){cout<<"[0]"<<endl;}
              else 
              {
                   cout<<'['<<(int)(a/b);
                   if (a%b!=0) cout<<';';
                   a%=b;
                   if (a!=0)
                   {
                         k=a,a=b,b=k;
                         cout<<(int)(a/b);
                         a%=b;
                   }
                   while (a!=0)
                   {
                         k=a,a=b,b=k;
                         cout<<','<<(int)(a/b);
                         a%=b;
                   } 
                   cout<<']'<<endl;
              }
          }
    }
    return 0;
}
