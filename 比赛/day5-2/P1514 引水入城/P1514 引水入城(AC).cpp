#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

int n,m;
int h[505][505];
bool vis[505][505];
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
int l[505][505],r[505][505];

void dfs(int x,int y){
	vis[x][y] = 1;
	for(ri i = 1;i <= 4;i ++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(h[xx][yy] >= h[x][y])
			continue;
		if(!vis[xx][yy])
			dfs(xx,yy);
		l[x][y] = min(l[x][y],l[xx][yy]);
        r[x][y] = max(r[x][y],r[xx][yy]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	memset(l,0x3f,sizeof(l));
	cin >> n >> m;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= m;j ++)
			cin >> h[i][j];
			
	for(ri i = 0;i <= m+1;i ++)						//ÖþÇ½ 
		h[0][i] = h[n+1][i] = INT_MAX;
	for(ri i = 0;i <= n+1;i ++)
		h[i][0] = h[i][m+1] = INT_MAX;
		
	for(ri i = 1;i <= m;i ++)
        l[n][i] = r[n][i] = i;
	for(ri i = 1;i <= m;i ++)
		if(!vis[1][i])
			dfs(1,i);
	int cnt = 0;
	for(ri i = 1;i <= m;i ++)
		if(!vis[n][i])
			cnt ++;
	if(cnt){
		cout << 0 << endl;
		cout << cnt << endl;
		return 0;
	}
	int left = 1;									//Ì°ÐÄÇø¼ä¸²¸Ç 
    while(left <= m){
        int maxr = 0;
        for(ri i = 1;i <= m;i ++)
            if (l[1][i] <= left)
                maxr = max(maxr,r[1][i]);
        cnt ++;
        //cout << maxr << endl;
        left = maxr + 1;
    }
    cout << 1 << endl;
	cout << cnt << endl;
	return 0;
}
