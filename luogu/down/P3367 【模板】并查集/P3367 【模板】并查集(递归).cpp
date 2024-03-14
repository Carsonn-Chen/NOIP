#include <bits/stdc++.h>

using namespace std;

int fa[10005];

int find(int k){
	if(fa[k] == k)
		return k;
	return fa[k] = find(fa[k]);
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
