#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
#include <iostream>
#define ri register int

using namespace std;

const int N = 105;
int a[15][15];
bool used[111];
bool vis[15];
int flag;

void print(int n) {
	for(ri i = 1;i <= n;i ++) {
		for(ri j = 1;j <= n;j ++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

void DFS(int x,int y,int n) {
	if(x == n+1 && y == 1) {
		print(n);
		exit(0);
	}
	if(x == 1 || y == 1) {
		for(ri k = 2;k <= n*n;k ++) {
			if(!vis[k]){ //准备填k
				if(a[x-1][y] && used[k+a[x-1][y]]) 
					continue;
				if(a[x][y-1] && used[k+a[x][y-1]])
					continue;
				a[x][y] = k;
				vis[k] = 1;
				if(y >= n)
					DFS(x+1,1,n);
				else 
					DFS(x,y+1,n);
				a[x][y] = 0;
				vis[k] = 0;
			}
		}
	} else {
		for(int k=n*n; k>=2; k--) {
			if(!vis[k]) { //准备填k
				if(a[x-1][y]&&used[k+a[x-1][y]]) continue;
				if(a[x][y-1]&&used[k+a[x][y-1]]) continue;
				a[x][y]=k;
				vis[k]=1;
				if(y>=n) DFS(x+1,1,n);
				else DFS(x,y+1,n);
				a[x][y]=0;
				vis[k]=0;
			}
		}
	}
}
int main() {
	int m = sqrt(N+0.5);
	used[1] = 1;
	for(ri i = 2;i <= m;i ++)
		for(ri j = i*i;j <= N;j += i)
			used[j]=1;
	int n;
	scanf("%d",&n);
	a[1][1] = 1;
	vis[1] = 1; //数字1被标记
	DFS(1,2,n);
	if(flag == 0 || n == 1) {
		printf("NO\n");
		return 0;
	}
	return 0;
}
