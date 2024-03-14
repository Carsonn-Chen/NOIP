#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#define ri register int
#define maxn 100005
#define maxt 86400

using namespace std;

int read(){
	int summ = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		summ = summ * 10 + e - '0';
		e = getchar();
	}
	return summ;
}

void write(int x){
	if(x > 9)
		write(x/10);
	putchar(x%10 + '0');
}

int n;
int Time[maxn];
int Country[maxn*3];
vector<int>peo[maxn];

int main(){
	n = read();
	int k;
	for(ri i = 1;i <= n;i ++){
		Time[i] = read();
		k = read();
		for(ri j = 1;j <= k;j ++)
			peo[i].push_back(read());
	}
	int top = 1;
	int ans = 0;
	for(ri i = 1;i <= n;i ++){
		for(ri j = 0;j < (int)peo[i].size();j ++){
			if(!Country[peo[i][j]])
				ans ++;
			Country[peo[i][j]] ++;
		}
		while(Time[i] - Time[top] >= maxt){
			for(ri j = 0;j < (int)peo[top].size();j ++){
				Country[peo[top][j]] --;
				if(!Country[peo[top][j]])
					ans --;
			}
			top ++;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
