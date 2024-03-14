#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

long long a,b,c[50],d[50],ans,n;

int main() {
	cin >> a >> n;
	for(ri i = 1;i <= a;i ++) {
		cin >> b;
		c[b] ++;
	}
	for(ri i = 1;i <= n;i ++) {
		cin >> b;
		d[b] ++;
	}
	for(ri i = 10;i <= 40;i ++)
		ans += min(d[i],c[i]);
	cout << ans << endl;
}
