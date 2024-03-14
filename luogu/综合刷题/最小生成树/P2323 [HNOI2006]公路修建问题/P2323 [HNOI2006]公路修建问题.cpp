#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

struct node{
	int a,b;
	int c1,c2;
	int id;
}rd[20005];

struct node2{
    int t,p;
}ans[10005];

int n,k,m;
int fa[10005];

int find(int x){
	if(x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

bool cmp1(node x,node y){
	return x.c1 < y.c1;
}

bool cmp2(node x,node y){
	return x.c2 < y.c2;
}

bool cmp3(node2 x,node2 y){
	return x.t < y.t;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> m;
	m --;
	int cnt = 0;
	int Max = 0;
	for(ri i = 1;i <= n;i ++)
		fa[i] = i;
	for(ri i = 1;i <= m;i ++)
		cin >> rd[i].a >> rd[i].b >> rd[i].c1 >> rd[i].c2,rd[i].id = i;
	sort(rd+1,rd+1+m,cmp1);
	for(ri i = 1;cnt < k;i ++){
		int r1 = find(rd[i].a);
		int r2 = find(rd[i].b);
		if(r1 != r2){
			Max = max(Max,rd[i].c1);
			ans[++cnt].t = rd[i].id;
			ans[cnt].p = 1;
			fa[r1] = r2;
		}
	}
	sort(rd+1,rd+1+m,cmp2);
	for(ri i = 1;cnt < n-1;i ++){
		int r1 = find(rd[i].a);
		int r2 = find(rd[i].b);
		if(r1 != r2){
			Max = max(Max,rd[i].c2);
			ans[++cnt].t = rd[i].id;
			ans[cnt].p = 2;
			fa[r1] = r2;
		}
	}
	cout << Max << endl;
	sort(ans+1,ans+n,cmp3);
	for(ri i = 1;i < n;i ++)
			cout << ans[i].t << " " << ans[i].p << '\n';
	return 0;
}
