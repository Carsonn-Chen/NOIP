#include<cstdio>
#include<cstring>
#define base 1000000000
using namespace std;
char s[10005];
int two=0;
struct long_long_long {
	int t[3000];
	int len;
	long_long_long() {
		memset(t,0,sizeof(t));
		len=0;
	}
	void read() {
		scanf("%s",s+1);
		s[0]=0;
		int slen=strlen(s+1),p=0,w=1;
		for(int i=slen; i; --i) {
			p=p+(s[i]^'0')*w;
			w*=10;
			if(w==base) {
				t[++len]=p;
				p=0;
				w=1;
			}
		}
		if(p)t[++len]=p;
		if(len==1&&t[1]==0)len=0;
	}
	inline void print() {
		if(len==0) {
			puts("0");
			return;
		}
		printf("%d",t[len]);
		for(int i=len-1; i; --i)
			printf("%09d",t[i]);
		printf("\n");
	}

} a,b;
bool cmp() {
	if(a.len!=b.len)return a.len<b.len;
	for(int i=a.len; i; --i)
		if(a.t[i]!=b.t[i])return a.t[i]<b.t[i];
	return 0;
}
void a_div2() {
	for(int i=1; i<=a.len; ++i) {
		if(a.t[i]&1)a.t[i-1]+=500000000;
		a.t[i]>>=1;
	}
	while(a.t[a.len]==0&&a.len>0)--a.len;
}
void b_div2() {
	for(int i=1; i<=b.len; ++i) {
		if(b.t[i]&1)b.t[i-1]+=500000000;
		b.t[i]>>=1;
	}
	while(b.t[b.len]==0&&a.len>0)--b.len;
}
void a_mul2() {
	for(int i=1; i<=a.len; ++i) {
		a.t[i]<<=1;
		a.t[i]+=a.t[i-1]/base;
		a.t[i-1]%=base;
	}
	if(a.t[a.len]>=base) {
		a.t[a.len+1]=a.t[a.len]/base;
		a.t[a.len++]%=base;
	}
}
void b_mul2() {
	for(int i=1; i<=b.len; ++i) {
		b.t[i]<<=1;
		b.t[i]+=b.t[i-1]/base;
		b.t[i-1]%=base;
	}
	if(b.t[b.len]>=base) {
		b.t[b.len+1]=b.t[b.len]/base;
		b.t[b.len++]%=base;
	}
}
int main() {
	a.read();
	b.read();
	while(!(a.t[1]&1)&&!(b.t[1]&1)) {
		a_div2();
		b_div2();
		++two;
	}
	while(1) {
		while(!(a.t[1]&1))a_div2();
		while(!(b.t[1]&1))b_div2();
		if(cmp()) {
			for(int i=1; i<=a.len; ++i) {
				if(b.t[i]<a.t[i]) {
					--b.t[i+1];
					b.t[i]+=base;
				}
				b.t[i]-=a.t[i];
			}
			while(b.t[b.len]==0&&b.len>0)--b.len;
			if(!b.len) {
				while(two--)a_mul2();
				a.print();
				return 0;
			}
		} else {
			for(int i=1; i<=b.len; ++i) {
				if(a.t[i]<b.t[i]) {
					--a.t[i+1];
					a.t[i]+=base;
				}
				a.t[i]-=b.t[i];
			}
			while(a.t[a.len]==0&&a.len>0)--a.len;
			if(!a.len) {
				while(two--)b_mul2();
				b.print();
				return 0;
			}
		}
	}
	return 0;
}
