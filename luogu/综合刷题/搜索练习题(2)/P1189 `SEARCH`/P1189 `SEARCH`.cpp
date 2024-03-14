#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#define ri register int

using namespace std;

int R,C,N;
char Map[55][55];
int Turn[1005];
int dx[8] = {0,-1,1,0,0};
int dy[8] = {0,0,0,-1,1};
bool ans[55][55];
bool vis[55][55];
int sx,sy;

int main(){
	ios::sync_with_stdio(false);
	cin >> R >> C;
	for(ri i = 1;i <= R;i ++)
		for(ri j = 1;j <= C;j ++){
			cin >> Map[i][j];
			if(Map[i][j] == '*'){
				ans[i][j] = 1;
				sx = i;
				sy = j;
			}
		}
	cin >> N;
	for(ri i = 1;i <= N;i ++){
		string a;
		cin >> a;
		if(a == "NORTH")
			Turn[i] = 1;
		if(a == "SOUTH")
			Turn[i] = 2;
		if(a == "WEST")
			Turn[i] = 3;
		if(a == "EAST")
			Turn[i] = 4;
	}
	for(ri i = 1;i <= N;i ++){
		for(ri j = 1;j <= R;j ++){
			for(ri k = 1;k <= C;k ++){
				if(ans[j][k] == 1 && !vis[j][k]){
					ans[j][k] = 0;
					int xx = j+dx[Turn[i]],yy = k+dy[Turn[i]];
					while((xx <= R && xx >= 1) && (yy <= C && yy >= 1)){
						if(Map[xx][yy] == 'X')
							break;
						ans[xx][yy] = 1;
						vis[xx][yy] = 1;
						xx += dx[Turn[i]];
						yy += dy[Turn[i]];
					}
				}
			}
		}
		memset(vis,0,sizeof(vis));
	}
	for(ri i = 1;i <= R;i ++){
		for(ri j = 1;j <= C;j ++){
			if(ans[i][j] == 1)
				printf("*");
			else if(i == sx && j == sy)
					printf(".");
			else
				printf("%c",Map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
