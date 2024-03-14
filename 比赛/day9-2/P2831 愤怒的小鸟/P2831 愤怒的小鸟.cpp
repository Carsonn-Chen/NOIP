#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <ctime>
#define ri register int
#define eps 1e-9

using namespace std;

int n,m;
struct node{
	double x;
	double y;
}p[20];
bool vis[20];

inline bool check(double a,double b){
	return fabs(a-b) < eps;
}

int main(){
	srand(time(NULL));
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T --){
		cin >> n >> m;
		int ans = n;
		for(ri i = 1;i <= n;i ++)
			cin >> p[i].x >> p[i].y;
		int t = 105;
	    while(t --) {
	        int tot = 0;
	        memset(vis,0,sizeof(vis));
	        random_shuffle(p+1,p+n+1);
	        for(ri i = 1;i <= n;i ++)
				if(!vis[i]) {
	                vis[i] = 1;
	                for(ri j = i+1;j <= n;j ++)
						if(!vis[j]) {
	                        if(check(p[i].x,p[j].x))
								continue;
	                        double b = (p[i].y-p[j].y*(p[i].x*p[i].x)/(p[j].x*p[j].x))/(p[i].x-(p[i].x*p[i].x)/p[j].x);
	                        double a = (p[i].y-p[i].x*b)/(p[i].x*p[i].x);
	                        if(a >= 0)
								continue;
	                        vis[j] = 1;
	                        for(ri k = j+1;k <= n;k ++)
	                            if(check(a*p[k].x*p[k].x+b*p[k].x,p[k].y))
									vis[k] = 1;
	                        break;
	                    }
	                tot ++;
	            }
	        ans = min(ans,tot);
	        if(ans == 1)
				break;
	    }
	    cout << ans << endl;
	}
	return 0;
}
