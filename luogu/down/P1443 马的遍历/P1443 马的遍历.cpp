#include <bits/stdc++.h>

using namespace std;

int m[405][405];
struct node{
	int r;
	int l;
	int step;
	node(int r,int l,int step):r(r),l(l),step(step){}
};
queue<node>q;
int n,mk;
int rr[] = {-1,1,2,2,1,-1,-2,-2};
int ll[] = {2,2,1,-1,-2,-2,-1,1};

int main(){
	int sx,sy;
	cin >> n >> mk >> sx >> sy;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= mk;j ++)
			m[i][j] = -1;
	q.push(node(sx,sy,0));
	while(!q.empty()){
		node e = q.front();
		q.pop();	
		if(m[e.r][e.l] != -1)
			continue;
		m[e.r][e.l] = e.step;
		for(int i = 0;i < 8;i ++)
			if((e.r+rr[i])>=1 && (e.r+rr[i])<=n && (e.l+ll[i])>=1 && (e.l+ll[i])<=mk)
				q.push(node((e.r+rr[i]),(e.l+ll[i]),(e.step+1)));	
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= mk;j ++)
			printf("%-5d",m[i][j]);
		printf("\n");
	}
	return 0;
}
