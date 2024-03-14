#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int v[55][55];
int f[55][55][55][55];
int n,m;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= m;j ++)
			cin >> v[i][j];
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= m;j ++)
			for(ri k = 1;k <= n;k ++)
				for(ri l = j + 1;l <= m;l ++)
					f[i][j][k][l] = max(max(f[i-1][j][k-1][l],f[i][j-1][k][l-1]),max(f[i-1][j][k][l-1],f[i][j-1][k-1][l])) + v[i][j] + v[k][l];
    cout << f[n][m-1][n-1][m] << endl;
	return 0;
}
