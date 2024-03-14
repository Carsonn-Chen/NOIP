#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int
#define N 200005

using namespace std;

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
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}

struct node {
	int l,r,s;
}t[N*100];

int n,m;
int a[N],root[N*2],v[N*2];
int top,tot,pos;
int inf[5][N];

void calc(int pre,int x,int l,int r) {
	if(l == r) {
		t[x].s = t[pre].s+1;
		return;
	}
	int m = (l+r) >> 1;
	if(pos <= m) {
		t[x].l = ++tot;
		t[x].r = t[pre].r;
		calc(t[pre].l,t[x].l,l,m);
	} else {
		t[x].l = t[pre].l;
		t[x].r = ++tot;
		calc(t[pre].r,t[x].r,m+1,r);
	}
	t[x].s = t[ t[x].l ].s + t[ t[x].r ].s;
}

void find(int x,int y,int l,int r,int k) {
	if(l == r) {
		pos = l;
		return;
	}
	int v = t[ t[y].l ].s - t[ t[x].l ].s;
	int m = (l+r) >> 1;
	if(k <= v)
		find(t[x].l,t[y].l,l,m,k);
	else{
		k = k-v;
		find(t[x].r,t[y].r,m+1,r,k);
	}
}

int main(){
	//freopen("in.in","r",stdin);
	n = read(),m = read();
	top = n;
	for(ri i = 1;i <= n;i ++)
		a[i] = read(),v[i] = a[i];
	for(ri i = 1;i <= m;i ++){
		inf[0][i] = read();
		if(inf[0][i] == 2)
			inf[1][i] = read(),v[++top] = inf[1][i];
		else if(inf[0][i] == 3){
			inf[1][i] = read();
			inf[2][i] = read();
			inf[3][i] = read();
		}
	}
	sort(v+1,v+1+top);
	top = unique(v+1,v+1+top)-v-1;
	for(ri i = 1;i <= n;i ++){
		root[i] = ++tot;
		pos = lower_bound(v+1,v+1+top,a[n-i+1])-v;
		calc(root[i-1],root[i],1,top);
	}
	for(ri i = 1;i <= m;i ++){
		if(inf[0][i] == 1)
			n --;
		else if(inf[0][i] == 2){
			root[ ++n ] = ++tot;
			pos = lower_bound(v+1,v+1+top,inf[1][i])-v;
			calc(root[n-1],root[n],1,top);
		}
		else{
			int k = inf[3][i];
			find(root[ n-inf[2][i] ],root[ n-inf[1][i]+1 ],1,top,k);
			write(v[pos]);
			putchar('\n');
		}
	}
	return 0;
}
