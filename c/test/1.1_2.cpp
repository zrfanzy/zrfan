#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
/*
ID:zrfan3
PROG:gift1
LANG: C++
*/

int main(){
    int n,i,j,k,p,q,l;
    char name[3000][20];
    char name1[20];
    int money[3000];
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++){
      scanf("%s\n",&name[i]);
    }
    i=0;
    for (i=1;i<=n;i++){
      scanf("%s\n",&name1);
      k=0;
      for (j=1;j<=n;j++){
        if (strcmp(name[j],name1)==0) k=j;
      } 
      scanf("%d %d\n",&p,&q);
      money[k]-=p;
      if (q>0)
      money[k]+=p%q;
      for (j=1;j<=q;j++){
        scanf("%s\n",&name1);
        for (l=1;l<=n;l++){
          if (strcmp(name[l],name1)==0){
            money[l]+=int(p/q);
          }
        }
      }
    }
    for (i=1;i<=n;i++){
      printf("%s %d\n",name[i],money[i]);
    }
}
