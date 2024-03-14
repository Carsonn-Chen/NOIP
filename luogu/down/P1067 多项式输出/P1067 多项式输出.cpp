#include <bits/stdc++.h>

using namespace std;

int main(){
	//freopen("out.out","w",stdout);
	int n;
	cin >> n;
	string s;
	bool first = 0;
	n += 1;
	while(n--){
		cin >> s;
		if(n != 0){
			if(s[0] != '-'){
				if(s != "0"){
					if(first)
						printf("+");
					if(s == "1"){
						if(n != 1)
							cout << "x" << "^" << n ;
						else
							cout << "x" ;
					}	
					else{
						if(n != 1)
							cout << s << "x" << "^" << n ;
						else
							cout << s << "x";
					}
					first = 1;
				}
			}
			else{
				if(s != "0"){
					if(s[1] == '1' && !s[2]){
						if(n != 1)
							cout << "-" << "x" << "^" << n ;
						else
							cout << "-" << "x";
					}
					else{
						if(n != 1)
							cout << s << "x" << "^" << n ;
						else
							cout << s << "x";
					}
					first = 1;
				}
			}
		}
		else if(n == 0){
			if(s != "0"){
				if(s[0] != '-'){
					printf("+");
					cout << s;	
				}
				else
					cout << s;
			}	
		}
	}
	return 0;
}
