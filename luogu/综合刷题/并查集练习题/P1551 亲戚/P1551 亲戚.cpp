#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

int fa[5005];

int Fa(int x){
	if(x == fa[x])
		return x;
	return fa[x] = Fa(fa[x]);
}

void Union(int x,int y){
	int r1 = Fa(x);
	int r2 = Fa(y);
	fa[r2] = r1;
}

int main(){
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(ri i = 1;i <= n;i ++)
		fa[i] = i;
	int mi,mj;
	for(ri i = 1;i <= m;i ++){
		scanf("%d%d",&mi,&mj);
		Union(mi,mj);
	}
	for(ri i = 1;i <= p;i ++){
		scanf("%d%d",&mi,&mj);
		if(Fa(mi) == Fa(mj))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
