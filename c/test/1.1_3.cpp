#include<iostream>
#include<stdio.h>
using namespace std;

/*
ID:zrfan3
PROG:friday
LANG:C++
*/

int main(){
  int n,i,j,dd;
  int d,k;
  int month1[100];
  for (i=0;i<=6;i++){
    month1[i]=0;
  }
  freopen("friday.in","r",stdin);
  freopen("friday.out","w",stdout);
  scanf("%d",&n);
  d=7;dd=0;
  for (i=1900;i<=1900+n-1;i++){
    for (j=1;j<=12;j++){
      switch(j){
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
           dd=31;
      break;
      case 4:
      case 6:
      case 9:
      case 11:
           dd=30;
      break;
      case 2:
           if ((i %4==0)&&(i %100!=0 || i %400 ==0)) dd=29;
           else dd=28;
      break;
      }
      for (k=1;k<=dd;k++){
        d+=1;
        d%=7;
        if ((k==13)) 
          month1[d]+=1;
      }          
    }
  }
  printf("%d",month1[6]);
  for (i=0;i<=4;i++){
    printf(" %d",month1[i]);
  }
  printf(" %d\n",month1[5]);
}
