#include <bits/stdc++.h>

using namespace std;

int qp[15][15] = {0};
int n;
int ans = 0;
int ac = 1;
int rec[15];

void DFS(int cnt){
	if(cnt == n+1){
		ans += 1;
		if(ac <= 3){
			for(int k = 1;k <= n;k ++)
				cout << rec[k] << " ";
			cout << endl;
			ac += 1;
		}
		return;
	}
	for(int i = 1;i <= n;i ++){
		if(qp[cnt][i] == 0){
			int temp = i;
			for(int j = cnt;j <= n;j ++){
				if(qp[j][i] == 0)
					qp[j][i] = cnt;
				if((j+i-cnt) <= n && qp[j][(j+i-cnt)] == 0)
					qp[j][(j+i-cnt)] = cnt;
				if(temp >= 1 && qp[j][temp] == 0)
					qp[j][temp] = cnt;
				temp --;
			}
			rec[cnt] = i;
			DFS(cnt+1);
			temp = i;
			for(int j = cnt;j <= n;j ++){
				for(int q = 1;q <= n;q ++)
					if(qp[j][q] == cnt)
						qp[j][q] = 0;
			}
		}
	}
}

int main(){
	cin >> n;
	DFS(1);
	cout << ans;
	return 0;
}
