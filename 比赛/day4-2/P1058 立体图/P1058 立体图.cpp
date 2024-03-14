#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int m,n,a[1001][1001],maxx,maxy;
int z[6]= {2,1,0,0,0,0},s[6]= {6,6,6,6,5,4};

char c[1001][1001],c1[10][10] ={
	"  +---+",
	" /   /|",
	"+---+ |",
	"|   | +",
	"|   |/",
	"+---+",
};

void fg(int x,int y) {
	for(ri i = 5;i >= 0;i --)
		for(ri j = z[i];j <= s[i];j ++){
			c[5-i+x][j+y] = c1[i][j];
			if(5-i+x > maxx)
				maxx = 5-i+x;
			if(j+y > maxy)
				maxy = j+y;
		}
}

int main() {
	scanf("%d%d",&n,&m);
	for(ri i = 1;i <= n;i ++)
		for(ri j = 0;j < m;j ++)
			scanf("%d",&a[i][j]);
	for(ri i = 1;i <= n;i ++)
		for(ri k = 0;k < m;k ++)
			for(ri l = 0;l < a[i][k];l ++)
				fg((n-i)*2+1+3*l,(n-i)*2+1+4*k);
	for(ri i = maxx;i >= 1;i --) {
		for(ri j = 1;j <= maxy;j ++)
			if(c[i][j] == '\000')
				printf(".");
			else 
				printf("%c",c[i][j]);
		printf("\n");
	}
}
