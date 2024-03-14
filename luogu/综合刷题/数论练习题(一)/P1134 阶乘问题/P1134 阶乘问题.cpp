#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n,ans = 1;
int a[4] = {6,8,4,2};

int main() {
    scanf("%d",&n);
    while(n) {
        for(ri i = 1;i <= n%10;i ++)
            if(i!=5)
				ans = ans * i % 10;
        n /= 5;
        ans = ans * a[n%4] % 10;
    }
    printf("%d",ans);
    return 0;
}
