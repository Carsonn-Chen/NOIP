#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define mod 998244353
#define LL long long

using namespace std;

const int N = 1e7+5;
int f[N];

inline int read(){
    int X = 0,w = 0;
	char ch = getchar();
    while(!isdigit(ch))
		w|=ch=='-',ch=getchar();
    while(isdigit(ch))
		X = (X<<3)+(X<<1)+(ch^48),ch = getchar();
    return w?-X:X;
}

void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main(){
	f[0] = f[1] = 1;
	for(ri i = 2;i < N;i ++)
		f[i] = (LL)(mod - mod/i)*f[mod%i]%mod;
	for(ri i = 2;i < N;i ++)
		f[i] = (f[i]+f[i-1])%mod;
	int T = read();
	while(T--){
		int n = read();
		write((n-f[n]+mod)%mod);
		putchar('\n');
	}
	return 0;
}
