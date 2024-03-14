#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define ri register int

using namespace std;

inline int read() {
	char c = getchar();
	int num = 0;
	for(; !isdigit(c); c=getchar());
	for(; isdigit(c); c=getchar())
		num = num*10+c-'0';
	return num;
}

priority_queue<int,vector<int> > q1;
priority_queue<int,vector<int>,greater<int> > q2;

int main() {
	int n = read();
	q1.push(read());
	cout << q1.top() << endl;
	for (ri i = 2; i <= n; i ++) {
		int a = read();
		if (a > q1.top())
			q2.push(a);
		else
			q1.push(a);
		while(abs((int)q1.size() - (int)q2.size()) > 1)
			if(q1.size() > q2.size()) {
				q2.push(q1.top());
				q1.pop();
			} else {
				q1.push(q2.top());
				q2.pop();
			}
		if (i%2) 
			cout << (q1.size() > q2.size()?q1.top():q2.top()) << endl;
	}
	return 0;
}
