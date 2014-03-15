#include<iostream>
#include <cmath>
using namespace std;

double p,q,f1,f2;
int k1,k2,k;

int main()
{
    freopen("conductor.in","r",stdin);
    freopen("conductor.out","w",stdout);
    cin>>p>>q;
    k=1;
    while(1)
    {
        f1=k*p/100;
        f2=k*q/100;
        k1=int(f1);
        k2=int(f2);
        if(k1<k2&&f1-k1>1e-9&&f2-k2>1e-9)break;
        ++k;
    }
    cout<<k<<endl;
    return 0;
}
