#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
	int to;
	int v;
	node(int to,int v):to(to),v(v){}
};

vector<node>m[20005];
int power;
long long ans;
bool via[20005];

void DFS(int x,int now){
	if(via[x])
		return;
	via[x] = 1;
	for(int i = 0;i < (int)m[x].size();i ++)
		if(m[x][i].v > now){
			now = power;
			ans ++;
			break;
		}
	for(int i = 0;i < (int)m[x].size();i ++)
		DFS(m[x][i].to,now-m[x][i].v);
}

int main(){
	int n;
	int Max = -1e8;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		int k;
		scanf("%d",&k);
		int temp1,temp2;
		while(k --){
			scanf("%d%d",&temp1,&temp2);
			m[i].push_back(node(temp1,temp2));
			Max = max(Max,temp2);
		}
	}
	scanf("%d",&power);
	if(Max > power){
		printf("No solution");
		return 0;
	}
	DFS(1,power);
	printf("%lld\n",ans);
	return 0;
}
