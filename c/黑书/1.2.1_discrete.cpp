#include<iostream>
using namespace std;
long long n,i,max1,maxi;
long long a[100005];

int main()
{
    freopen("discrete.in","r",stdin);
    freopen("discrete.out","w",stdout);
    cin>>n;
    max1=0;
    cin>>a[1]>>a[2];
    max1=a[2]-a[1],maxi=2;
    if (max1<0) max1*=-1;
    for (i=3;i<=n;i++)
    {
        cin>>a[i];
        if (i>1)
        {
            long long k1=a[i]-a[i-1];
            if (k1<0) k1*=-1;
            if (k1>max1) {max1=k1;maxi=i;}
        }
    }
    cout<<maxi-1<<" "<<maxi;
    return 0;
}
