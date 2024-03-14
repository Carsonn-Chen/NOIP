#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

int main(int argc, char** argv)
{
  freopen(argv[1],"w",stdout);
  srand(time(NULL));
  int N=1+rand()%100;
  printf("%d\n",N);
  for (int i=1; i<=N; i++)
  {
    int x=1+rand()%1000;
    printf("%d ",x);
  }
  return 0;
}
