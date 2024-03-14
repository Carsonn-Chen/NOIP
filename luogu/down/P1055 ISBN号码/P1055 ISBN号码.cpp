#include <bits/stdc++.h>

using namespace std;

int main(){
	char s[15];
	scanf("%s",s);
	int ans;
	ans = 1*(s[0]-48) + 2*(s[2]-48) + 3*(s[3]-48) + 4*(s[4]-48) + 5*(s[6]-48) + 6*(s[7]-48) + 7*(s[8]-48) + 8*(s[9]-48) + 9*(s[10]-48);
	ans = ans % 11;
	char e;
	if(ans == 10)
		e = 'X';
	else
		e = ans+48;
	if(e == s[12])
		printf("Right");
	else{
		s[12] = e;
		printf("%s",s);
	}
	return 0;
}
