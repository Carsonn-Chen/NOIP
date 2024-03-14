#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#define ri register int

using namespace std;

struct Int {
	vector<int> v;
};

char a[55];
Int num[45][45];
Int f[45][10];
int N,K;

Int mul(Int A,Int B) {
	Int c;
	c.v.clear();
	int LA=A.v.size();
	int LB=B.v.size();
	c.v.resize(LA+LB);
	for(ri i=0; i<LA; i++) {
		for(ri j=0; j<LB; j++) {
			c.v[i+j]+=A.v[i]*B.v[j];
			c.v[i+j+1]+=c.v[i+j]/10;
			c.v[i+j]%=10;
		}
	}
	int place=LA+LB-1;
	while(c.v[place]==0&&place>0) place--;
	c.v.resize(place+1);
	return c;
}
Int add(Int A,Int B) {
	Int c;
	c.v.clear();
	int LA=A.v.size();
	int LB=B.v.size();
	c.v.resize(LA+LB);
	int len=max(LA,LB);
	int g=0;
	for(ri i=0; i<len||g; i++) {
		int x=g;
		if(i < (int)A.v.size()) x+=A.v[i];
		if(i < (int)B.v.size()) x+=B.v[i];
		c.v[i]=x%10;
		g=x/10; //gÊÇ½øÎ»
	}
	int place=LA+LB-1;
	while(c.v[place]==0&&place>0) place--;
	c.v.resize(place+1);
	return c;
}
bool cmp(const Int &A,const Int &B) {
	if(A.v.size() != B.v.size()) return A.v.size() > B.v.size();
	for(ri i=A.v.size()-1; i>=0; i--) {
		if(A.v[i]!=B.v[i]) return A.v[i] > B.v[i];
	}
	return false;
}
Int INT(int x) {
	Int c;
	c.v.clear();
	do {
		c.v.push_back(x%10);
		x/=10;
	} while(x);
	return c;
}
void in(Int &x) {
	string s;
	cin>>s;
	x.v.clear();
	for(ri i=0; i < (int)s.length(); i++)
		x.v.push_back(s[i]-'0');
}
void out(const Int &x) {
	for(ri i=x.v.size()-1; i>=0; i--) {
		printf("%d",x.v[i]);
	}
}

int main() {
	cin >> N >> K;
	K ++;
	scanf("%s",a+1);
	for(ri i = 1; i <= N; i ++) 
		a[i]-='0';
	for(ri i = 1; i <= N; i ++)
		num[i][i]=INT(a[i]);
	for(ri i = 1; i <= N; i ++) {
		for(ri j=i+1; j<=N; j++) {
			Int c=mul(num[i][j-1],INT(10));
			num[i][j]=add(c,INT(a[j]));
		}
	}
	for(ri i=1; i<=N; i++) f[i][1]=num[1][i];
	for(ri i = 2; i <= N; i ++) {
		for(ri j = 2; j <= i && j <= K; j ++) {
			for(ri k = j-1; k+1 <= i; k ++) {
				Int x = mul(num[k+1][i],f[k][j-1]);
				if( cmp( x,f[i][j] ) )
					f[i][j]=x;
			}
		}
	}
	out(f[N][K]);
	return 0;
}
