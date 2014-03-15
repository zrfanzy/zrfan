#include<iostream>
using namespace std;
bool f[30];
int n,i,j;

bool dg(int p)

{
     int k,k1,l;
    k1=0;memset(f,true,sizeof(f));
    for (k=1;k<=n;k++)
    {
        if (p%(2*n-k+1)!=0){
            for (l=1;l<=(p%(2*n-k+1));l++)
            {
              k1++;
              if (k1>2*n) k1=1;
              while (!f[k1]){k1++;if (k1>2*n) k1=1;}
            }
        }
        else for (l=1;l<=2*n-k+1;l++)
        {
            k1++;
            if (k1>2*n) k1=1;
            while (!f[k1]){k1++;if (k1>2*n) k1=1;}

        }
        f[k1]=false;
        if (k1<=n) return false;
        k1--;if (k1<1) k1=2*n;
        while (!f[k1]){k1--;if (k1<1) k1=2*n;}
    }
    return true;
}

int main()
{
    freopen("joseph.in","r",stdin);
    freopen("joseph.out","w",stdout);
    cin>>n;
    i=n+1;
    while (!dg(i)){
          i++;}
    cout<<i<<endl;
    return 0;
}
