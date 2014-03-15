#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
/*
ID:zrfan3
PROG:ride
LANG: C++
*/
int main(){
  char a[7],b[7];
  int a1,b1,i;
  a1=1;b1=1;
  freopen("ride.in","r",stdin);
  freopen("ride.out","w",stdout);
  scanf("%s %s",&a,&b);
  for(i=0;i<strlen(a);i++){
    a1*=a[i]-64;                     
  }
  for(i=0;i<strlen(b);i++){    
    b1*=b[i]-64;
  }       
  if ((a1%47)==(b1%47)) printf("%s\n","GO");
  else printf("%s\n","STAY");
  return 0;
}
