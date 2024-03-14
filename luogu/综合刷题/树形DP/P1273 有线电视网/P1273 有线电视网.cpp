#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>
#define ri register int

using namespace std;

struct node{
	int to;
	int next;
	int v;
}edge[10000005];
int head[3005];
int cnt = 0;
int n,m;
int val[3005];
int dp[3005][3005];							//dp[i][j]表示i节点，选j个用户，能得到的钱的最大值 

void Add(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	edge[cnt].v = w;
	head[u] = cnt;
}

int dfs(int u){
    if(u > n-m){
        dp[u][1] = val[u];
        return 1;
    } 
    int sum = 0,t;
    for(ri k = head[u];k != 0;k = edge[k].next){
        int v = edge[k].to;
        t = dfs(v); 
		sum += t;
        for(ri j = sum;j >= 1;j --)
            for(ri i = 1;i <= t;i ++)
                if(j-i >= 0) 
					dp[u][j] = max(dp[u][j],dp[u][j-i]+dp[v][i]-edge[k].v);
    }
    return sum;
}

int main(){
	fill(&dp[0][0],&dp[3004][3004],-999999999);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ri i = 1;i <= n-m;i ++){
		int k;
		cin >> k;
		int a,b;
		for(ri j = 1;j <= k;j ++){
			cin >> a >> b;
			Add(i,a,b);
		}
	}
	for(ri i = n-m+1;i <= n;i ++)
		cin >> val[i];
	for(ri i = 1;i <= n;i ++) 
		dp[i][0]=0;
    dfs(1);
    for(ri i = m;i >= 1;i --){
        if(dp[1][i] >= 0){
            cout << i << endl;
            break;
        }
    }
	return 0;
}
