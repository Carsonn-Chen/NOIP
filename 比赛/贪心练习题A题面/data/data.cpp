#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int x;
	int r;
}inf[15005];

bool cmp(node a,node b){
	return a.r > b.r;
}

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T,n,l,w;
	scanf("%d",&T);
	while(T --){
		scanf("%d%d%d",&n,&l,&w);
		for(int i = 1;i <= n;i ++)
			scanf("%d%d",&inf[i].x,&inf[i].r);
		sort(inf+1,inf+1+n,cmp);
		int ans = 0,now = 0;
		for(int i = 1;i <= n;i ++){
			if(inf[i].x - inf[i].r <= now);
		}
		printf("%d\n",-1);
	}
	return 0;
}
