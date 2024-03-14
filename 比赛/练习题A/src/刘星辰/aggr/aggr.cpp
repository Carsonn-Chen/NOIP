#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#define pi acos(-1,0)
#define maxn 100005

using namespace std;

int n,m;
int p[maxn];
int q[maxn];
int ans = -999999;

bool cmp(int a,int b){
	return a > b;
}

void search(int x,int now,int pre){
	if(x == m+1){
		ans = max(ans,*min_element(q+2,q+m));
		return;
	}
	if(x >= 2)
		q[x] = p[now] - p[pre];
	for(int i = now+1;i <= n;i ++)
		search(x+1,i,now);
}

int main(){
	freopen("aggr.in","r",stdin);
	freopen("aggr.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&p[i]);
	sort(p+1,p+1+n);
	search(1,1,1);
	printf("%d\n",ans);
	return 0;
}
