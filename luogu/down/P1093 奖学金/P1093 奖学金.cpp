#include <bits/stdc++.h>

using namespace std;

struct inf{
	int yw;
	int zf;
	int id;
}pop[305];

bool cmp1(inf x,inf y){
	if(x.zf == y.zf){
		if(x.yw == y.yw)
			return x.id < y.id;
		return x.yw > y.yw;
	}
	return x.zf > y.zf;
}

int main(){
	int n;
	cin >> n;
	int a,b;
	for(int i = 1;i <= n;i ++){
		cin >> pop[i].yw >> a >> b;
		pop[i].zf = pop[i].yw+a+b;
		pop[i].id = i;
	}
	sort(pop+1,pop+1+n,cmp1);
	for(int i = 1;i <= 5;i ++)
		printf("%d %d\n",pop[i].id,pop[i].zf);
	return 0;
}
