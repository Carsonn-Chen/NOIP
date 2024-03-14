#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#define ri register int

using namespace std;

int n,m;
int a[1005];
long long f[1005][1005];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ri i = 1;i <= n;i ++)	
		cin >> a[i];
	f[0][0] = 1;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 0;j <= m;j ++)
			for(ri k = 0;k <= a[i];k ++)
				f[i][j] = (f[i-1][j-k]+f[i][j])%1000007;
	cout << f[n][m] << endl;
	return 0;
}
