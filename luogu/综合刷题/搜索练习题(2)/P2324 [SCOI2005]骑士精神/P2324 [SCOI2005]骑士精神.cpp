#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int num[8][8];
const int tar[6][6] = {
	{},
	{0,1,1,1,1,1},
	{0,0,1,1,1,1},
	{0,0,0,2,1,1},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0}
};
int Min,Max;
int dx[8]={-2,-2,-1,1,-1,1,2,2};
int dy[8]={-1,1,2, 2,-2,-2,-1,1};

bool Dfs(int cnt,int x,int y,int sum,int last) {	//当前已操作数；剩余操作数；搜索的坐标；上次搜索的方向
	if(cnt + sum > Max)
		return 0;
	if(sum == 0)
		return 1;
	for(ri i = 0; i <= 7; i ++) {				//8个方向移动
		if(i != (7-last)) {					//上次移动过来的不能移回去
			int xx = x + dx[i];
			int yy = y + dy[i];
			int p = sum;
			if(xx <= 5 && xx >= 1 && yy <= 5 && yy >= 1) {
				if(num[xx][yy] == tar[xx][yy] && num[xx][yy] != tar[x][y])
					p ++;
                if(num[xx][yy] != tar[xx][yy] && num[xx][yy] == tar[x][y])
					p --;
                if(tar[xx][yy] == 2)
					p --;
                if(tar[x][y] == 2)
					p ++;
				swap(num[xx][yy],num[x][y]);
				bool flag = Dfs(cnt+1,xx,yy,p,i);
				if(flag)
					return 1;
				swap(num[xx][yy],num[x][y]);
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --) {
		int x,y;
		char e;
		Min = 0;
		for(ri i = 1; i <= 5; i ++)
			for(ri j = 1; j <= 5; j ++) {
				cin >> e;
				if(e == '*') {
					num[i][j] = 2;
					x = i;
					y = j;
				} else
					num[i][j] = (int)(e - '0');
				if(num[i][j] != tar[i][j])
					Min ++;
			}
		bool tag = 0;
		for(ri i = Min; i <= 16; i ++) {
			Max = i;
			if(Dfs(0,x,y,Min,-1)){
				printf("%d\n",i-1);
				tag = 1;
				break;
			}
		}
		if(!tag)
			printf("-1\n");
	}
	return 0;
}
