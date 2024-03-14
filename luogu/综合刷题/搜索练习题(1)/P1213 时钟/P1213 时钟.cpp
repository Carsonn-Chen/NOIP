#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int Clock[4][4];

void One(int x){
	if(x){
		Clock[1][1] += 3;
		Clock[1][2] += 3;
		Clock[2][1] += 3;
		Clock[2][2] += 3;
	}else{
		Clock[1][1] -= 3;
		Clock[1][2] -= 3;
		Clock[2][1] -= 3;
		Clock[2][2] -= 3;
	}
}

void Two(int x){
	if(x){
		Clock[1][1] += 3;
		Clock[1][2] += 3;
		Clock[1][3] += 3;
	}else{
		Clock[1][1] -= 3;
		Clock[1][2] -= 3;
		Clock[1][3] -= 3;
	}
}

void Three(int x){
	if(x){
		Clock[1][2] += 3;
		Clock[1][3] += 3;
		Clock[2][2] += 3;
		Clock[2][3] += 3;
	}else{
		Clock[1][2] -= 3;
		Clock[1][3] -= 3;
		Clock[2][2] -= 3;
		Clock[2][3] -= 3;
	}
}

void Four(int x){
	if(x){
		Clock[1][1] += 3;
		Clock[2][1] += 3;
		Clock[3][1] += 3;
	}else{
		Clock[1][1] -= 3;
		Clock[2][1] -= 3;
		Clock[3][1] -= 3;
	}
}

void Five(int x){
	if(x){
		Clock[1][2] += 3;
		Clock[2][1] += 3;
		Clock[2][2] += 3;
		Clock[2][3] += 3;
		Clock[3][2] += 3;
	}else{
		Clock[1][2] -= 3;
		Clock[2][1] -= 3;
		Clock[2][2] -= 3;
		Clock[2][3] -= 3;
		Clock[3][2] -= 3;
	}
}

void Six(int x){
	if(x){
		Clock[1][3] += 3;
		Clock[2][3] += 3;
		Clock[3][3] += 3;
	}else{
		Clock[1][3] -= 3;
		Clock[2][3] -= 3;
		Clock[3][3] -= 3;
	}
}

void Seven(int x){
	if(x){
		Clock[2][1] += 3;
		Clock[2][2] += 3;
		Clock[3][1] += 3;
		Clock[3][2] += 3;
	}else{
		Clock[2][1] -= 3;
		Clock[2][2] -= 3;
		Clock[3][1] -= 3;
		Clock[3][2] -= 3;
	}
}

void Eight(int x){
	if(x){
		Clock[3][1] += 3;
		Clock[3][2] += 3;
		Clock[3][3] += 3;
	}else{
		Clock[3][1] -= 3;
		Clock[3][2] -= 3;
		Clock[3][3] -= 3;
	}
}

void Nine(int x){
	if(x){
		Clock[2][2] += 3;
		Clock[2][3] += 3;
		Clock[3][2] += 3;
		Clock[3][3] += 3;
	}else{
		Clock[2][2] -= 3;
		Clock[2][3] -= 3;
		Clock[3][2] -= 3;
		Clock[3][3] -= 3;
	}
}

bool check(){
	for(register int i = 1;i <= 3;i ++)
		for(register int j = 1;j <= 3;j ++)
			if(Clock[i][j]%12 != 0)
				return false;
	return true;
}

int ans[105];

void Dfs(int cnt){
	if(check() || cnt > 10)
		return;
	One(1);
	ans[cnt] = 1;
	Dfs(cnt+1);
	One(0);
	
	Two(1);
	ans[cnt] = 2;
	Dfs(cnt+1);
	Two(0);
	
	Three(1);
	ans[cnt] = 3;
	Dfs(cnt+1);
	Three(0);
	
	Four(1);
	ans[cnt] = 4;
	Dfs(cnt+1);
	Four(0);
	
	Five(1);
	ans[cnt] = 5;
	Dfs(cnt+1);
	Five(0);
	
	Six(1);
	ans[cnt] = 6;
	Dfs(cnt+1);
	Six(0);
	
	Seven(1);
	ans[cnt] = 7;
	Dfs(cnt+1);
	Seven(0);
	
	Eight(1);
	ans[cnt] = 8;
	Dfs(cnt+1);
	Eight(0);
	
	Nine(1);
	ans[cnt] = 9;
	Dfs(cnt+1);
	Nine(0);
}

int main(){
	for(register int i = 1;i <= 3;i ++)
		for(register int j = 1;j <= 3;j ++)
			scanf("%d",&Clock[i][j]);
	Dfs(1);
	int i = 1;
	while(ans[i] != 0)
		printf("%d ",ans[i++]);
	return 0;
}
