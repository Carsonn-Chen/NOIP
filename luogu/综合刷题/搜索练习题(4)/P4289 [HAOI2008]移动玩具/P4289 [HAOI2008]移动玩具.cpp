#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

struct zb {
	int x,y;
}c[26]; 

int a[5][5];
int b[5][5];
int w[5][5][5][5];//前两个下标表示未匹配点坐标，后两个下标为待匹配点坐标，保存值为未匹配点到待匹配点的最短距离
bool used[5][5];
int sum = 0;
int Min = INT_MAX;

void search(int pos,int v){
	if(pos > sum) {
		Min = min(Min,v);
		return ;
	}
	for(ri i = 1; i <= 4; i ++)
		for(ri j = 1; j <= 4; j ++)
			if(w[c[pos].x][c[pos].y][i][j]!=0&&!used[i][j]) {
				used[i][j] = 1;
				search(pos+1,v+w[c[pos].x][c[pos].y][i][j]);
				used[i][j] = 0;
			}
}

int main() {
	ios::sync_with_stdio(false);
	char e;
	for(ri i = 1;i <= 4; i ++)
		for(ri j = 1; j <= 4; j ++) {
			cin >> e;
			a[i][j] = e-'0';
		}
	for(ri i = 1; i <= 4; i ++)
		for(ri j = 1; j <= 4; j ++) {
			cin >> e;
			b[i][j] = e-'0';
			if(a[i][j] == b[i][j])
				a[i][j] = b[i][j] = 0;
		}
	for(ri i = 1; i <= 4; i ++)
		for(ri j = 1; j <= 4; j ++)
			if(a[i][j] == 1) {
				c[++sum].x = i;
				c[sum].y = j;
				for(ri k = 1;k <= 4;k ++)
					for(ri l = 1; l <= 4; l++)
						if(b[k][l] == 1) {
							w[i][j][k][l] = abs(i-k) + abs(j-l);
						}
			}
	search(1,0);
	cout << Min << endl;
	return 0;
}
