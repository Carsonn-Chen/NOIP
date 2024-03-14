#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int num[8][8];
int ans;
int n,m;
int via[8][8];
int mr[15]={0,-1,-1,-1,0,0,0,1,1,1};
int ml[15]={0,-1,0,1,-1,0,1,-1,0,1};


void Dfs(int r,int l,int tot){
	if(r > n || l > m)
		return;
	tot += num[r][l];
	ans = max(ans,tot);
	for(register int i = 1;i <= 9;i ++)
			via[r+mr[i]][l+ml[i]] ++;
	for(register int i = l+1;i <= m;i ++)
		if(!via[r][i])
			Dfs(r,i,tot);
	for(register int i = r+1;i <= n;i ++)
		for(register int j = 1;j <= m;j ++)
			if(!via[i][j])
				Dfs(i,j,tot);
	for(register int i = 1;i <= 9;i ++)
			via[r+mr[i]][l+ml[i]] --;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ans = 0;
		memset(via,0,sizeof(via));
		cin >> n >> m;
		for(register int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
				cin >> num[i][j];	
		for(register int i = 1;i <= n;i ++)
			for(register int j = 1;j <= m;j ++)
				Dfs(i,j,0);
		printf("%d\n",ans);
	}
	return 0;
}
