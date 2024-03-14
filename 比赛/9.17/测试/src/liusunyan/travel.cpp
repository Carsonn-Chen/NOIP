#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
inline int read() {
	char ch = getchar();int k = 1,sum = 0;
	while(ch < '0' || ch > '9') {if(ch == '-')k = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9') {sum = sum * 10 + ch - '0';ch = getchar();}
	return sum * k;
}
void print(int x) {
	if(x > 9) print(x/10);
	putchar(x%10+'0');
}
int N,M;
const int maxn = 52505;
struct Edge {
	int u,v;
	long long w;
	Edge(int u = 0,int v = 0,long long w = 0): u(u),v(v),w(w){}
};
long long d[maxn];
vector<Edge> edges;
vector<int> G[maxn];
bool in[maxn];
int vis[maxn];
void SPFA(int s) {
	in[s] = 1;
	vis[s] ++;
	queue<int> q;
	q.push(s);
	for(int i = 1;i <= N;i ++) d[i] = 0x3f3f3f3f;
	d[s] = 0;
	while(!q.empty()) {
		int t = q.front();q.pop();in[t] = 0;
		for(int i = 0;i < G[t].size();i ++) {
			Edge& e = edges[G[t][i]];
			if(d[t] + e.w < d[e.v] && d[t] < 0x3f3f3f3f){ d[e.v] = d[t] + e.w;
				if(!in[e.v] && vis[e.v] <= N){q.push(e.v);in[e.v] = 1;vis[e.v] ++;}
			}
		}
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	N = read(),M = read();
	for(int i = 1;i <= N;i ++) {
		int t = read();
		edges.push_back(Edge(i,i%N+1,t));
		G[i].push_back(edges.size()-1);
		edges.push_back(Edge(i%N+1,i,t));
		G[i%N+1].push_back(edges.size()-1);
	}
	for(int i = 1;i <= M;i ++) {
		int u = read(),v = read(),w = read();if(u != v) {
			edges.push_back(Edge(u,v,(long long)w));
			G[u].push_back(edges.size()-1);
			edges.push_back(Edge(v,u,(long long)w));
			G[v].push_back(edges.size()-1);
		}
	}
	int Q = read();
	while(Q --) {
		int x = read(),y = read();
		SPFA(x);
		print(d[y]);putchar('\n');
	}
	return 0;
}
