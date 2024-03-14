#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
#define ri register int

using namespace std;

int main(){
	int m,n,p;
	cin >> m >> n >> p;
	string s[25];
	for(ri i = 1;i <= m;i ++)
		cin >> s[i];
	srand(time(NULL));
	cout << s[rand() % m + 1] << endl;
	return 0;
}
