#include<iostream>
using namespace std;
char ch[100];
int n,i,j,a[100],b[100],k;
bool f,ff;

int main()
{
    //freopen("1047.in","r",stdin);
    //freopen("1047.out","w",stdout);
    while (!feof(stdin))
    {
          memset(ch,0,sizeof(ch));
          memset(b,0,sizeof(b));
          memset(a,0,sizeof(a));
          scanf("%s ",ch);
          n=strlen(ch);
          f=true;
          for (i=0;i<n;i++)
          {
              a[n-i-1]=(int)(ch[i])-(int)('0');
              b[n-i-1]=a[n-i-1];
          }
          for (j=0;j<n-1;j++)
          {
              for (i=0;i<n;i++)
              {
                  b[i]+=a[i];
                  b[i+1]+=b[i]/10;
                  b[i]%=10;
              }
              if (b[n]>0)
              {
                  f=false;
                  printf("%s is not cyclic\n",ch);break;
              }
              ff=false;
              for (i=0;i<n;i++)
                  if (b[i]==a[0])
                  {
                      ff=true;
                      for (k=0;k<n;k++)
                          if (b[(i+k)%n]!=a[k])
                          { ff=false;
                            break;}
                      if (ff==true) {break;}
                  }
              //for (i=n-1;i>=0;i--) printf("%d",b[i]);
              //printf("\n");
              if (!ff) {printf("%s is not cyclic\n",ch);f=false;break;}
          }
          if (f) printf("%s is cyclic\n",ch);
    }
    return 0;
}
