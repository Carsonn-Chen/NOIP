#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

struct node{
	int c,d;
}cloud[10005];
int fa[10005];
int f[10005];

int Fa(int x){
	if(x == fa[x])
		return x;
	return fa[x] = Fa(fa[x]);
}

int main(){
	int n,m,w;
	scanf("%d%d%d",&n,&m,&w);
	for(ri i = 1;i <= n;i ++)
		scanf("%d%d",&cloud[i].c,&cloud[i].d);
	int a,b;
	for(ri i = 1;i <= n;i ++)
		fa[i] = i;
	for(ri i = 1;i <= m;i ++){
		scanf("%d%d",&a,&b);
		if(Fa(a) != Fa(b))
			fa[Fa(b)] = Fa(a);
	}
	for (int i=1;i<=n;i++)
    	if(fa[i] != i){
        	cloud[Fa(i)].c += cloud[i].c;
        	cloud[Fa(i)].d += cloud[i].d;
        	cloud[i].c = cloud[i].d = 0;
    	}
	for (ri i = 1;i <= n;i ++)
    	for (ri j = w;j >= cloud[i].c;j --)
    		f[j] = max(f[j],f[j-cloud[i].c]+cloud[i].d);
	printf("%d\n",f[w]);
	return 0;
}
