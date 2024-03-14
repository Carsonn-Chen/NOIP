#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

inline int read(){
	char e = getchar();
	int sum = 0;
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		sum = sum*10 + e - '0';
		e = getchar();
	}
	return sum;
}

int n,m;
int cnt[40005][5];

struct node{
	int v;
	int id;
}inf[40005];

bool cmp1(node x,node y){
	return x.v < y.v;
}

int main(){
	n = read();
	m = read();
	for(ri i = 1;i <= m;i ++){
		inf[i].v = read();
		inf[i].id = i;
	}
	sort(inf+1,inf+1+m,cmp1);
	for(ri a = 1;a <= m-3;a ++)
		for(ri b = a+1;b <= m-2;b ++){
			if(inf[a].v == inf[b].v)
				continue;
			for(ri c = b+1;c <= m-1;c ++){
				if(inf[b].v == inf[c].v)
					continue;
				for(ri d = c+1;d <= m;d ++){
					if(inf[d].v == inf[c].v)
						continue;
					if((inf[b].v - inf[a].v) == 2*(inf[d].v-inf[c].v) && (inf[b].v - inf[a].v)*3 < (inf[c].v - inf[b].v)){
						cnt[inf[a].id][1] ++;
						cnt[inf[b].id][2] ++;
						cnt[inf[c].id][3] ++;
						cnt[inf[d].id][4] ++;
					}
				}
			}
		}
	for(ri i = 1;i <= m;i ++)
		printf("%d %d %d %d\n",cnt[i][1],cnt[i][2],cnt[i][3],cnt[i][4]);
	return 0;
}
