#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int X[25000010];
int T[25000010];
int Up[5010],Down[5010];

int main(){
	int a,b,c,d;
	long long x0;
	scanf("%lld%d%d%d%d",&x0,&a,&b,&c,&d);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 0; i < n * m; i++){
		x0 = (a * x0 * x0 + b * x0 + c) % d;
		X[i] = (int)x0;
	}
    for(int i = 0; i < n * m; i++) 
		T[i] = i;
    for(int i = 0; i < n * m; i++) 
		swap(T[i], T[X[i] % (i + 1)]);
    while(q--){
    	int temp1,temp2;
		scanf("%d%d", &temp1, &temp2);
		swap(T[temp1 - 1], T[temp2 - 1]);
	}
    for(int i = 0; i < n * m; i++) 
		X[T[i]] = i;                             
    for(int i = 0; i < m; i++){ 
		Up[i] = 0;
		Down[i] = n - 1;
	}
    for(int i = 0; i < n * m; i++)
        if(Up[X[i] % m] <= X[i] / m && Down[X[i] % m] >= X[i] / m){
            printf("%d ", i + 1);
            for(int j = X[i] % m + 1; j < m; j++) 
				Up[j] = max(Up[j], X[i] / m);
            for(int j = 0; j < X[i] % m; j++)
				Down[j] = min(Down[j], X[i] / m);
        }
    return 0;
}
