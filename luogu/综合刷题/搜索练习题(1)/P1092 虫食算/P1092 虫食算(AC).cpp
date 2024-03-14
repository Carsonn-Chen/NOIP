#include <cstdio>
#include <cstring>
#include <cmath>
#include<algorithm>
#include <iostream>
#define maxn 35

using namespace std;

int a[maxn],b[maxn],c[maxn];
int num[maxn],Next[maxn],n,cnt;
char s1[maxn],s2[maxn],s3[maxn];
bool vis[maxn];

bool check() {
	int x= 0;
	for(int i = n-1; i >= 0; i --) {
		int A = num[a[i]],B = num[b[i]],C = num[c[i]];
		if((A+B+x)%n != C) 
			return false;
		x = (A+B+x) / n;
	}
	return true;
}

bool check2() {
	if(num[a[0]]+num[b[0]] >= n)
		return true;
	for(int i = n-1; i >= 0; i --) {
		int A = num[a[i]],B = num[b[i]],C = num[c[i]];
		if(A == -1 || B == -1 || C == -1) 
			continue;
		if((A+B)%n != C&&(A+B+1)%n != C)
			return true;
	}
	return false;
}

void Print() {
	for(int i = 0; i < n; i ++)
		printf("%d ",num[i]);
	exit(0);
}

void dfs(int x) {
	if(check2() == true) 
		return;
	if(x == n) {
		if(check() == true) 
			Print();
		return;
	}
	for(int i = n-1; i >= 0; i --)
		if(vis[i] == false) {
			num[Next[x]] = i;
			vis[i] = true;
			dfs(x+1);
			num[Next[x]] = -1;
			vis[i] = false;
		}
	return;
}

void GetNext(int x) {
	if(vis[x]==false) {
		vis[x]=true;
		Next[cnt++]=x;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s1 >> s2 >> s3;
	for(int i = 0; i < n; i ++) {
		a[i]=(int)(s1[i] - 'A');
		b[i]=(int)(s2[i] - 'A');
		c[i]=(int)(s3[i] - 'A');
		num[i] = -1;
	}
	for(int i = n-1; i >= 0; i --) {
		GetNext(a[i]);
		GetNext(b[i]);
		GetNext(c[i]);
	}
	for(int i = 0; i < n; i ++) 
		vis[i]=false;
	dfs(0);
	return 0;
}
