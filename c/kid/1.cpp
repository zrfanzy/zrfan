#include<iostream>
using namespace std;

long a[3000];
int k,n;

void qsort(int i,int j)
{
    int x = i, y = j + 1, tmp = a[i];
    if (j <= i) return;
    while(x != y){
        do
            y--;
        while ((x != y)&&(a[y] >= tmp));
        a[x] = a[y];
        if (x != y){
            do
                x++;
            while ((x != y)&&(a[x] <= tmp));
            a[y] = a[x];
        };
    };
    a[x] = tmp;
    qsort(i, x - 1);
    qsort(x + 1, j);
};

int main()
{
    int i;
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d %Ld %d",&n,&a[0],&k);
    for (i=1;i<=n-1;i++){
        scanf("%Ld",&a[i]);
    }
    qsort(0,n-1);
    for (i=1;i<=n-1;i++){
        if (abs(a[i]-a[i-1])>k){
           printf("No\n");
           exit(0);
        }
    }
    printf("Yes\n");
    return 0;
}
