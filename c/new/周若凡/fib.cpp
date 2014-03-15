#include<iostream>
using namespace std;
long n;
int jz[3][3],jz1[3][3],jz2[3][3],jz3[3][3];

inline void cheng(long p)
{
       if (p==1) return;
       else 
       {if (p%2==0) {cheng((int)(p/2));
          jz2[0][0]=jz1[0][0]*jz1[0][0]+jz1[0][1]*jz1[1][0];
          jz2[0][1]=jz1[0][0]*jz1[0][1]+jz1[0][1]*jz1[1][1];
          jz2[1][0]=jz1[1][0]*jz1[0][0]+jz1[1][1]*jz1[1][0];
          jz2[1][1]=jz1[1][0]*jz1[0][1]+jz1[1][1]*jz1[1][1];}
       else {
          cheng((p/2));
          jz2[0][0]=jz1[0][0]*jz1[0][0]+jz1[0][1]*jz1[1][0];
          jz2[0][1]=jz1[0][0]*jz1[0][1]+jz1[0][1]*jz1[1][1];
          jz2[1][0]=jz1[1][0]*jz1[0][0]+jz1[1][1]*jz1[1][0];
          jz2[1][1]=jz1[1][0]*jz1[0][1]+jz1[1][1]*jz1[1][1];
                   
          jz3[0][0]=jz2[0][0]*jz[0][0]+jz2[0][1]*jz[1][0];
          jz3[0][1]=jz2[0][0]*jz[0][1]+jz2[0][1]*jz[1][1];
          jz3[1][0]=jz2[1][0]*jz[0][0]+jz2[1][1]*jz[1][0];
          jz3[1][1]=jz2[1][0]*jz[0][1]+jz2[1][1]*jz[1][1];
       
          for (int p1=0;p1<=1;p1++)
           for (int q1=0;q1<=1;q1++)
               jz2[p1][q1]=jz3[p1][q1]%1729;
       }
       for (int p1=0;p1<=1;p1++)
           for (int q1=0;q1<=1;q1++)
               jz1[p1][q1]=jz2[p1][q1]%1729;
       }
}

int main()
{
    freopen("fib.in","r",stdin);
    freopen("fib.out","w",stdout);
    cin>>n;
    if (n<=2) cout<<1<<endl;
    else
    {
        jz[0][0]=1,jz[0][1]=1,jz[1][0]=1,jz[1][1]=0;
        jz1[0][0]=1,jz1[0][1]=1,jz1[1][0]=1,jz1[1][1]=0;
        cheng(n-2);
        cout<<((jz1[0][0]+jz1[1][0])%1729)<<endl;
    }
    return 0;
}
