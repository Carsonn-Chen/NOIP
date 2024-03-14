#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int a[305][305];
int n,s;

void Floyed() {
	for(ri k=1; k<=n; k++) {
		for(ri i=1; i<=n; i++) if(a[i][k]!=1e9) {
				for(ri j=1; j<=n; j++) if(a[k][j]!=1e9) {
						if(a[i][k]+a[k][j]<a[i][j]) {
							a[i][j]=a[i][k]+a[k][j];
						}
					}
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++)
			if(i != j)
				a[i][j] = 1e9;
	for(ri i = 1;i < n;i ++) {
		int x,y,w;
		cin >> x >> y >> w;
		a[x][y] = a[y][x] =w;
	}
	Floyed();
	int ans = 1e9;
	for(ri i = 1;i <= n;i ++) {
		for(ri j = 1;j <= n;j ++) {
			if(a[i][j] <= s) {
				int dis = 0;
				for(ri k = 1;k <= n;k ++) {
					if(i != k && j != k)
						dis = max(dis,a[i][k]+a[j][k]-a[i][j]);
				}
				ans = min(ans,dis);
			}
		}
	}
	cout << ans/2 << endl;
	return 0;
}
