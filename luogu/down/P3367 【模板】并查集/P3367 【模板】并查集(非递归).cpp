#include <bits/stdc++.h>

using namespace std;

int fa[10005];

int find(int k){
	int x,y;
	x = k;
	while(x != fa[x])
		x = fa[x];
	while(k != x){
		y = fa[k];
		fa[k] = x;
		k = y;
	}
	return x; 
}

int main(){
	int n,m;
	int zi,xi,yi;
	cin >> n >> m;
	for(int i = 0;i <= n;i ++)
		fa[i] = i;
	while(m--){
		cin >> zi >> xi >> yi;
		if(zi == 1)
			fa[find(xi)] = find(yi);
		else{
			if(find(xi) == find(yi))
				printf("Y\n");
			else
				printf("N\n");
		}
	}
	return 0;
}
