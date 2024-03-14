#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

struct node{
	LL s;
	LL j;
}num[1005];

bool cmp(node a,node b){
	return a.j < b.j;
}

int main(){
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	int n;
	scanf("%d",&n);	
	for(int i = 1;i <= n;i ++)
		scanf("%lld%lld",&num[i].s,&num[i].j);
	sort(num+1,num+1+n,cmp);
	int ans = 0,now = 0;
	for(int i = 1;i <= n;i ++){
		if(now <= num[i].s){
			now = num[i].j;
			ans ++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
