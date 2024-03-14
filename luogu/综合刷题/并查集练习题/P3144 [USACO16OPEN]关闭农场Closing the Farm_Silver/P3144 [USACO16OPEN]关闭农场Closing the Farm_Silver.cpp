#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#define ri register int

using namespace std;

int n,m,k;
bool M[3005][3005];
int fa[3005];
bool tag[3005];
int order[3005];

int find(int k){
    int x,y;
    x = k;
    while(x != fa[x])
        x = fa[x];
    while(k != x){
        y = fa[k];
        fa[k] = x;
        k = y;
    }
    return x; 
}

void Union(int x,int y){
    int r1 = find(x);
    int r2 = find(y);
    fa[r2] = r1;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int a,b;
	k = n;
	for(ri i = 1;i <= m;i ++){
		cin >> a >> b;
		M[a][b] = M[b][a] = 1;
	}
	for(ri i = 1;i <= n;i ++){
		cin >> order[i];
		fa[i] = i;
	}
	for(ri i = n;i >= 1;i --){
		int x = order[i];
		for(ri j = i+1;j <= n;j ++)
			if(M[x][order[j]] && find(x) != find(order[j])){
				Union(x,order[j]);
				k --;
			}
		if(k == i)
			tag[i] = 1;
	}
	for(ri i = 1;i <= n;i ++){
		if(tag[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
