#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

string z = "0abcdefghijklmnopqrstuvwxyz";
int s,t,w;
string a;
int pos[30];

int calc(int i){
	if(pos[i] > t - (int)a.size() + i + 1){
		pos[i - 1] ++;
		pos[i] = calc(i-1) + 1;
	}
	return pos[i];
}

int main(){
	scanf("%d%d%d",&s,&t,&w);
	cin >> a;
	for(ri i = 0;i < (int)a.size();i ++)
		for(ri j = 1;j <= 26;j ++)
			if(a[i] == z[j]){
				pos[i] = j;
				break;
			}
	int cnt = 0;
	while(1){
		if(cnt == 5)
			break;
		pos[a.size() - 1] ++;
		calc(a.size() - 1);
		if(pos[0] > t - (int)a.size() + 1)
			break;
		else{
			for(ri i = 0;i < w;i ++)
				printf("%c",z[pos[i]]);
			printf("\n");
			cnt ++;
		}
	}
	return 0;
}
