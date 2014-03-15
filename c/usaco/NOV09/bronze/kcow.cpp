#include<iostream>
#include<cstring>
using namespace std;
char c;
int i,j,x,y,x1,y1,x2,y2,start,all1;
int all[22505][2];
int f1[155][155];
bool f[155][155];
int n[2][8]={{1,1,-1,-1,2,2,-2,-2},
             {2,-2,2,-2,1,-1,1,-1}};
             
/*
ID:zrfan3
TASK:kcow
LANG:C++
*/

int main()
{
    FILE *fin=fopen("kcow.in","r");
    FILE *fout=fopen("kcow.out","w");
    fscanf(fin,"%d %d\n",&y,&x);
    memset(f1,false,sizeof(f1));
    for (i=1;i<=x;i++)
    {
        for (j=1;j<=y;j++)
        {
            fscanf(fin,"%c",&c);
            if (c=='*') f[i][j]=false;else f[i][j]=true;
            if (c=='K') {x1=i,y1=j;}
            if (c=='H') {x2=i,y2=j;}
        }
        fscanf(fin,"\n");
    }
    all[1][0]=x1,all[1][1]=y1;
    start=0,f1[x1][y1]=1;all1=1;
    while (1)
    {
          start++;
          for (i=0;i<8;i++)
          {
              int x3=all[start][0]+n[0][i],y3=all[start][1]+n[1][i];
              if (x3>0&&x3<=x&&y3>0&&y3<=y&&!f1[x3][y3]&&f[x3][y3])
              {
                  f1[x3][y3]=f1[all[start][0]][all[start][1]]+1;
                  if (x3==x2&&y2==y3) {fprintf(fout,"%d\n",f1[x3][y3]-1);return 0;}
                  all1++;
                  all[all1][0]=x3,all[all1][1]=y3;
              }
          }
    }
    return 0;
}
