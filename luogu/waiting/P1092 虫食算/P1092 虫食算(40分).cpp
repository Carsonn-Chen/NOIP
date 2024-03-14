#include <bits/stdc++.h>

using namespace std;

int n;
string a,b,c;
int p[30];
bool tag[30] = {0};
bool pd = 0;
int a1[30],b1[30],c1[30],d[30];

bool calc(){
	memset(d,0,sizeof(d));
	for(int m = 1;m <= n;m ++){
		a1[m] = p[(a[m-1]-'A')];
		b1[m] = p[(b[m-1]-'A')];
		c1[m] = p[(c[m-1]-'A')];
	}
	for(int m = n;m >= 1;m --){
		d[m] += a1[m]+b1[m];
		if(d[m] >= n){
			d[m] -= n;
			d[m-1] += 1;
		}
	}
	for(int m = 1;m <= n;m ++)
		if(c1[m] != d[m])
			return 0;
}

void DFS(int i){
	if(i == n){
		if(calc())
			pd = 1;
		return;
	}
	for(register int j = 0;j < n;j ++){
		if(!tag[j]){
			p[i] = j;
			tag[j] = 1;
			DFS(i+1);
			if(pd)
				return;
			tag[j] = 0;
		}
	}
}

int main(){
	scanf("%d",&n);
	cin >> a >> b >> c;
	DFS(0);
	if(pd)
		for(int o = 0;o < n;o ++)
			cout << p[o] << " ";
	return 0;
}
