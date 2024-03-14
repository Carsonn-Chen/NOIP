#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int
using namespace std;

struct node {
	int x,y;
	int id;
};

const int maxn=100;
int s,t,a,b;
int T[105];
double dis[405];
node point[405];

double Dis(int x1, int y1, int x2, int y2) {
	return sqrt((x1-y1)*(x1-y1) + (x2-y2)*(x2-y2));
}

void calc(int x1, int y1, int x2, int y2, int x3, int y3, int i) {
	int ab = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	int ac = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
	int bc = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
	int x4,y4;
	if (ab+ac == bc)
		x4 = x2+x3-x1,y4 = y2+y3-y1;
	if (ab+bc == ac)
		x4 = x1+x3-x2,y4 = y1+y3-y2;
	if (ac+bc == ab)
		x4 = x1+x2-x3,y4 = y1+y2-y3;
	point[i+3].x = x4;
	point[i+3].y = y4;
}

void spfa() {
	bool vis[405];
	queue <int> q;
	for(ri i = 1;i <= 4*s;i ++) 
		dis[i]=99999999.99999;
	for(int i = a*4-3;i <= a*4;i ++){
		dis[i] = 0;
		q.push(i);
		vis[i] = 1;
	}
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int i = 1;i <= 4*s;i ++) {
			if(i == x) 
				continue;
			double cost = Dis(point[x].x,point[i].x,point[x].y,point[i].y);
			if (point[i].id == point[x].id) 
				cost *= T[point[i].id];
			else 
				cost *= t;
			if (dis[x] + cost < dis[i]) {
				dis[i] = dis[x] + cost;
				if (!vis[i]){
					vis[i] = 1;
					q.push(i);
				}
			}
		}
		vis[x] = 0;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	while (n--) {
		memset(point,0,sizeof(point));
		scanf("%d%d%d%d",&s,&t,&a,&b);
		for(ri i = 1;i <= 4*s;i += 4) {
			scanf("%d%d%d%d%d%d%d",&point[i].x,&point[i].y,&point[i+1].x,&point[i+1].y,&point[i+2].x,&point[i+2].y,&T[i/4+1]);
			point[i].id = point[i+1].id = point[i+2].id = point[i+3].id = i/4+1;
			calc(point[i].x,point[i].y,point[i+1].x,point[i+1].y,point[i+2].x,point[i+2].y,i);
		}
		spfa();
		double ans = dis[b*4];
		for(ri i = b*4-3;i < b*4;i ++)
			if (dis[i] < ans) 
				ans = dis[i];
		printf("%.1lf",ans);
	}
}
