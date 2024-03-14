#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n,sum;
bool via[15];
int ans[15];
int leijia[15][15];

void Dfs(int x,int summ){
	if(summ > sum)
		return ;
	if(summ == sum && x == n+1){
		for(register int i = 1;i <= n;i ++)
			cout << ans[i] << " ";
		exit(0);
	}
	for(int i = 1;i <= n;i ++){
		if(!via[i]){
			via[i] = 1;
			ans[x] = i;
			Dfs(x+1,summ+i*leijia[n][x]);
			via[i] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> sum;
	leijia[1][1] = 1;
	for(int i = 2;i <= n;i ++)
		for(int j = 1;j <= i;j ++)
			leijia[i][j] = leijia[i-1][j] + leijia[i-1][j-1];
	Dfs(1,0);
	return 0;
}
