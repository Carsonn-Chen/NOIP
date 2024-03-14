#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define maxn 100000
#define ri register int

using namespace std;

int a[105];

int main() {
	int p;
	scanf("%d",&p);
	printf("%d\n",(int)(p*log10(2.0)+1));
	int left = p % 10;
	p = p/10;
	a[0] = 1;
	for(ri i = 1;i <= p;i ++) {
		for(ri j = 0;j <= 100;j ++)
			a[j] <<= 10;
		for(ri j = 0;j <= 100;j ++) {
			if(a[j] >= maxn) {
				a[j+1] += a[j]/maxn;
				a[j] %= maxn;
			}
		}
	}
	for(ri i = 1;i <= left;i ++) {
		for(ri j = 0;j <= 100;j ++)
			a[j] <<= 1;
		for(ri j = 0;j <= 100;j ++) {
			if(a[j] >= maxn) {
				a[j+1] += a[j]/maxn;
				a[j] %= maxn;
			}
		}
	}
	a[0]--;
	for(ri i = 99;i >= 0;i --) {
		printf("%05d",a[i]);
		if(i%10 == 0)
			printf("\n");
	}
	return 0;
}
