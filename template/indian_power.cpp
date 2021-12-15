long long _pow(long long a,long long b){
  long long c = 1;
  for(;b;b/=2,a=a*a)
    if(b&1)c=c*a;
  return c;
}