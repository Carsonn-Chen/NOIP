/*�ڵ��������в���Ԫ�أ�����������ж����ͬ��Ԫ�أ�
  ��������һ��Ԫ�ص��±꼴�ɡ�,�����ʺ����ظ�Ԫ�أ�
  ������Ȼ���ظ�Ԫ�أ������ز��޶����½磬�����⡣ 
*/ 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const double PI= acos(-1.0);

int a[1000005],n,k;

int Erfen(){
   int L = 0; // �����������˵�
   int R = n - 1; // ����������Ҷ˵�
   while( L <= R) { // ����������䲻Ϊ�վͼ�������
      int mid = L+(R-L>>1); // ȡ������������Ԫ�ص��±�
      if( k == a[mid] ) return mid;
      if( k > a[mid]) L = mid + 1; // �����µĲ����������˵�
        else R = mid - 1; // �����µĲ���������Ҷ˵�
   }
   return -1;
}   // ���Ӷ�O(log(n))

int main(){
	freopen("solve.in","r",stdin);
    freopen("solve.out","w",stdout);    
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i]; 
    cout<<Erfen()<<endl;   
return 0;
}


