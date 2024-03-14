#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	double x,y;
}zb[20];
int n;
bool via[20];
double ans = 99999999,anst;

double calc(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void Dfs(int last,int k){
	if(anst > ans)
		return;
	if(k == n){
		ans = min(ans,anst);
		return;
	}
	for(register int i = 1;i <= n;i ++){
		if(!via[i]){
			anst += calc(zb[i],zb[last]);
			via[i] = 1;
			Dfs(i,k+1);
			via[i] = 0;
			anst -= calc(zb[i],zb[last]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(register int i = 1;i <= n;i ++)
		cin >> zb[i].x >> zb[i].y;
	zb[0].x = 0;
	zb[0].y = 0;
	Dfs(0,0);
	printf("%.2lf\n",ans);
	return 0;
}
