#include <cstdio> 
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int
#define LL long long

using namespace std;

struct node{
	LL a,b,c;
}food[55];
LL f[100005];

bool cmp(node x,node y){
	return x.c*y.b < x.b*y.c;
}

int main(){
	ios::sync_with_stdio(false);
	int n,t;
	cin >> t >> n;
	for(ri i = 1;i <= n;i ++)
		cin >> food[i].a;
	for(ri i = 1;i <= n;i ++)
	 	cin >> food[i].b;
	for(ri i = 1;i <= n;i ++) 
	 	cin >> food[i].c;
	sort(food+1,food+1+n,cmp);
	memset(f,-1,sizeof(f));
	f[0] = 0;
	for(ri i = 1;i <= n;i ++)
		for(ri j = t;j >= 0;j --)
			if (f[j] != -1 && j + food[i].c <= t)
                f[j + food[i].c] = max(f[j + food[i].c], f[j] + food[i].a - ((j + food[i].c) * food[i].b));
	cout << *max_element(f,f+t+1) << endl;
	return 0;
}
