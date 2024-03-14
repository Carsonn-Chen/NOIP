//#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
const int maxn = 1e6 + 5;
struct node { int x, y; } a[maxn], b[maxn];
int c[2 * maxn], fa[2 * maxn], len, n;
inline int getfa(int x) {
	int tmp = x;
	while (fa[tmp] != tmp) tmp = fa[tmp];
	while (x != tmp) {
		int tmp2 = fa[x];
		fa[x] = tmp;
		x = tmp2;
	}
}
inline void init(int &x) {
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
}
inline int erfen(int x) {
	int l = 1, r = len;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (c[mid] > x) r = mid - 1;
		else l = mid;
	}
	return l;
}
int main() {
	freopen("ribbon.in", "r", stdin);
	freopen("ribbon.out", "w", stdout);
	init(n);
	for (int i = 1; i <= n; i ++) {
		init(a[i].x); init(a[i].y);
		a[i].y --;
		c[++ len] = a[i].x; c[++ len] = a[i].y;
	}
	sort(c + 1, c + 1 + len);
	len = unique(c + 1, c + 1 + len) - c - 1;
	for (int i = 1; i <= n; i ++)
		b[i].x = erfen(a[i].x), b[i].y = erfen(a[i].y);
	/*for (int i = 1; i <= len; i ++) {
		if (c[i] != c[i - 1]) tmp ++;
		M[c[i]] = tmp;
	}
	for (int i = 1; i <= n; i ++)
		b[i].x = M[a[i].x], b[i].y = M[a[i].y];*/
	
	for (int i = 0; i <= len; i ++) fa[i] = i;
	int ans = 0;
	for (int i = n; i >= 1; i --) {
		int gx = getfa(b[i].y), ok = 0;
		while (gx >= b[i].x && gx) {
			ok = 1;
			int gy = getfa(gx - 1);
			fa[gx] = gy;
			gx = gy;
		}
		ans += ok;
	}
	printf("%d\n", ans);
	return 0;
}
