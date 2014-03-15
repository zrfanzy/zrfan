/*
ID: zrfan3
LANG: C++
PROG: traffic
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;
char C[305];
int R[305],B[305],U[305],ini , fin,n,m,x,y,p;
vector <int> Adj[305];
bool Cogi[305];
int P[305];
char Color(int nod ,int time)
{
  if(time < R[nod]) return C[nod];
  time-=R[nod];
  time%=U[nod] + B[nod];
  if(C[nod] == 'B')
  {
    if(time < U[nod])return 'P';
    return 'B';
  }
    if(time < B[nod])return 'B';
    return 'P';
}
void Dikjstra()
{
 for(int i = 0 ; i < n ; i++)
  {
   Cogi[i] = 0;
   P[i] = 2147483647;
  }
  P[ini] = 0;
  for(int kk =0 ; kk< n-1 ; kk++)
  {
    int m1 = -1;
    for(int i = 0 ; i < n ; i++)
      {
       if(Cogi[i]) continue;
       if(m1 == -1 || P[m1] > P[i])
          m1 = i;
      }
      if(m1 == -1 || P[m1] == 2147483647) break;
    Cogi[m1] = true;
    for(int i = 0 ; i < Adj[m1].size();i+=2)
    {

       int t = P[m1];
       int m2 = Adj[m1][i];
       if(Cogi[m2]) continue;
       // caluclar t1
       int t1 = t;
       bool enc = 0;

       for(t1 = t ; t1<= t+50005;t1++)
       if(Color(m2,t1) == Color(m1,t1)){
         enc = 1;
         break;
       }

       if(enc && t1 + Adj[m1][i+1] < P[m2])
          P[m2] =  t1 + Adj[m1][i+1];
    }
  }
   if(P[fin] == 2147483647)P[fin] = 0;

}
int main()
{
FILE * in = fopen("traffic.in","r");
  FILE * out = fopen("traffic.out","w");

  fscanf(in,"%d%d",&ini,&fin);  ini--;fin--;
  fscanf(in,"%d%d",&n,&m);
  for(int i = 0 ; i < n ; i++)
  {
    while(1) {
    fscanf(in,"%c",&C[i]);
    if( C[i]== 'B' || C[i] == 'P')break;
    }

    fscanf(in,"%d%d%d",R+i,B+i,U+i);
  }
  while(m--)
  {
    fscanf(in,"%d%d%d",&x,&y,&p);x--;y--;
    Adj[x].push_back(y);
    Adj[x].push_back(p);
    Adj[y].push_back(x);
    Adj[y].push_back(p);
  }
  Dikjstra();
  fprintf(out,"%d\n",P[fin]);
  return 0;
}
