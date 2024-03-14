#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e7+5;

struct ss{
	int v;
	int num;
}s1[MAXN],s2[MAXN];

bool cmp1(ss abc,ss bcd){
	return abc.num < bcd.num;
}

int main(){
	int n;
	cin >> n;
	string a;
	int cnts,cntc,cntsall = 0,cntcall = 0;
	int ans = 0;
	int si=0,ci=0;
	for(int j = 0;j < n;j ++){
		cin >> a;
		cnts = cntc = 0;
		for(int i = 0;i < a.size();i ++){
			if(a[i] == '+')
				continue;
			if(a[i] == 's')
				cnts ++;
			else
				cntc ++;
		}
		if(cnts > cntc){
			s1[si++].v = cntc;
			s1[si].num = cnts;
		}
		else{
			s2[ci++].v = cnts;
			s2[ci].num = cntc;
		}
		cntsall += cnts;
		cntcall += cntc;
	}
	if(cntsall == cntcall)
		ans = (cntsall+cntcall)/2;
	else{
		sort(s1,s1+si,cmp1);
		sort(s2,s2+ci,cmp1);
		si = ci = 0;
		while(cntsall != cntcall){
			if(cntsall > cntcall)
				cntsall -= s1[si++].num;
			else
				cntcall -= s2[ci++].num;
		}
		ans = (cntsall+cntcall)/2;
	}
	cout << ans << endl;
}
