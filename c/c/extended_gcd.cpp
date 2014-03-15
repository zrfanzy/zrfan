long extended_gcd(long a,long b,long x,long y){
     if (b==0){
        return(a);x=1;y=0;
     }
     else {
          t=x;
          x=y;
          y=t-(a/b)*y;
          return(extended_gcd(b,a%b));
     }
}
