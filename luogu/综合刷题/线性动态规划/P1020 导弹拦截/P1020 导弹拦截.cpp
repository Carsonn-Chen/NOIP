#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int h[100005];
int h1[100005];
int f[100005];
int n = 1;

int main(){
	//freopen("in.in","r",stdin);
	while(cin >> h[n++]);
	n -= 2;
	memset(f,0x3f,sizeof(f));
	for(ri i = 1;i <= n;i ++)
		h1[i] = h[n-i+1];
	for(ri i = 1;i <= n;i ++){
		int x = h1[i];
		*upper_bound(f+1,f+n+1,x) = x;
	}
	int cnt1 = lower_bound(f+1,f+1+n,f[0]) - f-1;
	memset(f,0x3f,sizeof(f));
	for(ri i = 1;i <= n;i ++){
		int x = h[i];
		*lower_bound(f+1,f+1+n,x) = x;
	}
	int cnt2 = lower_bound(f+1,f+1+n,f[0]) - f-1;
	cout << cnt1 << '\n' << cnt2 << endl;
}
