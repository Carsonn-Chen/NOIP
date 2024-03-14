#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#define ri register int

using namespace std;

struct node{
	int w;
	int l;
}p11[5505],p21[5505];

int main(){
	ios::sync_with_stdio(false);
	string s;
	int c11 = 1,c21 = 1;
	bool tag = 0;
	while(cin >> s){
		int len = s.size();
		for(ri i = 0;i < len;i ++){
			if(s[i] == 'W'){
				p11[c11].w ++;
				p21[c21].w ++;
			}
			else if(s[i] == 'L'){
				p11[c11].l ++;
				p21[c21].l ++;
			}
			else if(s[i] == 'E'){
				tag = 1;
				break;
			}
			if(p11[c11].w >= 11){
				if(p11[c11].w - p11[c11].l >= 2)
					c11 ++;
			}
			if(p11[c11].l >= 11){
				if(p11[c11].l - p11[c11].w >= 2)
					c11 ++;
			}
			
			if(p21[c21].w >= 21){
				if(p21[c21].w - p21[c21].l >= 2)
					c21 ++;
			}
			if(p21[c21].l >= 21){
				if(p21[c21].l - p21[c21].w >= 2)
					c21 ++;
			}
		}
		if(tag)
			break;
	}
	/*if(p11[c11].w < 11 && p11[c11].l < 11)
		c11 --;
	if(p21[c21].w < 21 && p21[c21].l < 21)
		c21 --;*/
	for(ri i = 1;i <= c11;i ++)
		cout << p11[i].w << ":" << p11[i].l << endl;
	cout << endl;
	for(ri i = 1;i <= c21;i ++)
		cout << p21[i].w << ":" << p21[i].l << endl;
	return 0;
}
