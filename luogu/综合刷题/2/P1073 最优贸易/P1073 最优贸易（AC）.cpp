#include <bits/stdc++.h>
#define INF 0x7fffff

using namespace std;

vector<int>m[100005];
int price[100005];
int MIN[100005],f[1000005];

void dfs(int x,int minx,int pre) {
    int flag = 1; 
    minx = min(price[x],minx);
    if (MIN[x] > minx) 
		MIN[x] = minx,flag = 0;
    int maxx = max(f[pre],price[x]-minx);
    if (f[x] < maxx) 
		f[x] = maxx,flag = 0;
    if (flag) 
		return;
    for (int i = 0;i < (int)m[x].size();i ++) 
		dfs(m[x][i],minx,x);
}

int main(){
	int n,m2;
	scanf("%d%d",&n,&m2);
	for (int i = 1;i <= 100005;i ++) 
		MIN[i] = INF;
	for(int i = 1;i <= n;i ++)
		scanf("%d",&price[i]);
	int x,y,z;
	for(int i = 1;i <= m2;i ++){
		scanf("%d%d%d",&x,&y,&z);
		m[x].push_back(y);
		if(z == 2)
			m[y].push_back(x);
	}
	dfs(1,INF,0);
	printf("%d\n",f[n]);
	return 0;
} 
