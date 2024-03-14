#include <bits/stdc++.h>

using namespace std;

priority_queue<long long>q;

int main(){
	/*freopen("earthworm5.in","r",stdin);
	freopen("out.out","w",stdout);*/
	int n,m,l,u,v,t;
	scanf("%d%d%d%d%d%d",&n,&m,&l,&u,&v,&t);
	long long x;
	for(int i = 1;i <= n;i ++){
		scanf("%lld",&x);
		q.push(x);
	}
	for(int i = 0;i < m;i ++){
		x = q.top()+i*l;
		q.pop();
		if((i+1)%t == 0)
			printf("%lld ",x);
		int x2 = u*x/v;
		q.push(x2-(i+1)*l);
		q.push(x-x2-(i+1)*l);
	}
	printf("\n");
	int i = 1;
	l = l*m;
	while(!q.empty()){
		long long x2 = q.top()+l;
		q.pop();
		if(i%t == 0)
			printf("%lld ",x2);
		i ++;
	}
	return 0;
}
