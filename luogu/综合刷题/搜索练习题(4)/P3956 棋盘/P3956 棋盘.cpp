#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <climits>
#define ri register int

using namespace std;

int m,n;
int M[105][105];
int f[105][105];
int ans = INT_MAX;
int dx[5] = {0,-1,0,0,1};
int dy[5] = {0,0,-1,1,0};

void Dfs(int x,int y,int cnt,bool used){
	if(f[x][y] <= cnt)
		return;
	if(x == m && y == m){
		ans = min(ans,cnt);
		return;
	}
	f[x][y] = cnt;
	for(ri i = 1;i <= 4;i ++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx <= m && xx >= 1 && yy <= m && yy >= 1){
			if(M[xx][yy]){
				if(M[xx][yy] == M[x][y])
					Dfs(xx,yy,cnt,0);
				else
					Dfs(xx,yy,cnt+1,0);
			}
			else if(!used){
				M[xx][yy] = M[x][y];
				Dfs(xx,yy,cnt+2,1);
				M[xx][yy] = 0;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	memset(f,0x3f,sizeof(f));
	cin >> m >> n;
	int x,y,c;
	for(ri i = 1;i <= n;i ++){
		cin >> x >> y >> c;
		M[x][y] = c+1;
	}
	Dfs(1,1,0,0);
	cout << (ans == INT_MAX?-1:ans) << endl;
	return 0;
}
