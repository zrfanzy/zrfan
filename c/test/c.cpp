#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>

int main()
{
      int s;
      string a;
      int q='A'-1;
      s=1;

      scanf("%s\n",&a);
      for (int i;i++;i<=a.size()){
        int k=a[i];
        s=s*(k-q);
      }
      if (s%47==0) printf("%s\n","GO");
      else printf("%s\n","STAY");
      system("PAUSE");
      return 0;
}
