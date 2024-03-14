#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define ri register int

using namespace std;

int a[100005];
int add = 0;
queue<int> q,q1,q2;

bool cmp(int x,int y) {
	return x > y;
}

int ft(queue<int> &Q) {
	return Q.empty()?-0x3f3f3f3f:Q.front()+add;
}

int get() {
	int a=ft(q),b=ft(q1),c=ft(q2);
	int maxn=max(max(b,c),a);
	if(maxn==a) q.pop();
	else if(maxn==b) q1.pop();
	else q2.pop();
	return maxn;
}
int main() {
	int n,m,d,x1,x2,t;
	scanf("%d%d%d%d%d%d",&n,&m,&d,&x1,&x2,&t);
	for(ri i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(ri i = 1;i <= n;i ++)
		q.push(a[i]);
	for(ri i = 1;i <= m;i ++,add += d){
		int top = get();
		int a1= (long long)top*x1/x2;
		int a2 = top-a1;
		q1.push(a1-d-add);
		q2.push(a2-d-add);
		if(i%t == 0)
			printf("%d ",top);
	}
	printf("\n");
	for(ri i = 1;i <= m+n;i ++)
		if(i%t == 0)
			printf("%d ",get());
		else 
			get();
	printf("\n");
	return 0;
}
