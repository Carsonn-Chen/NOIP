#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#define ri register int

using namespace std;

vector<int>m[305],t[305];
bool vis[305];
bool iscut[305];
int child[305];
int ans = 1e9;
int dep;

void cut(int x){
	iscut[x] = 1;
	for(ri i = 0;i < (int)m[x].size();i ++)
		cut(m[x][i]);
}

void nocut(int x){
	iscut[x] = 0;
	for(ri i = 0;i < (int)m[x].size();i ++)
		nocut(m[x][i]);
}

void calc(int x,int now){
	dep = max(dep,now);
	for(ri i = 0;i < (int)m[x].size();i ++){
		t[now].push_back(m[x][i]);
		calc(m[x][i],now+1);
	}
}

int getc(int x){
	if(!vis[x]){
		vis[x] = 1;
		for(ri i = 0;i < (int)m[x].size();i ++)
			child[x] += getc(m[x][i]);
	}
	return child[x];
}

void dfs(int now,int sum){
	for(ri i = 0;i < (int)t[now].size();i ++){
		if(iscut[t[now][i]])
			continue;
		cut(t[now][i]);
		dfs(now+1,sum-child[t[now][i]]);
		nocut(t[now][i]);
	}
	ans = min(ans,sum);
}

int main(){
	ios::sync_with_stdio(false);
	int n,p;
	cin >> n >> p;
	int a,b;
	for(ri i = 1;i <= p;i ++){
		cin >> a >> b;
		if(b < a)
			swap(a,b);
		m[a].push_back(b);
	}
	for(ri i = 1;i <= n;i ++)
		child[i] = 1;
	t[1].push_back(1);
	calc(1,2);
	getc(1);
	dfs(2,n);
	if(ans == 1e9)
		ans = 1;
	cout << ans << endl;
}
