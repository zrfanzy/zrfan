/*
4��5�����̣������ʼλ�����룬�����ܷ��س�ʼλ�õĲ�ͬ�߷��������߹��ĸ��Ӳ����ظ�����Ҳ��Ҫ����������ߡ��ա��֣� 
*/
#include<iostream>
using namespace std;
const int a[8][2]={1,2,
                   1,-2,
                   -1,2,
                   -1,-2,
                   2,1,
                   2,-1,
                   -2,1,
                   -2,-1};
bool map[10][10];
int ans,n,m;

void search(int p,int q,int all)
{
     int i;
     if (p==n&&q==m&&all>0) {ans++;}
     else
     {
         for (i=0;i<8;i++)
         {
             int x=p+a[i][0],y=q+a[i][1];
             if (x>=0&&x<4&&y>=0&&y<5&&(!map[x][y]))
             {
                 map[x][y]=true;
                 search(x,y,all+1);
                 map[x][y]=false;
             }
         }
     }
}

int main()
{
    freopen("6-1.in","r",stdin);
    freopen("6-1.out","w",stdout);
    scanf("%d %d",&n,&m);
    if (n<=0||n>4||m<=0||m>5) {printf("ERROR");return 0;}
    memset(map,false,sizeof(map));
    ans=0;
    n--;m--;
    search(n,m,0);
    printf("%d\n",ans);
    return 0;
}
/*
���� 
*/ 
