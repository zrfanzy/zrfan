#include<iostream>
#include<stdio.h>
using namespace std;
/*
ID:zrfan3
PROG:beads
LANG:C++
*/

int main(){
  freopen("beads.in","r",stdin);
  freopen("beads.out","w",stdout);
  char a[500];
  char k;
  int n,i,ans,a1,a2,b1,b2;
  scanf("%d %s",&n,a);
  ans=0;
  for (i=0;i<n;i++){
    a1=0;
    b1=i;
    b2=i;
    while ((a[b1]=='w')&&(a1<n)){
      b2=b1;
      b1-=1;a1+=1;
      if (b1<1) b1=n-1;
    }
    k=a[b1];
    while (((a[b1]==k)||(a[b1]=='w'))&&(a1<n)){
      b2=b1;
      b1-=1;
      a1+=1;
      if (b1<0) b1=n-1;
    }
    b1=i+1;
    if (b1>=n) b1=1;
    a2=b1;
    while ((a[b1]=='w')&&(a1<n)&&(b1!=b2)){
      a2=b1;
      b1+=1;a1+=1;
      if (b1>=n) b1=0;
    } 
    k=a[b1];
    while (((a[b1]==k)||(a[b1]=='w'))&&(a1<n)&&(b1!=b2)){
      a2=b1;
      b1+=1;
      a1+=1;
      if (b1>=n) b1=0;
    }      
    if (a2==b2) a1-=1;
    if (a1>ans) ans=a1;
  }
  
  printf("%d\n",ans);
}
