#include <bits/stdc++.h>

using namespace std;

int num[85][85];

struct node{
	int len;
	int sum[1005];
	node operator = (const node &a,node &b){
		b.len = a.len;
		for(int i = 1;i <= a.len;i ++)
			b.sum[i] = a.sum[i];
	}
}f[55];
node multi;

void multiply1(node &a,int b){
	for(int i = 1;i <= a.len;i ++)
		a.sum[i] *= b;
	for(int i = 1;i <= a.len;i ++){
		a.sum[i+1] += (a.sum[i]/10);
		a.sum[i] %= 10;
	}
	a.len ++;
	while(a.sum[a.len] > 9){
		a.sum[a.len+1] += (a.sum[a.len]/10);
		a.sum[a.len] %= 10;
		a.len ++;
	}
	if(a.sum[a.len] == 0)
		a.len --;
}

void multiplt2(node a,node &b){
	for(int i = 1;i <= a.len;i ++)
		mulsiply1(b,a.sum[i]);
}

void add(node a,node &b){
	int len1 = (a.len>b.len)?a.len:b.len;
	for(int i = 1;i <= len1;i ++)
		b.sum[i] += a.sum[i];
	b.len = len1;
	for(int i = 1;i <= b.len;i ++){
		b.sum[i+1] += (b.sum[i]/10);
		b.sum[i] %= 10;
	}
	b.len ++;
	while(b.sum[b.len] > 9){
		b.sum[b.len+1] += (b.sum[b.len]/10);
		b.sum[b.len] %= 10;
		b.len ++;
	}
	if(b.sum[b.len] == 0)
		b.len --;		
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			scanf("%d",&num[i][j]);
	multi.sum[1] = 1;
	f[0].sum[1] = 0;
	f[0].len = 0;
	for(int i = 1;i <= m;i ++){
		multiply1(multi,i);
		for(int j = 1;j <= n;j ++)
			
	}
}
