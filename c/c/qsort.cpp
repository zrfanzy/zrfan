#include<stdio.h>
int a[101];
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

int main(void)
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int i, j, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    qsort(1, n);
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
};

