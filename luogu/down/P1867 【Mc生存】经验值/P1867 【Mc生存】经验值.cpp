#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int 

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int jy = 0;										//���� 
	double kx;										//��Ѫ	 
	int jjy;										//�ӵľ��� 
	double sm = 10;									//���� 
	for(ri i = 1;i <= n;i ++){
		cin >> kx >> jjy;
		if(sm - kx <= 0)
			break;
		sm -= kx;
		if(sm > 10)
			sm = 10;
		jy += jjy;
	}
	int dj = 0;										//�ȼ�
	jjy = 1;
	while(jy >= jjy){
		dj ++;
		jy -= jjy;
		jjy *= 2;
	}
	cout << dj << " " << jy;
}
