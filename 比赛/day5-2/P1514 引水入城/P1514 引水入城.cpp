#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

int n,m;
int h[505][505];
bool vis[505][505];

void dfs(int r,int l){
	if(vis[r][l])
		return;
	vis[r][l] = 1;
	if(h[r][l] > h[r-1][l])
		dfs(r-1,l);
	if(h[r][l] > h[r+1][l])
		dfs(r+1,l);
	if(h[r][l] > h[r][l-1])
		dfs(r,l-1);
	if(h[r][l] > h[r][l+1])
		dfs(r,l+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= m;j ++)
			cin >> h[i][j];
	for(ri i = 0;i <= m+1;i ++)
		h[0][i] = h[n+1][i] = INT_MAX;
	for(ri i = 0;i <= n+1;i ++)
		h[i][0] = h[i][m+1] = INT_MAX;
	for(ri i = 1;i <= m;i ++)
		dfs(1,i);
	int ans = 0;
	for(ri i = 1;i <= m;i ++)
		if(!vis[n][i])
			ans ++;
	cout << 0 << endl;
	cout << ans << endl;
	return 0;
}
