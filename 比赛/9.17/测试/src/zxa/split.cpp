#include <cstdio>
using namespace std;
const int maxn = 55;
// f[i][j][k] 前i个珠子，分成j段，能否and出k 
bool f[maxn][maxn][1050];
int a[maxn], xo[maxn];
int main() {
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	int n, L, R;
	scanf("%d%d%d", &n, &L, &R);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		xo[i] = xo[i - 1] ^ a[i];
	}
	//f[i][j][k] -> f[p][j + 1][xo[i + 1 ~ p] & k]
	for (int i = 0; i <= 1024; i ++) f[0][0][i] = 1;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < R; j ++)
			for (int k = 0; k <= 1024; k ++) {
				if (!f[i][j][k]) continue;
				for (int p = i + 1; p <= n; p ++)
					f[p][j + 1][(xo[p] ^ xo[i]) & k] = 1;
			}
	int mx = 0;
	for (int i = L; i <= R; i ++)
		for (int j = 1024; j >= mx; j --)
			if (f[n][i][j]) { mx = j; break; }
	printf("%d\n", mx);
	/*for (int i = 1; i <= R; i ++)
		for (int j = 0; j <= 10; j ++)
			if (f[n][i][j]) printf("%d %d %d\n", n, i, j);*/
	return 0;
}
