#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

struct node {
	int rank;
	int sum;
}def[10];

int a[10][10],hang[10][10],lie[10][10],gong[10][10],s[100][4];
int u,ok,most = -1,have;

bool cmp(node a,node b) {
	return a.sum < b.sum;
}

void dfs(int p,int score) {
	if(p == u) {
		if(score > most)  
			most = score;
		return;
	}
	for(ri i = 1;i <= 9;i ++) {
		if(!hang[s[p][0]][i]&&!lie[s[p][1]][i]&&!gong[s[p][3]][i]) { 
			hang[s[p][0]][i] = lie[s[p][1]][i] = gong[s[p][3]][i] = 1;
			dfs(p+1,score+(s[p][2]*i));
			hang[s[p][0]][i] = lie[s[p][1]][i] = gong[s[p][3]][i] = 0;
		}
	}
	return;
}

int which(int i,int j) {
	if(i <= 3) {
		if(j <= 3)        
			return 1;
		else if(j <= 6)   
			return 2;
		else
			return 3;
	} 
	else if(i <= 6){
		if(j <= 3)    
		    return 4;
		else if(j<=6)   
			 return 5;
		else        
		    return 6;
	} 
	else {
		if(j <= 3)       
			return 7;
		else if(j <= 6)  
			return 8;
		else          
			return 9;
	}
}

int point(int i,int j) {
	if(i == 1 || j == 1 || i == 9 || j == 9)
		return 6;
	if(i == 2 || j == 2 || i == 8 || j == 8)
		return 7;
	if(i == 3 || j == 3 || i == 7 || j == 7)
		return 8;
	if(i == 4 || j == 4 || i == 6 || j == 6)
		return 9;
	return 10;
}

int main() {
	for(ri i = 1;i <= 9;i ++)
		def[i].rank = i; 
	for(ri i = 1;i <= 9;i ++)
		for(ri j = 1;j <= 9;j ++) {
			cin >> a[i][j];
			if(a[i][j] > 0)
				hang[i][a[i][j]] = lie[j][a[i][j]]=gong[which(i,j)][a[i][j]]=1,have+=a[i][j]*point(i,j);
			else  
				def[i].sum++;
		}
	sort(def+1,def+10,cmp);
	for(ri i = 1;i <= 9;i ++) {
		for(ri j = 1;j <= 9;j ++)
			if(a[def[i].rank][j] == 0)
				s[u][0] = def[i].rank,s[u][1]=j,s[u][2]=point(def[i].rank,j),s[u++][3]=which(def[i].rank,j);
	}
	dfs(0,have);
	cout << most << endl;
	return 0;
}
