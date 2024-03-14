#include <bits/stdc++.h>

using namespace std;

int main(){
	char hx[10],xz[10];
	scanf("%s%s",hx,xz);
	int numhx = 1,numxz = 1;
	for(int i = 0;i < strlen(hx);i ++)
		numhx *= (hx[i]-'A'+1);
	for(int i = 0;i < strlen(xz);i ++)
		numxz *= (xz[i]-'A'+1);
	numhx = numhx % 47;
	numxz = numxz % 47;
	if(numhx == numxz)
		printf("GO");
	else
		printf("STAY");
	return 0;
}
