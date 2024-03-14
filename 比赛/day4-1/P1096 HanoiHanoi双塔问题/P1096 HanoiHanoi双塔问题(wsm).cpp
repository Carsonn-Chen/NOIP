#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#define ri register int

using namespace std;

int a[305];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	a[1] = 1;
	int len = 1;
	for(ri i = 1;i <= n;i ++) {
		for(ri j = 1;j <= len;j ++)
			a[j] *= 2;
		for(ri j = 1;j <= len;j ++) {
			a[j+1] += a[j]/10;
			a[j] %= 10;
		}
		if(a[len+1])
			len ++;
	}
	int i1 = 1;
	while(a[i1] == 0) {
		a[i1] += 10;
		a[++i1] --;
	}
	a[1] --;
	for(ri j = 1;j <= len;j ++)
		a[j] *= 2;
	for(ri j = 1;j <= len;j ++) {
		a[j+1] += a[j]/10;
		a[j] %= 10;
	}
	if(a[len+1])
		len ++;
	for(ri i = len;i >= 1;i --)
		printf("%d",a[i]);
	return 0;
}
