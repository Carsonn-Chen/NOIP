#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#define ri register int
#define maxn 100005

using namespace std;

int num1[maxn],num2[maxn];
map <int,int>M;
int f[maxn];  

int main(){
	int n;
	cin >> n;
	memset(f,0x3f,sizeof(f));
	for(ri i = 1;i <= n;i ++)
		cin >> num1[i],M[num1[i]] = i;
	int x;
	for(ri i = 1;i <= n;i ++){
		cin >> x;
		num2[i] = M[x];
	}
	for(ri i = 1;i <= n;i ++){
		x = num2[i];
		*lower_bound(f+1,f+1+n,x) = x;
	}
	printf("%d\n",lower_bound(f+1,f+n+1,f[0])-f-1);
	return 0;
}
