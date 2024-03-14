#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n;
bool vis[105];
int num[105];
bool tag[505];

bool pd(int x){
	for(ri i = 2;i*i <= x;i ++)
		if(x % i == 0)
			return false;
	return true;
}

void search(int cnt){
	if(cnt == n*n+1){
		for(ri i = 1;i <= n*n;i ++){
			printf("%d ",num[i]);
			if(i % n == 0)
				printf("\n");
		}
		exit(0);
	}
	for(ri i = 1;i <= n*n;i ++){
		if(!vis[i]){
			if(cnt % n == 1){
				if(tag[i+num[cnt - n]]){
					num[cnt] = i;
					vis[i] = 1;
					search(cnt+1);
					vis[i] = 0;
				}	
			}else if(cnt <= n){
				if(tag[i+num[cnt - 1]]){
					num[cnt] = i;
					vis[i] = 1;
					search(cnt+1);
					vis[i] = 0;
				}
			}else{
				if(tag[i+num[cnt - 1]] && tag[i+num[cnt - n]]){
					num[cnt] = i;
					vis[i] = 1;
					search(cnt+1);
					vis[i] = 0;
				}
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	if(n == 1){
		printf("NO\n");
		return 0;
	}
	for(ri i = 2;i <= 500;i ++)	
		if(pd(i))
			tag[i] = 1;
	num[1] = 1;
	vis[1] = 1;
	search(2);
	printf("NO\n");
	return 0;
}
