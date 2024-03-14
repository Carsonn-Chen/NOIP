#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 5005
#define inf 1e18
#define ll long long
using namespace std;
int n,m,q;
ll f[maxn][maxn];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			f[i][j] = inf; f[i][i] = 0;
		}
	}
	for (int i = 1; i <= n; i ++) {
		int w; cin >> w;
		if(i == n) { f[n][1] = w; f[1][n] = w; }
		else f[i][i + 1] = w; f[i + 1][i] = w;
	}
	for (int i = 1; i <= m; i ++) {
		int u,v,w; cin >> u >> v >> w;
		f[u][v] = w; f[v][u] = w;
	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if(f[i][j] > f[i][k] + f[k][j]){
					f[i][j] = f[i][k] + f[k][j];
				}
			}
		}
	}
	cin >> q;
	while(q--){
		int u,v; cin >> u >> v;
		cout << f[u][v] << endl;
	}
	return 0;
}
