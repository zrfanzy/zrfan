#include<iostream>
#include<cmath>
using namespace std;
float n,m;
int i;

int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    cin>>n;
    n*=2;
    for (i=(int)(n/2);i>=2;i--)
    {
        if ((int)(n)%i==0)
        {
            m=n/i;
            float x=(m-(i-1))/2;
            if (x-(int)x<=1e-4&&x>0)
            {
                int y=(m-(i-1))/2;
                cout<<y<<' '<<y+i-1<<endl;
            }
        }
    }
    return 0;
}
