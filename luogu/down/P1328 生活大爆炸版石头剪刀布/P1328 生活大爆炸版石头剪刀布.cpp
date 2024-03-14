#include <bits/stdc++.h>

using namespace std;

int ch[5][5] = {{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};
int ia[205],ib[205];


int main(){
	int n,na,nb;
	cin >> n >> na >> nb;
	for(int i = 0;i < na;i ++)
		cin >> ia[i];
	for(int i = 0;i < nb;i ++)
		cin >> ib[i];
	int ka = 0,kb = 0;
	int ans1 = 0,ans2 = 0;
	while(n --){
		if(ka == na)
			ka = 0;
		if(kb == nb)
			kb = 0;
		if(ch[ia[ka]][ib[kb]] == 1)
			ans1 += 1;
		else if(ch[ia[ka]][ib[kb]] == -1)
			ans2 += 1;
		ka ++;
		kb ++;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
