#include <bits/stdc++.h>

using namespace std;

struct node{
	int w;
	int d;
	int tag;
}pop[20005];

int e[15];

bool cmp1(node a,node b){
	if(a.w == b.w)
		return a.tag < b.tag;
	return a.w > b.w;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= 10;i ++)
		scanf("%d",&e[i]);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&pop[i].w);
		pop[i].d = pop[i].tag = i;
	}
	sort(pop+1,pop+1+n,cmp1);
	for(int i = 1;i <= n;i ++){
		pop[i].d = (i-1)%10+1;
		pop[i].w += e[pop[i].d];
	}
	sort(pop+1,pop+1+n,cmp1);
	for(int i = 1;i <= k;i ++)
		printf("%d ",pop[i].tag);
	return 0;
}
