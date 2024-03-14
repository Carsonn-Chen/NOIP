#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

struct node{
	int to;
	int ep;
}m[205][205];

struct place{
	int r;
	int l;
}x,y,z;

int cost[205][205];

/*bool check(int a,int b,int c,int d){
	return (c-a)*(c-a)+(d-b)*(d-b) <= (m[a][b].to+m[c][d].to)*(m[a][b].to+m[c][d].to);
}*/
void bfs(place a){
	queue<node>q;
	q.push(num[a.r][a.l]);
	while(!q.empty()){
		node b = q.front();q,pop();
		
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i  =1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			scanf("%d",&m[i][j].to);
	for(int i  =1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			scanf("%d",&m[i][j].ep);
	scanf("%d%d%d%d%d%d",&x.r,&x.l,&y.r,&y.l,&z.r,&z.l);
	return 0;
}
