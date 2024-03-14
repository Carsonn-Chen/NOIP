#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int n,m,r,c;
int num[20][20];
int ans[20],cnt = 1;
int sum1[20],sum2[20][20];
int f[20][20];
int minn = 2147483647;
int temp;

void solve() {
	for(int i = 1; i <= m; i ++) {
		sum1[i] = 0;
		for(int j = 1; j < r; j ++) {
			sum1[i] += abs(num[ans[j]][i]-num[ans[j+1]][i]);
		}
	}
	for(int i = 2; i <= m; i ++) {
		for(int j = 1; j < i; j ++) {
			sum2[i][j] = 0;
			for(int k = 1; k <= r; k ++) {
				sum2[i][j] += abs(num[ans[k]][i]-num[ans[k]][j]);
			}
		}
	}
	
	for(int i = 1; i <= m; i ++) {
		temp = min(i,c);
		for(int j = 1; j <= temp; j ++) {
			if(j == 1)
				f[i][j] = sum1[i];
			else if(i == j)
				f[i][j] = f[i-1][j-1]+sum1[i]+sum2[i][j-1];
			else{
				f[i][j] = 2147483647;
				for(int k = j-1; k < i; k ++) 
					f[i][j] = min(f[i][j],f[k][j-1]+sum1[i]+sum2[i][k]);
			}
			if(j == c)
				minn = min(minn,f[i][c]);
		}
	}
}

void dfs(int node) {
	if(node > n) {
		solve();
		return;
	}
	if(r-cnt+1 == n-node+1) {
		ans[cnt++] = node;
		dfs(node+1);
		ans[cnt--] = 0;
		return;
	}
	dfs(node+1);
	if(cnt <= r) {
		ans[cnt++] = node;
		dfs(node+1);
		ans[cnt--] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> r >> c;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> num[i][j];
	dfs(1);
	cout << minn << endl;
	return 0;
}
