#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

int A[15],B[15],M,N,HP;

int main() {
	freopen("ending.in","r",stdin);
	freopen("ending.out","w",stdout);
	cin >> M >> N >> HP;
	for(int i = 1;i <= M;i ++) cin >> B[i];
	for(int i = 1;i <= N;i ++) cin >> A[i];
	bool k = 0;
	sort(A+1,A+N+1);
	do {
		int x = 0,cur = 1,i;
		for(i = 1;i <= N;i ++) if(cur <= M){
			if(x < B[cur]) x += A[i];
			else x = A[i],cur ++;
		}
		x = 0;
		if(cur > M) {for(i --;i <= N;i ++) {
			x += A[i];
		}
		if(x >= HP) {k = 1;break;}
		}
	}while(next_permutation(A+1,A+N+1));
	if(k) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
