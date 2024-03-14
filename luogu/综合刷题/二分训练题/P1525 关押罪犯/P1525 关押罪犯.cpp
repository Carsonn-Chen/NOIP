#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct node{
	int a,b;
	int v;
}re[100005];

int fa[20005];
int n,m;
int e[20005];

bool cmp(node x,node y){
	return x.v > y.v;
}

int find(int x){
	if(x == fa[x])
		return fa[x];
	return fa[x] = find(fa[x]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
		fa[i] = i;
	for(int i = 1;i <= m;i ++)
		scanf("%d%d%d",&re[i].a,&re[i].b,&re[i].v);
	sort(re+1,re+1+m,cmp);
	for(int i = 1;i <= m;i ++){
		if(find(re[i].a) == find(re[i].b)){
			printf("%d\n",re[i].v);
			return 0;
		}
		if(!e[re[i].a])
			e[re[i].a] = re[i].b;
		else
			fa[find(re[i].b)] = find(e[re[i].a]);
		if(!e[re[i].b])
			e[re[i].b] = re[i].a;
		else
			fa[find(re[i].a)] = find(e[re[i].b]);
	}
	printf("0\n");
	return 0;
}
