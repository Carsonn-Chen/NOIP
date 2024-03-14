#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int
#define pi acos(-1.0)

using namespace std;

struct node{
	double x,y;
	double r;
}point[10];

int n;
double sx,sy,ex,ey;
bool vis[8];
double ans;

void Dfs(int a,int k,double tot){
	point[a].r = min(min(abs(point[a].x-sx),abs(point[a].x-ex)),min(abs(point[a].y-sy),abs(point[a].y-ey)));
	for(ri i = 1;i <= n;i ++)
		if(vis[i] && i != a){
			double d=sqrt((point[a].x-point[i].x)*(point[a].x-point[i].x)+(point[a].y-point[i].y)*(point[a].y-point[i].y));
			point[a].r=min(point[a].r,max(d-point[i].r,0.0));
		}
	tot = tot + pi * point[a].r * point[a].r;
	if(k == n){
		ans = max(ans,tot);
		return;
	}
	for(ri i = 1;i <= n;i ++){
		if(!vis[i]){
			vis[i] = 1;
			Dfs(i,k+1,tot);
			vis[i] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> sx >> sy >> ex >> ey;
	double ss = abs(sx-ex) * abs(sy-ey);
	for(ri i = 1;i <= n;i ++)
		cin >> point[i].x >> point[i].y;
	for(ri i = 1;i <= n;i ++){
		vis[i] = 1;
		Dfs(i,1,0);
		memset(vis,0,sizeof(vis));
	}
	printf("%0.0lf\n",(ss-ans));
	return 0;
}
