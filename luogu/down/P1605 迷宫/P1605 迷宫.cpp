#include <bits/stdc++.h>

using namespace std;

int maze[6][6];
int sx,sy,fx,fy;
int ans = 0;
int n,m,t;

void DFS(int x,int y){
	if(x == fx && y == fy){
		ans ++;
		return;
	}
	maze[x][y] = 0;
	if(x+1 <= m && maze[x+1][y])
		DFS(x+1,y);
	if(x-1 >= 1 && maze[x-1][y])
		DFS(x-1,y);
	if(y+1 <= n && maze[x][y+1])
		DFS(x,y+1);
	if(y-1 >= 1 && maze[x][y-1])	
		DFS(x,y-1);
	maze[x][y] = 1;
}

int main(){
	cin >> n >> m >> t;
	memset(maze,1,sizeof(maze));
	cin >> sx >> sy >> fx >> fy;
	int zx,zy;
	for(int i = 1;i <= t;i ++){
		cin >> zx >> zy;
		maze[zx][zy] = 0;
	}
	DFS(sx,sy);
	cout << ans;
}
