#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int x,y;
}zb[55];

int n;
int fa[55];

int find(int x){
	if(x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

bool check(int x){
	for(int i = 1;i <= n;i ++)
		fa[i] = i;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n ;j ++){
			if(i == j || find(i) == find(j))
				continue;
			if((abs(zb[i].x-zb[j].x) + abs(zb[i].y-zb[j].y)) <= (2*x)){
				fa[find(j)] = find(i);
			}
		}
	for(int i = 2;i <= n;i ++)
		if(fa[i] != fa[1])
			return false;
	return true;
}

int main(){
	scanf("%d",&n);
	int l = 0,r = -1e8;
	for(int i = 1;i <= n;i ++){
		scanf("%d%d",&zb[i].x,&zb[i].y);
		r = max(max(zb[i].x,zb[i].y),r);
	}
	r = r*1.4;
	int ans;
	while(l <= r){
		int mid = (r+l) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}
		else
			l = mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
