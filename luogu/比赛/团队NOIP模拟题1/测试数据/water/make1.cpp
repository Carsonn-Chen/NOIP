#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  srand(time(NULL));
  freopen("water19.in","w",stdout);
  int test=1+rand()%10;
  printf("%d\n",test);
  for (int i=1; i<=test; i++)
  {
    int x=1+rand()%1000;
    int y=1+rand()%1000;
    printf("%d\n",x*y);
  }
  return 0;
}
