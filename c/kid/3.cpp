#include<iostream>
using namespace std;

int a,b,n,i,k,color,l,j;
int data[2000][10];
bool flat[200][200];
bool flat1[200];
bool dflat[20000];
bool ff;

int main()
{
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    scanf("%d %d %d",&a,&b,&n);
    for(i=1;i<=n;i++)
        for (j=1;j<=5;j++) { scanf("%d",&data[i][j]); flat1[data[i][5]]=true;}
    while (!feof(stdin))
    {
          scanf("%d %d",&k,&j);
          flat[k][k]=true;
          if (k>color) color=k;
          for (i=1;i<=j;i++) 
          {
              scanf("%d",&l);
              flat[k][l]=true;
          }
    }
    for (k=1;k<=color;k++)
        for (i=1;i<=color;i++)
            for (j=1;j<=color;j++)
                if (flat[i][k]&&flat[k][j]) flat[i][j]=true;
    memset(dflat,true,sizeof(dflat));
    for (i=1;i<=n;i++){
        for (j=i+1;j<=n;j++){
            if ((data[i][1]>=data[j][1])&&(data[i][2]>=data[j][2])&&(data[i][3]<=data[j][3])&&(data[i][4]<=data[j][3]))
               dflat[i]=false;
        }
    }
    for (i=1;i<=color;i++){
        ff=true;
        if (flat1[i]){
           for (j=1;j<=n;j++)
                if (dflat[j]&&flat[i][data[j][5]]==false) {ff=false; break;}
           if (ff) {
              printf("%d\n",i);
              exit(0);
           }
        }
    }
    printf("Escape\n");
    return 0;
}
