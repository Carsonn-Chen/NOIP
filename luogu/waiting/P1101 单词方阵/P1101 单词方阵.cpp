#include <bits/stdc++.h>

using namespace std;

char word[102][102];
int place[102];
string s = " yizhong";
int tag[102][102] = {0};
int fr[9] = {0,1,1,1,0,0,-1,-1,-1};
int fl[9] = {0,0,+1,-1,+1,-1,0,+1,-1};

bool search(int r,int l,int cnt,int dir){					//r,lÈ·¶¨ËÑË÷Î»ÖÃ 
	
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++){
			cin >> word[i][j];
			if(word[i][j] == 'y')
				place[i] = j;
		}
	for(int i = 1;i <= n;i ++)
		if(place[i])
			search();
	for(int i = 1;i <=n ;i ++){
		for(int j = 1;j <= n;j ++){
			if(tag[i][j])
				printf("%c",word[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}
