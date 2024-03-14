#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int h[105][105];
int mr[8] = {0,0,-1,0,1};
int ml[8] = {0,-1,0,1,0};
int f[105][105];
int R,C;

int Dfs(int r,int l){
	if(f[r][l] != 1)
		return f[r][l];
	else{
		int temp = 0;
		for(int i = 1;i <= 4;i ++)
			if(r+mr[i] >= 1 && r+mr[i] <= R && l+ml[i] >= 1 && l+ml[i] <= C && h[r][l] > h[r+mr[i]][l+ml[i]])
				temp = max(temp,Dfs(r+mr[i],l+ml[i])+1);
		f[r][l] = max(f[r][l],temp);
		return f[r][l];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for(int i = 1;i <= R ;i ++)
		for(int j = 1;j <= C;j ++)
			cin >> h[i][j],f[i][j] = 1;
	int ans = 0; 
	for(int i = 1;i <= R;i ++)
		for(int j = 1;j <= C;j ++)
			ans = max(ans,Dfs(i,j));
	cout << ans << endl;
	return 0;
}
