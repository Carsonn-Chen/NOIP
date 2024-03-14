#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define MAXN 1000010

using namespace std;

int next[MAXN];
int la,lb,j;
char a[MAXN],b[MAXN];

int main() {
	cin>> a+1 >>b+1;
	la = strlen(a+1);
	lb = strlen(b+1);
	for(ri i = 2; i <= lb;i ++) {
		while(j&&b[i] != b[j+1])
			j = next[j];
		if(b[j+1] == b[i])
			j++;
		next[i] = j;
	}
	j = 0;
	for(ri i = 1; i <= la; i ++) {
		while(j > 0 && b[j+1] != a[i])
			j = next[j];
		if (b[j+1] == a[i])
			j ++;
		if (j == lb) {
			cout << i-lb+1 << endl;
			j = next[j];
		}
	}
	for(ri i = 1;i <= lb;i ++)
		cout << next[i] << " ";
	return 0;
}
