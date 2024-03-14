#include <bits/stdc++.h>

using namespace std;

struct pha{
	int begin;
	int end;
	int value;
}p[50005];

int fa[305];

bool cmp1(pha x,pha y){
	return x.value < y.value;
}

int Find(int x){
	while(fa[x] != x)
		x = fa[x];
	return x;
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= m;i ++)
		cin >> p[i].begin >> p[i].end >> p[i].value;
	for(int i = 1;i <= n;i ++)
		fa[i] = i;
	sort(p+1,p+1+m,cmp1);
	int cnt = 0,Max = -9999999;
	for(int i = 1;cnt < n-1;i ++){
		int f1 = Find(p[i].begin);
		int f2 = Find(p[i].end);
		if(f1 != f2){
			fa[f2] = f1;
			Max = max(Max,p[i].value);
			cnt ++;
		}
	}
	printf("%d %d",cnt,Max);
	return 0;
}
