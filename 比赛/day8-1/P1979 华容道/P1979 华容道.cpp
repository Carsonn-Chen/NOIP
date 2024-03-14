#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n,m,qq;
int e[20010][3],p[4010],ans;
int q[1010][2],dis[35][35],sq[4010],sdis[4010];
int vis[4010],map[35][35],dir[4][2] = {-1,0,1,0,0,-1,0,1};

struct node{
	int to,next,w;
}edge[20005];
int head[4005],cnt;

void add(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

void bfs(int si,int sj,int bi,int bj,int id) {
	memset(dis,0,sizeof(dis));
	int h = 1,t = 2;
	q[1][0] = si;
	q[1][1] = sj;
	dis[si][sj] = 1;
	while(h != t) {
		int i = q[h][0];
		int j = q[h++][1];
		for(ri k = 0;k < 4;k ++) {
			int ii = i+dir[k][0];
			int jj = j+dir[k][1];
			if(!map[ii][jj] || (ii==bi&&jj==bj) || dis[ii][jj])
				continue;
			dis[ii][jj] = dis[i][j]+1;
			q[t][0] = ii;
			q[t++][1] = jj;
		}
	}
	if(id == 4) 
		return;
	for(ri k = 0;k < 4;k ++) {
		int i = bi+dir[k][0];
		int j = bj+dir[k][1];
		if((i == si && j == sj) || !dis[i][j])
			continue;
		add(bi*30*4+bj*4+id,bi*30*4+bj*4+k,dis[i][j]-1);
	}
	add(bi*30*4+bj*4+id,si*30*4+sj*4+(id^1),1);
}

void spfa(int si,int sj) {
	memset(sdis,60,sizeof(sdis));
	int h = 1,t = 1;
	for(ri i = 0;i < 4;i ++) {
		if(!dis[si+dir[i][0]][sj+dir[i][1]])
			continue;
		int u = si*30*4+sj*4+i;
		sq[t++] = u;
		sdis[u] = dis[si+dir[i][0]][sj+dir[i][1]]-1;
		vis[u] = 1;
	}
	while(h != t) {
		int u = sq[h++];
		for(ri i = head[u];i;i = edge[i].next) {
			int v = edge[i].to;
			int w = edge[i].w;
			if(sdis[v] <= sdis[u]+w)
				continue;
			sdis[v] = sdis[u]+w;
			if(vis[v])
				continue;
			vis[v] = 1;
			sq[t++] = v;
			if(t > 4000)
				t = 1;
		}
		vis[u] = 0;
		if(h > 4000)
			h = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> qq;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= m;j ++)
			cin >> map[i][j];
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= m;j ++){
			if(!map[i][j])
				continue;
			if(map[i-1][j])
				bfs(i-1,j,i,j,0);
			if(map[i+1][j])
				bfs(i+1,j,i,j,1);
			if(map[i][j-1])
				bfs(i,j-1,i,j,2);
			if(map[i][j+1])
				bfs(i,j+1,i,j,3);
		}
	int bi,bj,si,sj,fi,fj;
	while(qq--) {
		cin >> bi >> bj >> si >> sj >> fi >> fj;
		if(si == fi && sj == fj) {
			cout << "0" << endl;
			continue;
		}
		bfs(bi,bj,si,sj,4);
		spfa(si,sj);
		ans = 1e9;
		for(ri i = 0;i < 4;i ++)
			ans = min(ans , sdis[fi*30*4+fj*4+i]);
		if(ans == 1e9)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}

