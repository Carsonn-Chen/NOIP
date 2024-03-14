#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int
#define maxn 1000005

using namespace std;

struct node{
	int next,to;
}edge[maxn*2];
int head[maxn],cnt;

void add(int u,int v){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int dfn[maxn],low[maxn];
int n,m;
bool vis[maxn];
int num,now,top;
int Stack[maxn];
//int color[maxn];
priority_queue<int,vector<int>,greater<int> >q;

void tarjan(int u){
	vis[u] = 1;
	dfn[u] = low[u] = (++now);
	Stack[++top] = u;
	for(ri i = head[u];i;i = edge[i].next){
		int v = edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]); 
		} 
		else if(vis[v])
			low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u]){
		vis[u] = 0;
		//color[u] = ++num;
		priority_queue<int,vector<int>,greater<int> >q2;
		while(Stack[top] != u){
			//color[Stack[top]] = num;
			q2.push(Stack[top]);
			vis[Stack[top--]] = 0;
		}
		top --;
		q2.push(u);
		if(q2.size() > q.size())
			q = q2;
		else if(q2.size() == q.size())
			if(q2.top() < q.top())
				q = q2;
	}
}

int main(){
	cin >> n >> m;
	for(ri i = 1;i <= m;i ++){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b);
		if(c == 2)
			add(b,a);
	}
	for(ri i = 1;i <= n;i ++)
		if(!dfn[i])
			tarjan(i);		
	cout << q.size() << endl;
	while(!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}
	return 0;
}
