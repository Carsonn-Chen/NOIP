#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define maxn 155

using namespace std;

struct node {
	int x;
	int y;
}point[maxn];

double cal(int i,int j) {
	return sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));
}

int n;
double dis1[maxn][maxn],dis2[maxn];

int main() {
	int temp;
	double l1,l2 = INT_MAX;
	scanf("%d",&n);
	for(ri i = 1;i <= n;i ++)
		scanf("%d%d",&point[i].x,&point[i].y);
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++) {
			scanf("%1d",&temp);
			if(temp)
				dis1[i][j] = cal(i,j);
			else if(i!=j)
				dis1[i][j] = INT_MAX;
		}
	for(ri k = 1;k <= n;k ++)
		for(ri i = 1;i <= n;i ++)
			for(ri j = 1;j <= n;j ++)
				if(dis1[i][k] + dis1[k][j] < dis1[i][j])
					dis1[i][j] = dis1[i][k] + dis1[k][j];
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++) {
			if(dis1[i][j] != INT_MAX)
				dis2[i] = max(dis1[i][j],dis2[i]);
			l1=max(l1,dis2[i]);
		}
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++)
			if(dis1[i][j] == INT_MAX)
				l2 = min(dis2[i]+cal(i,j)+dis2[j],l2);
	printf("%.6f",max(l1,l2));
	return 0;
}
