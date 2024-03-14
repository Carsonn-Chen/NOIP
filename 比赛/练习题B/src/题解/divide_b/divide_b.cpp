#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const double PI= acos(-1.0);

const int MXN = 100000;
int n, m;
int a[MXN];
int check (int m) {
	int t, ans;
	t = 0;
	ans = 1;
	for (int i = 0; i < n; i++) {
		if (t + a[i] <= m)
			t += a[i];
		else {
			t = a[i];
			ans ++;
		}
	}
	return ans;
}
int main() {
	freopen("divide_b.in", "r", stdin);
	freopen("divide_b.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	int l = 0,r = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		r += a[i];
		l = max (l, a[i]);
	}
	while (l < r) {
		int mid = l+(r-l>>1);
		if (check(mid) <= m)
			r = mid;
		else
			l = mid + 1;
	}
	printf ("%d\n", l);
}
