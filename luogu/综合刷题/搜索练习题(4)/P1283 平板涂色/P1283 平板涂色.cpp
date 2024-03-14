#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n,num,ans = INT_MAX;
int map[105][105];

struct sq {
	int x1,y1;
	int x2,y2;
	int col;
	bool vis;
} a[21];

void rs(int x) {									//È¾É« 
	for(ri j = a[x].x1+1;j <= a[x].x2;j ++)
		for(ri k = a[x].y1+1;k <= a[x].y2;k ++)
			map[j][k] = 0;
}

void ts(int x) {									//ÍÊÉ« 
	for(ri j = a[x].x1+1;j <= a[x].x2;j ++)
		for(ri k = a[x].y1+1;k <= a[x].y2;k ++)
			map[j][k] = a[x].col;
}

int pd(int x) {
	for(ri i = a[x].y1+1;i <= a[x].y2;i ++)
		if(map[a[x].x1][i]!=0) return 0;
	return 1;
}
void dfs(int now,int sum,int cnt) {
	if(sum > ans) return;
	if(cnt == n) {
		ans = sum;
		return;
	}
	for(ri i = 1;i <= n;i ++) {
		if(!a[i].vis&&pd(i)) {
			if(a[i].col == a[now].col&&pd(i)) {
				a[i].vis = 1;
				rs(i);
				dfs(i,sum,cnt+1);
				a[i].vis = 0;
				ts(i);
			}
			if(a[i].col != a[now].col&&pd(i)) {
				a[i].vis = 1;
				rs(i);
				dfs(i,sum+1,cnt+1);
				a[i].vis = 0;
				ts(i);
			}

		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(ri i = 1; i <= n; i ++) {
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].col;
		a[i].vis=0;
		for(ri j = a[i].x1+1;j <= a[i].x2;j ++)
			for(int k = a[i].y1+1;k <= a[i].y2;k ++)
				map[j][k] = a[i].col;
	}
	for(ri i = 1;i <= n;i ++) {
		if(!a[i].x1 && !a[i].vis) {
			a[i].vis = 1;
			rs(i);
			dfs(i,1,1);
			a[i].vis = 0;
			ts(i);
		}
	}
	cout << ans << endl;
}
