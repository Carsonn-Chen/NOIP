#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int time;
	int v;
}inf[505];

bool cmp(node a,node b){
	return a.v > b.v;
}

bool tag[505];

int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&inf[i].time);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&inf[i].v);
	sort(inf+1,inf+1+n,cmp);
	bool sign;
	for(int i = 1;i <= n;i ++){
		sign = 1;
		for(int j = inf[i].time;j >= 1;j --){
			if(!tag[j]){
				tag[j] = 1;
				sign = 0;
				break;
			}
		}
		if(sign)
			m -= inf[i].v;
	}
	printf("%d\n",m);
	return 0;
}
