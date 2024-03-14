#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int read(){
	int summ = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e))
		summ = summ*10 + e - '0',e = getchar();
	return summ;
}

struct node {
	int to,next,w;
}edge[100005];
int head[1005],cnt;

void add(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n,m;

int main(){
	n = read(),m = read();
	for(ri i = 1;i <= m;i ++){
		int u,v,w;
		u = read(),v = read(),w  = read();
		add(u,v,w);
		add(v,u,w);
	}
	
	return 0;
}

