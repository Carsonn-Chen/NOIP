#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

struct node{
	int next,to,w;
}edge[100005];
int head[105],cnt;

void add(int u,int v,int w){
	edge[++cnt].next = head[u];
	edge[cnt].to = v;
	edge[cnt].w = w;
	head[u] = cnt;
}


struct info{
	long long val;
	int ui;
}sjy[105];

int n,p;
int in[105],out[105];


int main(){
	ios::sync_with_stdio(false);
	cin >> n >> p;
	for(ri i = 1;i <= n;i ++)
		cin >> sjy[i].val >> sjy[i].ui;
	for(ri i = 1;i <= p;i ++){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
		in[b] ++;
		out[a] ++;
	}
	queue<int>q;
	for(int i = 1;i <= n;i ++)
		if(!in[i])
			q.push(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(sjy[u].val <= 0)
			continue;
		for(ri i = head[u];i;i = edge[i].next){
			int v = edge[i].to;
			sjy[v].val += sjy[u].val*edge[i].w;
			in[v]--;
			if(in[v] == 0){
				q.push(v);
				sjy[v].val -= sjy[v].ui;
			}
		}
	}
	bool tag = 0;
    for(ri i = 1;i <= n;i ++)
        if(out[i] == 0)
            if(sjy[i].val > 0){
                tag = 1;
                break;
            }
    if(tag){
        for(ri i = 1;i <= n;i ++)
            if(out[i] == 0 && sjy[i].val > 0)
                cout << i << " " << sjy[i].val << endl;
    }
    else{
        printf("NULL");
    }
	return 0;
}
