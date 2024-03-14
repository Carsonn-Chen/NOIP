#include <bits/stdc++.h>
#define ri register int

using namespace std;

int a[10005];
int sum1[10005],sum2[10005];
int n,m;

inline int lowbit(int x){
	return x & -x;
}

void add(int x,int *t,int d){
	for(;x <= n;x += lowbit(x))
		t[x] += d;
}

void update(int x,int y,int k){
	add(x,sum1,k);
	add(y+1,sum1,-k);
	add(x,sum2,(x-1)*k);
	add(y+1,sum2,-y * k);
}

int sum(int x,int *t){
	int summ = 0;
	for(;x; x-= lowbit(x))
		summ += t[x];
	return summ;
}

int calc(int s,int t){
	return ( (t * sum(t,sum1) - sum(t,sum2)) - ((s-1) * sum(s-1,sum1) - sum(s-1,sum2)) );
}


int main(){
	freopen("in.in","r",stdin);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ri i = 1;i <= n;++ i){
		cin >> a[i];
		add(i,sum1,a[i] - a[i-1]);
		add(i,sum2,(i-1)*(a[i] - a[i-1]));
	}
	int tag;
	int a,b,c;
	for(ri i = 1;i <= m;i ++){
		cin >> tag;
		if(tag == 1){
			cin >> a >> b >> c;
			update(a,b,c);
		}
		else{
			cin >> a >> b;
			cout << calc(a,b) << endl;;
		}
	}
	fclose(stdin);
	return 0;
}