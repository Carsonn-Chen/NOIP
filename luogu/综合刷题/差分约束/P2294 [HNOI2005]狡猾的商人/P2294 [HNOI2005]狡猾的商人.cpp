#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int w,n,m;
int dis[101][101];

int main() {
	cin >> w;
	while(w --){
		memset(dis,0,sizeof(dis));
		cin >> n >> m;
		int s,t,v;
		for(ri j = 1;j <= m;j ++) {
			cin >> s >> t >> v;
			dis[s][t] = v;
		}
		int tag=1;
		for(ri j = 2;j <= n && tag;j ++)
			for(ri k = j-1;k >= 1 && tag;k --)
				for(ri l = k;l < j && tag;l ++)
					if(dis[k][l] && dis[l+1][j]){
						if(dis[k][j]){
							if(dis[k][j] != dis[k][l]+dis[l+1][j])
									tag=0;
						}
						else
							dis[k][j] = dis[k][l]+dis[l+1][j];
					}
		if(tag == 0)
			cout<<"false"<<endl;
		if(tag == 1)
			cout<<"true"<<endl;
	}
	return 0;
}
