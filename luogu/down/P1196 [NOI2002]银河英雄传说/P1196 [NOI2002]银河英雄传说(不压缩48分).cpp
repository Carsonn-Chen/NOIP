#include <bits/stdc++.h>

using namespace std;

int fa[30005];
int tail[30005];

void unionn(int m,int n){
	int c = m;
	while(fa[c] != c)
		c = fa[c];
	fa[c] = tail[n];
	while(fa[c] != c){
		tail[c] = tail[m];
		c = fa[c];
	}
	tail[c] = tail[m];
}

int check(int m,int n){
	int step1 = 0,step2 = 0;
	int r1 = m,r2 = n;
	while(fa[r1] != r1){
		r1 = fa[r1];
		step1 ++;
	}
	while(fa[r2] != r2){
		r2 = fa[r2];
		step2 ++;
	}
	if(r1 == r2)
		return abs(step1-step2);
	else
		return -1;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0;i <= 30004;i ++)
		fa[i] = tail[i] = i;
	char e;
	int a,b;
	while(t--){
		cin >> e >> a >> b;
		if(e == 'M')
			unionn(a,b);
		else if(e == 'C'){
			int ans = check(a,b);
			if(ans == -1)
				printf("-1\n");
			else
				printf("%d\n",ans-1);
		}
	}
	return 0;
}
