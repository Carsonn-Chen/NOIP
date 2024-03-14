#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m,k,i,maxn,tot=0,p;
int Clock[1005];//到达第i个景点的时间
int last[1005];//起始点为i的乘客最晚到达i景点的时间
int d[1005];//两个景点之间所用的时间
int range[1005];//在i站使用加速器所能加速的最远景点的编号
int leave[1005];//第一个景点到第i个景点之间每个景点下车人数的总和
int t[10005],a[10005],b[10005];//第i位乘客来到出发景点的时刻；出发的景点编号；到达的景点编号

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(i = 1; i <= n-1; i ++)
		cin >> d[i];
	for(i = 1; i <= m; i ++) {
		cin >> t[i] >> a[i] >> b[i];
		last[a[i]] = max(last[a[i]],t[i]);//找出起始点为i的乘客最晚到达i景点的时间
		leave[b[i]] ++;//计算出在本景点下车的人数
	}
	for(i = 2; i <= n; i ++) {
		leave[i] += leave[i-1];//计算出第一个景点到第i个景点之间每个景点下车人数的总和
		Clock[i] = max(Clock[i-1],last[i-1])+d[i-1];//计算出每一个景点的到达时间
	}
	for(i = 1; i <= m; i ++)
		tot += Clock[b[i]]-t[i];//计算出不使用加速器之前的所有人的时间总和
	while(k != 0) {
		k --;
		range[n-1] = n;
		for(i = n-2; i >= 1; i --) {
			if(Clock[i+1] <= last[i+1])//如果下一个景点汽车到达的时间小于等于下一个景点最后一个人到达的时间
				range[i] = i+1;//加速器只在i+1下车的人有效
			else
				range[i] = range[i+1];//加速器连续有效
		}
		maxn = -1;
		for(i = 1; i <= n; i ++) {
			if(leave[range[i]]-leave[i] > maxn&&d[i]!=0) {
				maxn = leave[range[i]]-leave[i];//找出在哪一个景点使用加速器能够加速的时间（能够加速最多的人）
				p = i;//记录该景点
			}

		}
		if(maxn == -1)//加速器无效，退出循环
			break;
		tot -= maxn;//减去能够加速的总时间
		d[p] --;
		for(i = p; i <= n; i ++)
			Clock[i] = max(Clock[i-1],last[i-1])+d[i-1];//重新计算到达每一站的时间
	}
	cout << tot;
	return 0;
}

