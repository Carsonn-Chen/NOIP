#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

#define maxn 10005

using namespace std;

struct node1 {
	int x,y,dis;
	bool operator< (const node1 &a) const{
		return dis > a.dis;
	} 
}edge1[50005];

struct node2 {
	int to,next,w;
}edge2[100005];
int cnt,head[maxn];

int fa[maxn][25];
int depth[maxn],f[maxn],w[maxn][25];
int n,m;
bool vis[maxn];

void add(int u, int to, int w) {
	edge2[++cnt].next = head[u];
	edge2[cnt].to = to;
	edge2[cnt].w = w;
	head[u] = cnt;
}

int find(int x){
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

void calc() {
	sort(edge1+1, edge1+m+1);
	for(ri i = 1;i <= n;i ++)
		f[i] = i;
	for(ri i = 1;i <= m;i ++)
		if(find(edge1[i].x) != find(edge1[i].y)) {
			f[find(edge1[i].x) ]= find(edge1[i].y);
			add(edge1[i].x, edge1[i].y, edge1[i].dis);
			add(edge1[i].y, edge1[i].x, edge1[i].dis);
		}
	return ;
}

void dfs(int x) {
	vis[x] = 1;
	for(ri i = head[x];i;i = edge2[i].next) {
		int to = edge2[i].to;
		if(vis[to])
			continue;
		depth[to] = depth[x]+1;
		fa[to][0] = x; 
		w[to][0] = edge2[i].w; 
		dfs(to);
	}
	return ;
}

int lca(int x, int y) {
	if(find(x)!=find(y)) return -1;
	int ans=INT_MAX;
	if(depth[x]>depth[y]) swap(x,y);
	for(ri i=20; i>=0; i--)
		if(depth[fa[y][i]]>=depth[x]) {
			ans=min(ans, w[y][i]);
			y=fa[y][i]; 
		}
	if(x==y) return ans;
	for(ri i=20; i>=0; i--)
		if(fa[x][i]!=fa[y][i]) {
			ans=min(ans, min(w[x][i], w[y][i])); 
			x=fa[x][i];
			y=fa[y][i]; 
		}
	ans=min(ans, min(w[x][0], w[y][0]));
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int x,y,z;
	for(ri i = 1;i <= m;i ++) {
		cin >> x >> y >> z;
		edge1[i].x = x;
		edge1[i].y = y;
		edge1[i].dis = z;
	}
	calc();
	for(ri i = 1;i <= n;i ++)
		if(!vis[i]) {
			depth[i] = 1;
			dfs(i);
			fa[i][0] = i;
			w[i][0] = INT_MAX;
		}
	for(ri i = 1;i <= 20;i ++)
		for(ri j = 1;j <= n;j ++) {
			fa[j][i] = fa[fa[j][i-1]][i-1];
			w[j][i] = min(w[j][i-1] , w[fa[j][i-1]][i-1]);
		}
	int q;
	cin >> q;
	for(ri i = 1;i <= q;i ++) {
		cin >> x >> y;
		cout << lca(x,y) << endl;
	}
	return 0;
}
