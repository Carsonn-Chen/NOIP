#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int
#define ll long long
#define mod 1000000007
#define maxn 55

ll t[11]= {0,7,77,777,7777,77777};
ll topn,topf;
ll ans[15];
ll num[maxn];
char a[maxn];
char c[maxn];
char f[maxn];

ll pow_mod(ll a,ll b,ll p) {
	ll s = 1;
	a %= p;
	while(b) {
		if(b&1)
			s = s*a%p;
		a = a*a%p;
		b >>= 1;
	}
	return s;
}

ll level(char c) {
	if(c == '(')
		return 0;
	if(c == '+' || c == '-')
		return 1;
	if(c == '*' || c == '/')
		return 2;
	if(c == '^')
		return 3;
	return 0;
}

void work() {
	ll x = num[topn--];
	ll y = num[topn--];
	char c = f[topf--];
	if(c == '+')
		num[++topn] = (x+y)%mod;
	else if(c=='-')
		num[++topn] = (y-x+mod)%mod;
	else if(c=='*')
		num[++topn] = (x*y)%mod;
	else if(c=='^')
		num[++topn] = pow_mod(y,x,mod);
}

void getnum(char* a,ll &p) {
	ll sum = 0;
	while(isdigit(a[p]))
		sum = (sum*10+(a[p++]&15))%mod;
	num[++topn] = sum;
}

ll solve(char* a,ll i) {
	ll p = topf = topn = 0;
	int len = strlen(a);
	while(p < len) {
		if(isdigit(a[p]))
			getnum(a,p);
		else if(a[p]==' ')
			p++;
		else if(a[p]=='+'||a[p]=='-'||a[p]=='*'||a[p]=='/'||a[p]=='^') {
			if(level(a[p])>level(f[topf])) f[++topf]=a[p++];
			else {
				while(level(a[p]) <= level(f[topf]))
					work();
				f[++topf] = a[p++];
			}
		} 
		else if(a[p] == 'a')
			num[++topn] = t[i],p++;
		else if(a[p] == '(')
			f[++topf] = a[p++];
		else if(a[p] == ')'){
			bool tag = 0;
			for(ri i= 1 ;i <= topf;i ++)
				tag |= (f[i]=='(');
			if(!tag){
				p ++;
				continue;
			}
			while(f[topf]^'(')
				work();
			topf --;
			p ++;
		}
	}
	while(topn^1)
		work();
	return num[1];
}

void get(char* x) {
	for(ri i = 0;i <= 50;i ++)
		x[i] = '\0';
	char c = getchar();
	int pos = 0;
	while(c == '\n' || c == '\r')
		c = getchar();
	while(c != '\n' && c != '\r')
		x[pos++] = c,c = getchar();
}

int main() {
	get(a);
	for(ri i = 1;i <= 5;i ++)
		ans[i] = solve(a,i);
	int n;
	scanf("%d\n",&n);
	for(ri k = 1; k <= n;k ++) {
		get(c);
		bool b = 1;
		for(ri i = 1;i <= 5;i ++) {
			if(solve(c,i)^ans[i]) {
				b = 0;
				break;
			}
		}
		if(b)
			putchar(k+'A'-1);
	}
	return 0;
}
