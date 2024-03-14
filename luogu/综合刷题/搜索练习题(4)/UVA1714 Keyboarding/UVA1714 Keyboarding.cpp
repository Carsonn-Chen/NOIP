#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#define ri register int

using namespace std;

struct node{
	int x,y;
	int k,cnt;				//k表示选第几个字符，cnt表示进行了几次操作 
};

map<char,int>M;
int r,c;
int Key[55][55];
int target[10005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int Next[55][55][4][2];
int ans;
int Max[55][55];
queue<node>q;

int main(){
	//freopen("in.in","r",stdin);
	for(ri i = 1;i <= 10;i ++) 
		M[('0'+i-1)] = i;
    for(ri i = 0;i <= 25;i ++) 
		M[('A'+i)] = (i+11);
    M['-']=37; 
	M['*']=38;							//代表换行的字符
	
	while(scanf("%d",&r) != EOF){
		memset(Next,0,sizeof(Next));
        memset(Key,0,sizeof(Key));
        memset(target,0,sizeof(target));
        memset(Max,-1,sizeof(Max));
        while(!q.empty())
        	q.pop();
        
        scanf("%d",&c);
		ans = 0;
		string e;
		for(ri i = 1;i <= r;i ++){
			cin >> e;
			for(ri j = 0;j < c;j ++)
				Key[i][j+1] = M[e[j]];
		}
		cin >> e;
		int len = e.size();
		for(ri i = 0;i < len;i ++)
			target[i] = M[e[i]];
		target[len] = M['*'];
		
		for(ri i = 1;i <= r;i ++)
	        for(ri j = 1;j <= c;j ++)
	            for(ri k = 0 ;k < 4;k ++){
	                int x = i+dx[k],y = j+dy[k];
	                while(Key[i][j] == Key[x][y]) 
						x += dx[k],y += dy[k];
	                Next[i][j][k][0] = x; 
					Next[i][j][k][1] = y;
	            }
	         
	    q.push((node){1,1,0,0});
	    while(!q.empty()){
	        node u = q.front();
			q.pop();
	        if(Key[u.x][u.y] == target[u.k]){
	            if(u.k == len){
	                ans = u.cnt + 1;
	                break;
	            }
		        u.k += 1;
				u.cnt += 1;
		        Max[u.x][u.y] = u.k;
		        q.push(u);
	        }else{
	            for(ri i = 0;i < 4;i ++){
	                int x = Next[u.x][u.y][i][0],y = Next[u.x][u.y][i][1];
	                if(x < 1 || x > r || y < 1 || y > c) 
						continue;
                	if(Max[x][y] >= u.k) 
						continue;
		                Max[x][y] = u.k;
		                q.push((node){x,y,u.k,u.cnt+1});
	            }
	        }
	    }
	    
	    printf("%d\n",ans);
	}
	return 0;
}
