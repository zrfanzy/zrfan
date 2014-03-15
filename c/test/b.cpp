#include<vector>
#include<string>


class DifferentStrings
{
public:
  vector <int> minimize(string A, string B);
};

vector <int> minimize(string A, string B)
{
   int la=A.length();
   int lb=B.length();
   vector <int> max;
   int max1=0;
   for (int i=1;i<=la;i++){
     for (int j=1;i<=lb;j++){
       int t=0,l1=i,l2=j;
       while ((A[l1]=B[l2])&&(l1<=la)&&(l2<=lb)){
         l1+=1;
         l2+=1;
         t+=1;
       }
       if (t>max1)
         max1=t;
     }
   }
   max.push_back(max1);
   return max;
}

