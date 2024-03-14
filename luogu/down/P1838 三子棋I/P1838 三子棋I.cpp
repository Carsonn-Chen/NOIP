#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#define ri register int 

using namespace std;

int num[5][5];

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(ri i = 0;i < s.size();i ++){
		int x,y;
		x = (s[i] - '0' - 1)/3 + 1;
		y = (s[i] - '0') % 3;
		if(y == 0)
		 y = 3;
		if((i+1) % 2 == 1)
			num[x][y] = 1;
		else
			num[x][y] = 2;
	}
	
	/*for(ri i = 1;i <= 3;i ++){
		for(ri j = 1;j <= 3;j ++)
			cout << num[i][j] << " ";
		cout << endl;
	}*/
	
	if(num[1][1] == 1 && num[1][2] == 1 && num[1][3] == 1)cout << "xiaoa wins.";
	else if(num[2][1] == 1 && num[2][2] == 1 && num[2][3] == 1)cout << "xiaoa wins.";
	else if(num[3][1] == 1 && num[3][2] == 1 && num[3][3] == 1)cout << "xiaoa wins.";
	else if(num[1][1] == 1 && num[2][1] == 1 && num[3][1] == 1)cout << "xiaoa wins.";
	else if(num[1][2] == 1 && num[2][2] == 1 && num[3][2] == 1)cout << "xiaoa wins.";
	else if(num[1][3] == 1 && num[2][3] == 1 && num[3][3] == 1)cout << "xiaoa wins.";
	else if(num[1][1] == 1 && num[2][2] == 1 && num[3][3] == 1)cout << "xiaoa wins.";
	else if(num[1][3] == 1 && num[2][2] == 1 && num[3][1] == 1)cout << "xiaoa wins.";
	
	else if(num[1][1] == 2 && num[1][2] == 2 && num[1][3] == 2)cout << "uim wins.";
	else if(num[2][1] == 2 && num[2][2] == 2 && num[2][3] == 2)cout << "uim wins.";
	else if(num[3][1] == 2 && num[3][2] == 2 && num[3][3] == 2)cout << "uim wins.";
	else if(num[1][1] == 2 && num[2][1] == 2 && num[3][1] == 2)cout << "uim wins.";
	else if(num[1][2] == 2 && num[2][2] == 2 && num[3][2] == 2)cout << "uim wins.";
	else if(num[1][3] == 2 && num[2][3] == 2 && num[3][3] == 2)cout << "uim wins.";
	else if(num[1][1] == 2 && num[2][2] == 2 && num[3][3] == 2)cout << "uim wins.";
	else if(num[1][3] == 2 && num[2][2] == 2 && num[3][1] == 2)cout << "uim wins.";
	else cout << "drew.";
	return 0;
}
