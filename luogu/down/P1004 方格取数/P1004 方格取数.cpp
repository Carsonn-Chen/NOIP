#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int num[15][15];
int n;
int f[15][15][15][15];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int a,b,c;
	cin >> a >> b >> c;
	while(a != 0 && b != 0 && c != 0){
		num[a][b] = c;
		cin >> a >> b >> c;
	}
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++)	
			for(ri k = 1;k <= n;k ++)	
				for(ri l = 1;l <= n;l ++){
					f[i][j][k][l] = num[i][j] + num[k][l] + max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]));
					if(i == k && l == j)
						f[i][j][k][l] -= num[i][j];
				}
	cout << f[n][n][n][n] << endl;
	return 0;
}
