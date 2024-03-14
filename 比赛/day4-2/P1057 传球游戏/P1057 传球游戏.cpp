#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n,m;
int f[35][65];
int num[65];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	f[1][2] = f[1][n] = 1;
	for(ri i = 2;i <= m;i ++)
		for(ri j = 1;j <= n;j ++){
			if(j == 1)
				f[i][j] = max(f[i][j],f[i-1][2] + f[i-1][n]);
			else if(j == n)
				f[i][j] = max(f[i][j],f[i-1][1] + f[i-1][n-1]);
			else
				f[i][j] = max(f[i][j],f[i-1][j-1] + f[i-1][j+1]);
		}
	cout << f[m][1] << endl;
	return 0;
}
