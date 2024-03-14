#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int ans;
int n,k;
 
void DFS(int kk,int tot,int last){
	if(tot > n)
		return;
	if(kk == k){
		if(tot == n)
			ans++;
		return;
	}
	for(int i = last;i <= (n-tot);i ++)
		DFS(kk+1,tot+i,i);
}

int main(){
	cin >> n >> k;
	for(int i = 1;i <= (n-k+1);i ++)
		DFS(1,i,i);
	cout << ans << endl;
	return 0;
}
