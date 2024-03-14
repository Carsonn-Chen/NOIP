#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#define ri register int
#define maxn 105

using namespace std;

int n,a[maxn],b[maxn];
int c[2][maxn],ans[maxn];
char s[maxn];

bool same(int p[],int q[],int x) {
	for(ri i=1; i<=x; i++)
		if(p[i]!=q[i])return 0;
	return 1;
}

void multi_1(int x) {
	int last = 0;
	for(ri i = 1;i <= ans[0];i ++) {
		ans[i] = ans[i]*x+last;
		last = ans[i]/10,ans[i]%=10;
	}
	if(last>0)ans[++ans[0]]=last;
}

void multi_2(int w[],int p[],int q[]) {
	int i,k,last = 0;
	w[0] = min(p[0]+q[0]-1,n);
	for(k = 1;k <= w[0];k ++) {
		for(w[k] = last,i = 1;i <= p[0];i ++)
			if(k+1-i>=1 && k+1-i<=q[0])
				w[k] += p[i]*q[k+1-i];
		last = w[k]/10;
		w[k] %= 10;
	}
	if(last)
		w[++w[0]] = last;
}

int get(int x) {
	memcpy(c[0],b,sizeof(b));
	for(ri i = 1;i <= 10;i ++) {
		multi_2(c[i%2],c[(i+1)%2],b);
		if(same(c[i%2],b,x)) {
			multi_2(c[i%2],c[(i-1)%2],a);
			if(!same(c[i%2],a,x)){
				printf("-1\n");
				exit(0);
			};
			memcpy(b,c[(i-1)%2],sizeof(c[0]));
			return i;
		}
	}
	printf("-1\n" );
	exit(0);
}

int main() {
	scanf("%s%d",s,&n);
	a[0] = strlen(s);
	n = min(a[0],n);
	for(ri i = 1;i <= n;i ++)
		a[i]=s[a[0]-i]-'0';
	memcpy(b,a,sizeof(a));
	ans[0] = 1;
	ans[1] = 1;
	for(ri i = 1;i <= n;i ++)
		multi_1(get(i));
	for(ri i = ans[0];i >= 1;i --)
		printf("%d",ans[i]);
	return 0;
}

