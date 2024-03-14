#include <bits/stdc++.h>

using namespace std;

int N[1005] = {0};			//0代表没出现过关系.1代表只出现过朋友,-1代表出现过敌人了 

int main(){
	int n,m;
	int ans = 0;
	char r;
	int a,b;
	cin >> n >> m;
	for(int i = 1;i <= m;i ++){
		cin >> r >> a >> b;
		if(N[a] == 0 && N[b] == 0){
			if(r == 'F'){
				N[a] = N[b] = 1;
				ans += 1;	 
			}
			else if(r == 'E'){
				N[a] = N[b] = -1;
				ans += 2;	 
			}
		}
		else if(((N[a] == 1 && N[b] != 1) || (N[b] == 1 && N[a] != 1)) && r == 'E'){
			N[a] = N[b] = -1;
			ans -= 1;
		}
	}
	cout << ans;
	return 0;
}
