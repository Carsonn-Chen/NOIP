#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const long long inf = 1e14;
const int maxn = 205;
int n, m, mod;
int a[maxn][maxn], b[maxn][maxn], X[5], Y[5];
long long d[4][maxn][maxn], D[5][5];
bool in[maxn][maxn];
struct node { int x, y; } tt[maxn * maxn];
inline bool check(int x, int y, int x2, int y2, int k) {
	return abs(x - x2) + abs(y - y2) <= k;
}
inline void spfa(long long d[maxn][maxn], int x, int y) {
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			d[i][j] = -1;
	d[x][y] = 0;
	int head = 0, end = 1;
	tt[head].x = x; tt[head].y = y;
	while (head != end) {
		x = tt[head].x; y = tt[head].y;
		head = (head + 1) % mod;
		in[x][y] = 0;
		for (int i = -a[x][y]; i <= a[x][y]; i ++) {
			if (x + i < 1 || x + i > n) continue;
			int tmp = a[x][y] - abs(i);
			for (int j = -tmp; j <= tmp; j ++) {
				int x1 = x + i, y1 = y + j;
				if (y1 < 1 || y1 > m) continue;
				if (check(x, y, x1, y1, a[x][y]))
					if (d[x1][y1] == -1 || d[x1][y1] > d[x][y] + b[x][y]) {
						d[x1][y1] = d[x][y] + b[x][y];
						if (!in[x1][y1]) {
							if (head != end && d[x1][y1] < d[tt[head].x][tt[head].y]) {
								head = (head - 1 + mod) % mod;
								tt[head].x = x1; tt[head].y = y1;
							} else {
								tt[end].x = x1; tt[end].y = y1;
								end = (end + 1) % mod;
							}
							in[x1][y1] = 1;
						}
					}
			}
		}
	}
}
int main() {
	freopen("friend.in", "r", stdin);
	freopen("friend.out", "w", stdout);
	scanf("%d%d", &n, &m);
	mod = n * m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", &b[i][j]);
	for (int i = 1; i <= 3; i ++) {
		scanf("%d%d", &X[i], &Y[i]);
		spfa(d[i], X[i], Y[i]);
	}
	long long ans = inf; char ans2;
	for (int i = 1; i <= 3; i ++)
		for (int j = 1; j <= 3; j ++) {
			if (i == j) continue;
			D[i][j] = d[i][X[j]][Y[j]];
		}
	if (D[2][1] != -1 && D[3][1] != -1) {
		long long tmp = D[2][1] + D[3][1];
		if (tmp < ans) ans = tmp, ans2 = 'X';
	}
	if (D[1][2] != -1 && D[3][2] != -1) {
		long long tmp = D[1][2] + D[3][2];
		if (tmp < ans) ans = tmp, ans2 = 'Y';
	}
	if (D[1][3] != -1 && D[2][3] != -1) {
		long long tmp = D[1][3] + D[2][3];
		if (tmp < ans) ans = tmp, ans2 = 'Z';
	}
	if (ans == inf) printf("NO\n");
	else printf("%c\n%I64d\n", ans2, ans);
	return 0;
}
