#include<iostream>
#include<cstring>
using namespace std;
char s1[30],s2[30];
char now[3000][30],now1[3000][30];
int all[3000];
int n,i,k,j,count1,w;
bool f;

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    memset(s1,0,sizeof(s1));
    memset(now,0,sizeof(now));
    scanf("%s\n",s1);
    while (!feof(stdin))
    {
          n++;
          memset(s2,0,sizeof(s2));
          scanf("%s",s2);
          strcpy(now[n],s2);
          f=false;
          for (i=0;(i<strlen(s2)&& !f);i++)
          {
              if (s2[i]=='.') f=true;
          }
          if (!f) scanf("%d\n",&all[n]);
          else all[n]=0;
          if (f&&strcmp(s2,s1)==0)
          {
                count1=1;w=0;
                memset(now1,0,sizeof(0));
                for (j=n-1;j>=1;j--){
                    count1+=1;
                    if (count1<=(all[j]+1)){
                       strcpy(now1[++w],now[j]);
                       count1=1;
                    }
                    else count1-=all[j];
                }
                for (j=w;j>=1;j--) printf("%s\\",now1[j]);
                printf("%s\n",s1);
          }
    }
    return(0);
}
