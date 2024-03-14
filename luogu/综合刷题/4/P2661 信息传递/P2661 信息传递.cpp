#include <bits/stdc++.h>

using namespace std;

int fa[200005],dis[200005];
int Min;

int Fa(int x){
	if(fa[x] != x){
		int last = fa[x];
		fa[x] = Fa(fa[x]);
		dis[x] += dis[last];
	}
	return fa[x];
}

void check(int a,int b){
	int x = Fa(a),y = Fa(b);
	if(x == y) 
		Min = min(Min,dis[a]+dis[b]+1);
	else{
		fa[x] = y;
		dis[a]=dis[b]+1;
	}
}

int main(){
	int n,t;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		fa[i] = i;
	Min = 0x7fffff;
	for(int i = 1;i <= n;i ++){
		scanf("%d",&t);
		check(i,t);
	}
	printf("%d",Min);
	return 0;
}
