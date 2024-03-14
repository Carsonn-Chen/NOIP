#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int Need[30];
int Sl[20][30];
int ans[20];
int cnt = 99999999;
int V,G;
int now[20];
bool via[20];

inline int read()
{
    int X = 0,w = 0; 
	char ch = 0;
    while(!isdigit(ch)) {
		w |= ch=='-';
		ch = getchar();}
    while(isdigit(ch)) 
		X = (X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}


bool check(int cntt){
	for(ri i = 1;i <= V;i ++){
		int temp = 0;
		for(ri j = 1;j <= cntt;j ++)
			temp += Sl[now[j]][i];
		if(temp < Need[i])
			return false;
	}
	return true;
}

void Dfs(int k,int cntt){
	if(cntt > G)
		return;
	now[cntt] = k;
	if(check(cntt)){
		if(cntt < cnt){
			cnt = cntt;
			for(ri i = 1;i <= cntt;i ++)
				ans[i] = now[i];
		}
		return;
	}
	for(ri i = k;i <= G;i ++){
		if(!via[i]){
			via[i] = 1;
			Dfs(i,cntt+1);
			via[i] = 0;
		}
	}
}

int main(){
	V = read();
	for(ri i = 1;i <= V;i ++)
		Need[i] = read();
	G = read();
	for(ri i = 1;i <= G;i ++)
		for(ri j = 1;j <= V;j ++)
			Sl[i][j] = read();
	for(ri i = 1;i <= G;i ++){
		via[i] = 1;
		Dfs(i,1);
		via[i] = 0;
	}
	cout << cnt << " ";
	for(ri i = 1;i <= cnt;i ++)
		cout << ans[i] << " ";
	return 0;
}
