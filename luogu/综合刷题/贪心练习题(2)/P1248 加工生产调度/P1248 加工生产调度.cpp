#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	long long a;
	long long b;
	long long no;
}inf[1005];

bool cmp(node x,node y){
	return x.a+max(x.b,y.a)+y.b < y.a+max(y.b,x.a)+x.b;
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		scanf("%lld",&inf[i].a);
		inf[i].no = i;
	}
	for(int i = 1;i <= n;i ++)
		scanf("%lld",&inf[i].b);
	sort(inf+1,inf+1+n,cmp);
	long long fa = inf[1].a,fb = inf[1].a+inf[1].b;
    for(int i = 2;i <=n ;i ++){
        fb = max(fa+inf[i].a,fb) + inf[i].b;
        fa += inf[i].a;
    }
	printf("%lld\n",fb);
	for(int i = 1;i <= n;i ++)
		printf("%lld ",inf[i].no);
	return 0;
}
