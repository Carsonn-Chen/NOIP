#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ri register int

using namespace std;

struct node{
	int next;
	int to;
}edge[200005];
int head[20005];
int cnt = 0;
bool used[20005];
int col[20005];
int sum[2];

void add(int a,int b){
    edge[++cnt].to = b;
    edge[cnt].next = head[a];
    head[a] = cnt;
}

bool Dfs(int k,int color){
	if(used[k]){
		if(col[k] != color)
			return false;
		return true;
	}
	used[k] = 1;
	col[k] = color;
	sum[color] += 1;
	for(ri i = head[k];i != 0;i = edge[i].next)
		if(!Dfs(edge[i].to,1-color))
			return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int a,b;
	for(ri i = 1;i <= m;i ++){
		cin >> a >> b;
		add(a,b);
		add(b,a);
	}
	long long ans = 0;
	for(ri i = 1;i <= n;i ++){
        if(used[i])
			continue;
        sum[0] = sum[1] = 0;
        if(!Dfs(i,0)){
            printf("Impossible");
            return 0;
        }
        ans += min(sum[0],sum[1]);
    }
    cout << ans << endl;
	return 0;
}
