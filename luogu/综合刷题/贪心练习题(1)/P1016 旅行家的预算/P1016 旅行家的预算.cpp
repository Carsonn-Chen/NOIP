#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	double d;
	double p;
}inf[10];

bool cmp1(node a,node b){
	return a.d < b.d;
}

int main(){
	double d1,c,d2,p1;
	int n;
	scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p1,&n);
	for(int i = 1;i <= n;i ++)
		scanf("%lf%lf",&inf[i].d,&inf[i].p);
	inf[0].d = 0;
	inf[0].p = p1;
	inf[n+1].d = d1;
	inf[n+1].p = 0;
	sort(inf+1,inf+1+n,cmp1);
	for(int i = 1;i <= n+1;i ++)
		if(inf[i].d - inf[i-1].d > c * d2){
			printf("No Solution\n");
			return 0;
		}
	int now = 0;
	double rest = d1,lastp = p1,lasto;
	double ans = 0;
	bool tag = 1;
	while(rest){
		tag = 1;
		for(int i = now+1;i <= n+1;i ++){
			if(inf[i].d - inf[now].d < c*d2 && inf[i].p < lastp){
				ans = ans + ((inf[i].d-inf[now].d) / d2 - lasto) * lastp;
				rest -= (inf[i].d - inf[now].d);
				lastp = inf[i].p;
				now = i;
				tag = 0;
				lasto = 0;
			} 
		}
		if(tag == 1){
			ans = ans + c * lastp;
			double Min = 999999999;
			int Mini;
			for(int i = now+1;i <= n+1;i ++){
				if(inf[i].p < Min && inf[i].d - inf[now].d < c*d2){
					Mini = i;
					Min = inf[i].p;
				}
			}
			lastp = inf[Mini].p;
			lasto = c - (inf[Mini].d-inf[now].d) / d2;
			rest -= (inf[Mini].d - inf[now].d);
			now = Mini;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
