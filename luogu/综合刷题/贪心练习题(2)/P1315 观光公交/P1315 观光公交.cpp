#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m,k,i,maxn,tot=0,p;
int Clock[1005];//�����i�������ʱ��
int last[1005];//��ʼ��Ϊi�ĳ˿�������i�����ʱ��
int d[1005];//��������֮�����õ�ʱ��
int range[1005];//��iվʹ�ü��������ܼ��ٵ���Զ����ı��
int leave[1005];//��һ�����㵽��i������֮��ÿ�������³��������ܺ�
int t[10005],a[10005],b[10005];//��iλ�˿��������������ʱ�̣������ľ����ţ�����ľ�����

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(i = 1; i <= n-1; i ++)
		cin >> d[i];
	for(i = 1; i <= m; i ++) {
		cin >> t[i] >> a[i] >> b[i];
		last[a[i]] = max(last[a[i]],t[i]);//�ҳ���ʼ��Ϊi�ĳ˿�������i�����ʱ��
		leave[b[i]] ++;//������ڱ������³�������
	}
	for(i = 2; i <= n; i ++) {
		leave[i] += leave[i-1];//�������һ�����㵽��i������֮��ÿ�������³��������ܺ�
		Clock[i] = max(Clock[i-1],last[i-1])+d[i-1];//�����ÿһ������ĵ���ʱ��
	}
	for(i = 1; i <= m; i ++)
		tot += Clock[b[i]]-t[i];//�������ʹ�ü�����֮ǰ�������˵�ʱ���ܺ�
	while(k != 0) {
		k --;
		range[n-1] = n;
		for(i = n-2; i >= 1; i --) {
			if(Clock[i+1] <= last[i+1])//�����һ���������������ʱ��С�ڵ�����һ���������һ���˵����ʱ��
				range[i] = i+1;//������ֻ��i+1�³�������Ч
			else
				range[i] = range[i+1];//������������Ч
		}
		maxn = -1;
		for(i = 1; i <= n; i ++) {
			if(leave[range[i]]-leave[i] > maxn&&d[i]!=0) {
				maxn = leave[range[i]]-leave[i];//�ҳ�����һ������ʹ�ü������ܹ����ٵ�ʱ�䣨�ܹ����������ˣ�
				p = i;//��¼�þ���
			}

		}
		if(maxn == -1)//��������Ч���˳�ѭ��
			break;
		tot -= maxn;//��ȥ�ܹ����ٵ���ʱ��
		d[p] --;
		for(i = p; i <= n; i ++)
			Clock[i] = max(Clock[i-1],last[i-1])+d[i-1];//���¼��㵽��ÿһվ��ʱ��
	}
	cout << tot;
	return 0;
}

