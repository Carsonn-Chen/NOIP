#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int cow[205];
int f[205];

bool cmp(int a,int b){
	return a > b;
}

int main(){
	int m,s,c;
	scanf("%d%d%d",&m,&s,&c);
	for(int i = 1;i <= c;i ++)
		scanf("%d",&cow[i]);
	if(m >= c){
		printf("%d\n",c);
		return 0;
	}
	sort(1+cow,1+cow+c,cmp);
	int ans = cow[1] - cow[c] + 1;
	for(int i = 1;i <= c-1;i ++)
		f[i] = cow[i] - cow[i+1];
	sort(f+1,f+c,cmp);
	for(int i = 1;i < m;i ++)
		ans = ans - f[i] + 1;
	printf("%d\n",ans);
	return 0;
}
